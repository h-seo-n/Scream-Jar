#ifndef SCREAMMODEL_H
#define SCREAMMODEL_H

#include <QAbstractTableModel>
#include "scream.h"

class ScreamModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit ScreamModel(QObject *parent = nullptr);

    void setScreams(const QList<QSharedPointer<Scream>>& screams);
    const QList<QSharedPointer<Scream>>& getScreams();
    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    QList<QSharedPointer<Scream>> screamList;
};

#endif // SCREAMMODEL_H
