#include "screammodel.h"
#include "scream.h"

ScreamModel::ScreamModel(QObject *parent)
    : QAbstractTableModel(parent)
{}

QVariant ScreamModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role==Qt::DisplayRole && orientation == Qt::Horizontal){
        if (section==0){
            return "Category";
        } else if (section == 1){
            return "Content";
        } else if (section == 2){
            return "Date-time";
        }
    }
    return QVariant();
}

int ScreamModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return screamList.size();
}

int ScreamModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 3; //category, content, time
}

void ScreamModel::setScreams(const QList<QSharedPointer<Scream>>& screams) {
    beginResetModel();
    screamList = screams;
    endResetModel();
}

const QList<QSharedPointer<Scream>>& ScreamModel::getScreams(){
    return screamList;
}


QVariant ScreamModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= screamList.size() || index.column()>=3)
        return QVariant();

    const QSharedPointer<Scream>& scream = screamList[index.row()];

    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case 0: return scream->getCategory();
        case 1: return scream->content;
        case 2: return scream->getDate().toString();
        default: return QVariant();  // Safety return for any unexpected column values
        }
    }
    return QVariant();
}

