#include "feedmodel.h"
#include "user.h"
#include "scream.h"
#include "serverapi.h"

FeedModel::FeedModel(QSharedPointer<User> user, ServerAPI *serv, QObject *parent)
    : QAbstractTableModel(parent)
    , server(serv)
{
    friendIDList = user->getFriendList();

    for(QString id : friendIDList){
        server->loadScreamsFromServer(id);
        server->loadUserFromServer(id);
    }

    connect(server, &ServerAPI::screamsLoaded, this, [=](QString id, QList<QSharedPointer<Scream>> screams){
        beginInsertRows(QModelIndex(), friendScream.size(), friendScream.size());
        friendScream[id] = screams.last(); // save last scream
        endInsertRows();
        emit layoutChanged();
    });

    connect(server, &ServerAPI::userLoaded, this, [=](QSharedPointer<User> user){
        friendList[user->getUserID()] = user->getUsername() ;
        emit layoutChanged();
    });
}

QVariant FeedModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role==Qt::DisplayRole && orientation == Qt::Horizontal){
        if (section==0){
            return "Screamer";
        } else if (section == 1){
            return "Category";
        } else if (section == 2) {
            return "Content";
        } else if (section == 3) {
            return "Date-time";
        }
    }
    return QVariant();
}


int FeedModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return friendIDList.size();
}

int FeedModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 4; // screamer, category, content, time
}

QVariant FeedModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= friendIDList.size() || index.column()>=4)
        return QVariant();

    QString id = friendIDList[index.row()];

    // Ensure data exists before accessing
    if (!friendList.contains(id) || !friendScream.contains(id) || friendScream[id].isNull())
        return QVariant(); // data not ready yet

    QString username = friendList[id];
    QSharedPointer<Scream> scream = friendScream[id];

    if (role == Qt::DisplayRole){
        switch(index.column()) {
        case 0 : return username;
        case 1 : return scream->getCategory();
        case 2 : return scream->content;
        case 3 : return formatRelativeTime(scream->getDate());

        default : return QVariant();
        }
    }
    return QVariant();
}

QString FeedModel::formatRelativeTime(const QDateTime& past) {
    QDateTime now = QDateTime::currentDateTimeUtc();
    qint64 seconds = past.secsTo(now);

    if (seconds < 60)
        return "just now";
    else if (seconds < 3600)
        return QString::number(seconds / 60) + " minutes ago";
    else if (seconds < 86400)
        return QString::number(seconds / 3600) + " hours ago";
    else if (seconds < 7 * 86400)
        return QString::number(seconds / 86400) + " days ago";
    else
        return past.date().toString("MMM d, yyyy");
}
