#ifndef SERVERAPI_H
#define SERVERAPI_H

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QSharedPointer>
#include "user.h"
#include "mainpage.h"
#include "scream.h"

class ServerAPI : public QObject
{
    Q_OBJECT

public:
    explicit ServerAPI(MainPage* page, QObject* parent = nullptr);

    void login(const QString& userID, const QString& password);
    void loadUserFromServer(const QString& userID);
    void registerUser(QSharedPointer<User> user, QString password);
    void saveUserToServer(QSharedPointer<User> user);
    void addFriend(const QString& myID, const QString& friendUserID);
    void deleteFriend(const QString& friendUserID);
    void checkUserExists(const QString& userID);
    void saveScreamToServer(const QString& userID, QSharedPointer<Scream> scream);
    void loadScreamsFromServer(const QString& userID);

signals:
    void loginSuccess(const QString& userID);
    void loginFailed();
    void userLoaded(QSharedPointer<User> user);
    void userNotLoaded();
    void friendAdded();
    void friendDeleted();
    void screamsLoaded(QString userID, QList<QSharedPointer<Scream>> screamList);
    void userExists(bool exists);

private:
    MainPage *mainPage;
    QNetworkAccessManager* networkManager;
    QString serverUrl = "https://scream-jar-api.onrender.com/";
};

#endif // SERVERAPI_H
