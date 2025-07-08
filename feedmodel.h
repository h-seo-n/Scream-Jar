#ifndef FEEDMODEL_H
#define FEEDMODEL_H

#include <QAbstractTableModel>
class User;
class Scream;
class ServerAPI;

class FeedModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit FeedModel(QSharedPointer<User> user, ServerAPI* serv, QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    static QString formatRelativeTime(const QDateTime& past);
    QList<QString> friendIDList; // list of id's
    QMap<QString, QSharedPointer<Scream>> friendScream; // id, last scream
    QMap<QString, QString> friendList; // id, username
    ServerAPI* server;

};

#endif // FEEDMODEL_H
