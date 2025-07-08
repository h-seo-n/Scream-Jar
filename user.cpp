#include "user.h"
#include <QDebug>

User::User(QObject *parent)
    : QObject(parent), screamList(QList<QSharedPointer<Scream>>())
{ // constuctor implementation
}


void User::setWallColor(QColor color){
    wallColor = color;
}
void User::setJarColor(QColor color){
    jarColor = color;
}


void User::setUsername(const QString& name){
    username = name;
    qDebug()<<username << "is saved to user info!";
}
void User::setUserID(const QString& ID){
    userID = ID;
}

void User::setFriendList(const QList<QString> &list){
    friendList = list;
}

void User::setScreamList(const QList<QSharedPointer<Scream>> screams){
    screamList = screams;
}

void User::addScream(int categoryIndex, QString scream, QDateTime screamDate){
    screamList.append(QSharedPointer<Scream>::create(categoryIndex, scream, screamDate));
}
