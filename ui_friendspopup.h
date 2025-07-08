/********************************************************************************
** Form generated from reading UI file 'friendspopup.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDSPOPUP_H
#define UI_FRIENDSPOPUP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendsPopup
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *closeButton;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *addButton;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;

    void setupUi(QWidget *FriendsPopup)
    {
        if (FriendsPopup->objectName().isEmpty())
            FriendsPopup->setObjectName("FriendsPopup");
        FriendsPopup->resize(400, 300);
        verticalLayout = new QVBoxLayout(FriendsPopup);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        label = new QLabel(FriendsPopup);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font: 700 16pt \"\353\247\221\354\235\200 \352\263\240\353\224\225\";"));

        horizontalLayout->addWidget(label);

        closeButton = new QPushButton(FriendsPopup);
        closeButton->setObjectName("closeButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMaximumSize(QSize(25, 25));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        closeButton->setIcon(icon);

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        addButton = new QPushButton(FriendsPopup);
        addButton->setObjectName("addButton");

        horizontalLayout_2->addWidget(addButton);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        tableView = new QTableView(FriendsPopup);
        tableView->setObjectName("tableView");
        tableView->setLineWidth(1);
        tableView->setSortingEnabled(true);

        verticalLayout_2->addWidget(tableView);


        verticalLayout->addLayout(verticalLayout_2);


        retranslateUi(FriendsPopup);

        QMetaObject::connectSlotsByName(FriendsPopup);
    } // setupUi

    void retranslateUi(QWidget *FriendsPopup)
    {
        FriendsPopup->setWindowTitle(QCoreApplication::translate("FriendsPopup", "Form", nullptr));
        label->setText(QCoreApplication::translate("FriendsPopup", "Friend List", nullptr));
        closeButton->setText(QString());
        addButton->setText(QCoreApplication::translate("FriendsPopup", "Add Friends", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FriendsPopup: public Ui_FriendsPopup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDSPOPUP_H
