#include "serverapi.h"
#include "database.h"
#include "mainpage.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrlQuery>
#include <QTimeZone>

ServerAPI::ServerAPI(MainPage* page, QObject* parent)
    : QObject(parent),
    mainPage(page)
{
    networkManager = new QNetworkAccessManager(this);
}

// server interaction

void ServerAPI::login(const QString &userID, const QString &password){
    QUrl url(serverUrl + "/login");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["id"] = userID;
    json["password"] = password;

    QNetworkReply* reply = networkManager->post(request, QJsonDocument(json).toJson());

    connect(reply, &QNetworkReply::finished, this, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            qDebug() << "Login successful.";
            emit loginSuccess(userID);
        } else {
            qWarning() << "Login failed:" << reply->errorString();
            emit loginFailed();
        }
        reply->deleteLater();
    });
}


// load server from user - use it to search for friends
// NOTE : LOADED USER HAS NO SCREAM IN THEM ; NEED TO MANUALLY LOAD SCREAM IN MAIN LOGIC (if needed(i don't think so))
void ServerAPI::loadUserFromServer(const QString &userID) {
    QUrl url(serverUrl + "friend-search");
    QUrlQuery query;
    query.addQueryItem("id", userID);
    url.setQuery(query);

    QNetworkRequest request(url);
    QNetworkReply* reply = networkManager->get(request);

    connect(reply, &QNetworkReply::finished, this, [=](){
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response = reply->readAll();
            QJsonDocument jsonResponse = QJsonDocument::fromJson(response);
            QJsonObject jsonObj = jsonResponse.object();

            // Parse the JSON object
            QString id = jsonObj["id"].toString();
            QString username = jsonObj["username"].toString();
            QString wallColor = jsonObj["wallColor"].toString();
            QString friendListStr = jsonObj["friendList"].toString();

            // create user object
            auto user = QSharedPointer<User>::create();
            user->setUserID(id);
            user->setUsername(username);
            user->setWallColor(QColor(wallColor));
            // load friend list
            QStringList friendList = friendListStr.split(",", Qt::SkipEmptyParts);
            user->setFriendList(friendList);

            // LOADING SCREAMS → DO FROM MAINPAGE BY USING CONNECT MANUALLY!!
            /*
            auto screams = loadScreamsFromServer(userID);
            for(const auto &scream : screams) {
                user->addScream(scream->getCategoryIndex(), scream->content, scream->getDate());
            }
            */

            qDebug() << "loaded user id : " << id;

            emit userLoaded(user);
        } else {
            qWarning() << "Network error:" << reply->errorString();
            emit userNotLoaded();
        }

        reply->deleteLater();
    });
}

// add friend to server, SQLite, and object;
void ServerAPI::addFriend(const QString& myID, const QString& friendUserID) {
    QUrl url(serverUrl + "add-friend");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    // Prepare JSON data to send to POST
    QJsonObject json;
    json["myUserID"] = myID;
    json["friendUserID"] = friendUserID;

    QNetworkReply* reply = networkManager->post(request, QJsonDocument(json).toJson());
    qDebug() << "Trying to add friend:" << myID << "->" << friendUserID;

    connect(reply, &QNetworkReply::finished, this, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response = reply->readAll();
            qDebug() << "Friend added successfully:" << response;

            emit friendAdded();
        } else {
            qWarning() << "Network error while adding frind:" << reply->errorString();
        }
        reply->deleteLater();

    });
}

// delete friend from server, SQLite, and object;
void ServerAPI::deleteFriend(const QString& friendUserID) {
    QUrl url(serverUrl + "delete-friend");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    auto currentUser = mainPage->getCurrentuser();

    // Prepare JSON data to send to POST
    QJsonObject json;
    json["myUserID"] = currentUser->getUserID();
    json["friendUserID"] = friendUserID;

    QNetworkReply* reply = networkManager->sendCustomRequest(request, "DELETE", QJsonDocument(json).toJson());

    connect(reply, &QNetworkReply::finished, this, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response = reply->readAll();
            qDebug() << "Friend deleted successfully:" << response;

            // update local user
            if (currentUser->getFriendList().contains(friendUserID)) {
                currentUser->getFriendList().removeAll(friendUserID);
                saveUser(currentUser);
                qDebug() << "Local database updated after deleting friend!";
            }
            emit friendDeleted();
        } else {
            qWarning() << "Network error while deleting friend:" << reply->errorString();
        }
        reply->deleteLater();
    });

}

