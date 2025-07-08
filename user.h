#ifndef USER_H
#define USER_H

#include <QObject>
#include <QString>
#include <QColor>
#include <QDateTime>
#include "scream.h"

class User : public QObject{
    Q_OBJECT


public:
    explicit User(QObject *parent = nullptr);
    void setWallColor(QColor color);
    void setJarColor(QColor color);

    void addScream(int categoryIndex, QString content, QDateTime = QDateTime::currentDateTimeUtc());
    void setUsername(const QString& name);
    void setUserID(const QString& ID);
    void setFriendList(const QList<QString>& list);
    void setScreamList(const QList<QSharedPointer<Scream>> screams);
    void addFriend(const QString& ID){ friendList.append(ID); }

    const QColor& getwallColor() const { return wallColor; }
    const QColor& getjarColor() const { return jarColor; }
    const QString& getUsername() const { return username; }
    const QString& getUserID() const { return userID; }
    QList<QSharedPointer<Scream>> const getScreamList(){ return screamList; }
    QList<QString> getFriendList() const { return friendList; }


private:
    QString username;
    QString userID;
    // QString password;
    QList<QSharedPointer<Scream>> screamList;
    QList<QString> friendList; // list of user id

    QColor wallColor;
    QColor jarColor;

};

#endif // USER_H
