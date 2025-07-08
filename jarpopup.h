#ifndef JARPOPUP_H
#define JARPOPUP_H

#include <QDialog>
#include "screammodel.h"
#include "mainpage.h"
#include <QSortFilterProxyModel>
#include <QDateTime>

class JarSortProxyModel : public QSortFilterProxyModel {
public:
    using QSortFilterProxyModel::QSortFilterProxyModel;
protected:
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const override {
        if (left.column() == 3) {
            QDateTime leftDate = sourceModel()->data(left).toDateTime();
            QDateTime rightDate = sourceModel()->data(right).toDateTime();
            return leftDate < rightDate;
        }
        return QSortFilterProxyModel::lessThan(left, right);
    }
};

namespace Ui {
class jarPopup;
}

class jarPopup : public QDialog
{
    Q_OBJECT

public:
    explicit jarPopup(MainPage* mainPage, QWidget *parent = nullptr);
    ~jarPopup();
    void closePopup();

private:
    Ui::jarPopup *ui;
    ScreamModel* screamModel;


};

#endif // JARPOPUP_H
