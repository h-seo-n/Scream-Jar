#ifndef FRIENDMODEL_H
#define FRIENDMODEL_H

#include <QAbstractTableModel>

class ServerAPI;
class User;
class Scream;

class FriendModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit FriendModel(ServerAPI *serv, QList<QString> friends, QObject *parent = nullptr);

    void refreshData(const QList<QString>& newFriends);
    void setFriends(QList<QString> friends);
    // Header:
    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QList<QSharedPointer<User>> getFriends();
    QSharedPointer<User> getUserAt(int row) const;
    void removeFriendsAt(const QList<int>& rows);


    ServerAPI *server;

private:
    QMap<QString, QSharedPointer<User>> pendingUsers; // id - user
    QMap<QString, QList<QSharedPointer<Scream>>> pendingScreams; // id - screamlist
    QList<QSharedPointer<User>> friendList;

signals:
    void loadingComplete();
};

#endif // FRIENDMODEL_H
