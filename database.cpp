#include "database.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

//initialize database, schema
bool initializeDatabase(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("appdata.db");

    if(!db.open()){
        qWarning() << "Database error occured:" <<db.lastError().text();
        return false;
    }

    //create 'users' table
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS users ("
                    "id TEXT PRIMARY KEY, "
                    "username TEXT NOT NULL, "
                    "wallColor TEXT, "
                    "friendList TEXT DEFAULT ''"
                    ")")) {
        qWarning() << "Failed to create users table:" << query.lastError().text();
        return false;
    }

    //create 'screams' table
    if (!query.exec("CREATE TABLE IF NOT EXISTS screams ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "userID TEXT NOT NULL, "
                    "categoryIndex INTEGER, "
                    "content TEXT, "
                    "screamDate TEXT, "
                    "FOREIGN KEY (userID) REFERENCES users(id) ON DELETE CASCADE)")) {
        qWarning() << "Failed to create screams table:" << query.lastError().text();
        return false;
    }


    return true;
}

//auto-login (not used)
QString getSavedCredentials() {
    QSqlQuery query;
    if(!query.exec("SELECT id FROM users LIMIT 1")) {
        qWarning() << "Failed to query users table:" << query.lastError().text();
        return "";
    }

    if (query.next()){
        QString userID = query.value(0).toString();
        return userID;
    }

    return "";
}


//Save User
bool saveUser(QSharedPointer<User> user){
    QSqlQuery query;
    query.prepare("INSERT INTO users (id, username, wallColor, friendList) "
                  "VALUES (:id, :username, :wallColor, :friendList) "
                  "ON CONFLICT(id) DO UPDATE SET "
                  "username = :username, wallColor = :wallColor, friendList =:friendList");
    query.bindValue(":id", user->getUserID());
    query.bindValue(":username", user->getUsername());
    query.bindValue(":wallColor", user->getwallColor().name());
    query.bindValue(":friendList", user->getFriendList().join(","));

    if (!query.exec()) {
        qWarning() << "Failed to save user:" << query.lastError().text();
        return false;
    }
    qDebug() << "Saving user with friends:" << user->getFriendList();

    return true;
}

//Load user
QSharedPointer<User> loadUser(const QString &userID){
    QSqlQuery query;
    query.prepare("SELECT username, wallColor, friendList FROM users WHERE id = :id");
    query.bindValue(":id", userID);
    qDebug() << "Loading user from DB with ID:" << userID;

    if (!query.exec() || !query.next()){
        qWarning() << "Failed to load user or no data found:" << query.lastError().text();
        return nullptr;
    }

    //Create User object
    auto user = QSharedPointer<User>::create();
    user->setUserID(userID);
    user->setUsername(query.value("username").toString());
    user->setWallColor(QColor(query.value("wallColor").toString()));
    // - Load the friend list
    QString friendListStr = query.value("friendList").toString();
    QStringList friendList = friendListStr.split(",", Qt::SkipEmptyParts); //Assuming comma-separated values
    user->setFriendList(friendList);

    // - Load associated screams
    auto screams = loadScreams(userID);
    for(const auto &scream : screams) {
        user->addScream(scream->getCategoryIndex(), scream->content, scream->getDate());
    }
    qDebug() << "Loaded friendList string:" << friendListStr;
    qDebug() << "Parsed friend list:" << friendList;

    return user;
}

//Check if user exists (first time?)
bool userExists(const QString &userID){
    QSqlQuery query;

    //Prepare the SQL query to check if the user exists
    query.prepare("SELECT COUNT(*) FROM users WHERE id = :id");
    query.bindValue(":id", userID);

    if(!query.exec()){
        qWarning() << "Failed to execute query to check user existence:" << query.lastError().text();
        return false; // error - assume user doesn't exist
    }

    //Check the result of query
    if (query.next() && query.value(0).toInt() > 0){
        return true; //User exists
    }
    return false; // user doesn't exist
}

QString getUsernameByUserID(const QString &userID){
    QSqlQuery query;
    query.prepare("SELECT username FROM users WHERE id = :id");
    query.bindValue(":id", userID);

    if (query.exec() && query.next()){
        return query.value(0).toString(); //Return the username
    }

    return {}; //Return empty string
}

//Save Scream
bool saveScream(const QString &userID, const Scream &scream){
    QSqlQuery query;

    query.prepare("INSERT INTO screams (userID, categoryIndex, content, screamDate) "
                  "VALUES (:userID, :categoryIndex, :content, :screamDate)");
    query.bindValue(":userID", userID);
    query.bindValue(":categoryIndex", scream.getCategoryIndex());
    query.bindValue(":content", scream.content);
    query.bindValue(":screamDate", scream.getDate().toString(Qt::ISODate));

    if (!query.exec()) {
        qWarning() << "Failed to save scream:" << query.lastError().text();
        return false;
    }
    return true;
}

//Load Screams
QList<QSharedPointer<Scream>> loadScreams(const QString &userID){
    QSqlQuery query;
    query.prepare("SELECT categoryIndex, content, screamDate FROM screams WHERE userID = :userID");
    query.bindValue(":userID", userID);

    QList<QSharedPointer<Scream>> screamList;

    if (query.exec()){
        while (query.next()){
            int categoryIndex = query.value("categoryIndex").toInt();
            QString content = query.value("content").toString();
            QDateTime screamDate = QDateTime::fromString(query.value("screamDate").toString(), Qt::ISODate);

            auto scream  = QSharedPointer<Scream>::create(categoryIndex, content, screamDate);
            screamList.append(scream);
        }
    } else {
        qWarning() <<"Failed to load screams:" << query.lastError().text();
    }

    return screamList;
}






