#include "friendmodel.h"
#include "serverapi.h"
#include "user.h"
#include "scream.h"

FriendModel::FriendModel(ServerAPI *serv, QList<QString> friends, QObject *parent)
    : QAbstractTableModel(parent),
    server(serv)
{

    for(QString id : friends){
        server->loadUserFromServer(id);
        server->loadScreamsFromServer(id);
    }

    connect(server, &ServerAPI::userLoaded, this, [this](QSharedPointer<User> user){
        QString id = user->getUserID();
        pendingUsers[id] = user;

        // check if screams loaded
        if (pendingScreams.contains(id)){
            user->setScreamList(pendingScreams[id]);

            beginInsertRows(QModelIndex(), friendList.size(), friendList.size());
            friendList.append(user);
            endInsertRows();

            pendingUsers.remove(id); pendingScreams.remove(id);
        }
        if (pendingUsers.isEmpty() && pendingScreams.isEmpty()) {
            emit loadingComplete();
        }
    });

    connect(server, &ServerAPI::screamsLoaded, this, [this](QString id, QList<QSharedPointer<Scream>> screams) {
        pendingScreams[id] = screams;

        // check if user already loaded
        if (pendingUsers.contains(id)) {
            QSharedPointer<User> user = pendingUsers[id];
            user->setScreamList(screams);

            beginInsertRows(QModelIndex(), friendList.size(), friendList.size());
            friendList.append(user);
            endInsertRows();

            pendingUsers.remove(id);
            pendingScreams.remove(id);
        }

        if (pendingUsers.isEmpty() && pendingScreams.isEmpty()) {
            emit loadingComplete();
        }
    });


}

void FriendModel::refreshData(const QList<QString>& newFriends) {
    beginResetModel();
    friendList.clear();
    pendingUsers.clear();
    pendingScreams.clear();
    endResetModel();

    // Re-load all
    for (const QString& id : newFriends) {
        server->loadUserFromServer(id);
        server->loadScreamsFromServer(id);
    }
}

QVariant FriendModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role==Qt::DisplayRole && orientation == Qt::Horizontal){
        if (section==0){
            return "Username";
        } else if (section == 1){
            return "Scream num";
        }
    }
    return QVariant();}


int FriendModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return friendList.size();
}

int FriendModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 2; // username, scream num
}

QList<QSharedPointer<User>> FriendModel::getFriends(){
    return friendList;
}

QVariant FriendModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= friendList.size() || index.column() >= 3)
        return QVariant();

    // how to get friend from friendList's id, using getFriendFromServer?
    QSharedPointer<User> user = friendList[index.row()];

    if (role == Qt::DisplayRole) {
        switch (index.column()){
        case 0: return user->getUsername();
        case 1: return user->getScreamList().size();
        default: return QVariant();
        }
    }
    return QVariant();
}

QSharedPointer<User> FriendModel::getUserAt(int row) const {
    if (row >= 0 && row < friendList.size())
        return friendList[row];
    return nullptr;
}

void FriendModel::removeFriendsAt(const QList<int>& rows){
    // remove in reverse to preserve index
    QList<int> sorted = rows;
    std::sort(sorted.begin(), sorted.end(), std::greater<int>());
    for (int row : sorted) {
        if (row >= 0 && row < friendList.size()) {
            beginRemoveRows(QModelIndex(), row, row);
            friendList.removeAt(row);
            endRemoveRows();
        }
    }
}
