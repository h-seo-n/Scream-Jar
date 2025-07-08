/********************************************************************************
** Form generated from reading UI file 'jarpopup.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JARPOPUP_H
#define UI_JARPOPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_jarPopup
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QTableView *screamTableView;

    void setupUi(QDialog *jarPopup)
    {
        if (jarPopup->objectName().isEmpty())
            jarPopup->setObjectName("jarPopup");
        jarPopup->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(jarPopup);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(jarPopup);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font: 700 16pt \"\353\247\221\354\235\200 \352\263\240\353\224\225\";"));

        verticalLayout_2->addWidget(label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        screamTableView = new QTableView(jarPopup);
        screamTableView->setObjectName("screamTableView");
        screamTableView->setSortingEnabled(true);

        verticalLayout->addWidget(screamTableView);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(jarPopup);

        QMetaObject::connectSlotsByName(jarPopup);
    } // setupUi

    void retranslateUi(QDialog *jarPopup)
    {
        jarPopup->setWindowTitle(QCoreApplication::translate("jarPopup", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("jarPopup", "\343\205\207\343\205\207's List of Screams", nullptr));
    } // retranslateUi

};

namespace Ui {
    class jarPopup: public Ui_jarPopup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JARPOPUP_H
