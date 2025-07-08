/********************************************************************************
** Form generated from reading UI file 'feedpopup.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEEDPOPUP_H
#define UI_FEEDPOPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FeedPopup
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableView *tableView;

    void setupUi(QDialog *FeedPopup)
    {
        if (FeedPopup->objectName().isEmpty())
            FeedPopup->setObjectName("FeedPopup");
        FeedPopup->resize(400, 300);
        verticalLayout = new QVBoxLayout(FeedPopup);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(FeedPopup);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("System")});
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);

        verticalLayout->addWidget(label, 0, Qt::AlignmentFlag::AlignHCenter);

        tableView = new QTableView(FeedPopup);
        tableView->setObjectName("tableView");

        verticalLayout->addWidget(tableView);


        retranslateUi(FeedPopup);

        QMetaObject::connectSlotsByName(FeedPopup);
    } // setupUi

    void retranslateUi(QDialog *FeedPopup)
    {
        FeedPopup->setWindowTitle(QCoreApplication::translate("FeedPopup", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("FeedPopup", "Scream Feed", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FeedPopup: public Ui_FeedPopup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEEDPOPUP_H