void ServerAPI::registerUser(QSharedPointer<User> user, QString password){
    QUrl url(serverUrl + "users");
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["id"] = user->getUserID();
    json["username"] = user->getUsername();
    json["wallColor"] = user->getwallColor().name();
    json["password"] = password;

    QNetworkReply* reply = networkManager->post(request, QJsonDocument(json).toJson());

    connect(reply, &QNetworkReply::finished, this, [=]() {
        if(reply->error() == QNetworkReply::NoError) {
            qDebug() << "User saved to server!";
            // saveUser(*user);
        } else {
            qWarning() << "Network error while saving user:" << reply->errorString();
        }
        reply->deleteLater();
    });
}



void ServerAPI::saveUserToServer(QSharedPointer<User> user) {
    QUrl url(serverUrl + "users/no-password");
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["id"] = user->getUserID();
    json["username"] = user->getUsername();
    json["wallColor"] = user->getwallColor().name();

    QNetworkReply* reply = networkManager->post(request, QJsonDocument(json).toJson());

    connect(reply, &QNetworkReply::finished, this, [=]() {
        if(reply->error() == QNetworkReply::NoError) {
            qDebug() << "User saved to server!";
            // saveUser(*user);
        } else {
            qWarning() << "Network error while saving user:" << reply->errorString();
        }
        reply->deleteLater();
    });
}

void ServerAPI::checkUserExists(const QString &userID) {
    QUrl url(serverUrl + "users/" + userID + "/exists");
    QNetworkRequest request(url);

    QNetworkReply* reply = networkManager->get(request);

    connect(reply, &QNetworkReply::finished, this, [=]() {
        if(reply->error() == QNetworkReply::NoError) {
            QByteArray response = reply->readAll();
            QJsonDocument jsonResponse = QJsonDocument::fromJson(response);
            QJsonObject obj = jsonResponse.object();
            bool exists = obj["exists"].toBool();

            emit(userExists(exists));
            qDebug() << "User exists?: " << exists;
        } else {
            qWarning() << "Network error:" << reply->errorString();
        }
        reply->deleteLater();
    });
}

void ServerAPI::saveScreamToServer(const QString& userID, QSharedPointer<Scream> scream) {
    QUrl url(serverUrl + "screams");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject json;
    json["userID"] = userID;
    json["categoryIndex"] = QString::number(scream->getCategoryIndex());
    json["content"] = scream->content;
    json["screamDate"] = scream->getDate().toString();

    QNetworkReply* reply = networkManager->post(request, QJsonDocument(json).toJson());

    connect(reply, &QNetworkReply::finished, this, [=](){
        if (reply->error() == QNetworkReply::NoError){
            qDebug() << "Scream saved to server";
            // saveScream(userID, *scream);
        } else {
            qWarning() << "Network error while saving scream:" << reply -> errorString();
        }
        reply->deleteLater();
    });
}

void ServerAPI::loadScreamsFromServer(const QString &userID) {
    QUrl url(serverUrl + "screams/" + userID);
    QNetworkRequest request(url);
    QNetworkReply* reply = networkManager->get(request);

    connect(reply, QNetworkReply::finished, this, [=](){
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response = reply->readAll();
            QJsonDocument jsonResponse = QJsonDocument::fromJson(response);
            QJsonArray screamArray = jsonResponse.array();

            QList<QSharedPointer<Scream>> screamList;
            for (const QJsonValue& value : screamArray){
                QJsonObject obj = value.toObject();

                QString dateString = obj["screamdate"].toString();
                QDateTime screamDate = QDateTime::fromString(dateString, "ddd MMM d HH:mm:ss yyyy 'GMT'");
                qDebug() << "Raw screamDate string from JSON:" << dateString;
                qDebug() << "QDateTime:" << screamDate;


                QString content = obj["content"].toString();
                int categoryIndex = obj["categoryIndex"].toInt();
                auto scream  = QSharedPointer<Scream>::create(categoryIndex, content, screamDate);
                screamList.append(scream);
            }

            qDebug() << "loaded screams count:" << screamList.size();
            emit screamsLoaded(userID, screamList);

        } else {
            qWarning() << "Network error while loading screams:" << reply->errorString();
        }
        reply->deleteLater();
    });
}





















