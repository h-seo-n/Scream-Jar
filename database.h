#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <QVariantMap>
#include <QSharedPointer>
#include <QList>
#include <QPair>
#include "user.h"
#include "scream.h"

//Database initialization
bool initializeDatabase();

//auto-login at start (not used)
QString getSavedCredentials();

//User-related database functions
bool saveUser(QSharedPointer<User> user);
QSharedPointer<User> loadUser(const QString &userID);
bool userExists(const QString &userID);
QString getUsernameByUserID(const QString &userID);


//Scream-related database functions
bool saveScream(const QString &userID, const Scream &scream);
QList<QSharedPointer<Scream>> loadScreams(const QString &userID);

#endif // DATABASE_H
