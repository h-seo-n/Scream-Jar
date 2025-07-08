/********************************************************************************
** Form generated from reading UI file 'friendaddpopup.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDADDPOPUP_H
#define UI_FRIENDADDPOPUP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_friendAddPopup
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QLabel *label;
    QWidget *searchWidget;
    QVBoxLayout *searchLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *idLabel1;
    QLineEdit *idInput;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *searchButton;
    QSpacerItem *horizontalSpacer_3;
    QWidget *confirmWidget;
    QVBoxLayout *confirmLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *idLabel2;
    QSpacerItem *horizontalSpacer_8;
    QLabel *friendIDLabel;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_9;
    QLabel *friendUsernameLabel;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_7;

    void setupUi(QWidget *friendAddPopup)
    {
        if (friendAddPopup->objectName().isEmpty())
            friendAddPopup->setObjectName("friendAddPopup");
        friendAddPopup->resize(338, 300);
        friendAddPopup->setStyleSheet(QString::fromUtf8("font: 12pt \"System\";"));
        verticalLayout = new QVBoxLayout(friendAddPopup);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(friendAddPopup);
        pushButton->setObjectName("pushButton");
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        pushButton->setIcon(icon);

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        label = new QLabel(friendAddPopup);
        label->setObjectName("label");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("System")});
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        label->setFont(font);

        verticalLayout->addWidget(label, 0, Qt::AlignmentFlag::AlignHCenter);

        searchWidget = new QWidget(friendAddPopup);
        searchWidget->setObjectName("searchWidget");
        searchLayout = new QVBoxLayout(searchWidget);
        searchLayout->setObjectName("searchLayout");
        searchLayout->setContentsMargins(-1, 1, -1, 1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        idLabel1 = new QLabel(searchWidget);
        idLabel1->setObjectName("idLabel1");

        horizontalLayout_2->addWidget(idLabel1);

        idInput = new QLineEdit(searchWidget);
        idInput->setObjectName("idInput");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(idInput->sizePolicy().hasHeightForWidth());
        idInput->setSizePolicy(sizePolicy1);
        idInput->setMinimumSize(QSize(100, 20));

        horizontalLayout_2->addWidget(idInput);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        searchLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_2 = new QSpacerItem(40, 30, QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        searchButton = new QPushButton(searchWidget);
        searchButton->setObjectName("searchButton");

        horizontalLayout_3->addWidget(searchButton);

        horizontalSpacer_3 = new QSpacerItem(40, 30, QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        searchLayout->addLayout(horizontalLayout_3);


        verticalLayout->addWidget(searchWidget);

        confirmWidget = new QWidget(friendAddPopup);
        confirmWidget->setObjectName("confirmWidget");
        confirmLayout = new QVBoxLayout(confirmWidget);
        confirmLayout->setObjectName("confirmLayout");
        confirmLayout->setContentsMargins(-1, 1, -1, -1);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        idLabel2 = new QLabel(confirmWidget);
        idLabel2->setObjectName("idLabel2");
        sizePolicy.setHeightForWidth(idLabel2->sizePolicy().hasHeightForWidth());
        idLabel2->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(idLabel2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);

        friendIDLabel = new QLabel(confirmWidget);
        friendIDLabel->setObjectName("friendIDLabel");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(friendIDLabel->sizePolicy().hasHeightForWidth());
        friendIDLabel->setSizePolicy(sizePolicy2);
        friendIDLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255)"));

        horizontalLayout_5->addWidget(friendIDLabel);


        confirmLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(-1, -1, 10, -1);
        label_2 = new QLabel(confirmWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_6->addWidget(label_2);

        horizontalSpacer_9 = new QSpacerItem(10, 10, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);

        friendUsernameLabel = new QLabel(confirmWidget);
        friendUsernameLabel->setObjectName("friendUsernameLabel");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(friendUsernameLabel->sizePolicy().hasHeightForWidth());
        friendUsernameLabel->setSizePolicy(sizePolicy3);
        friendUsernameLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));

        horizontalLayout_6->addWidget(friendUsernameLabel);


        confirmLayout->addLayout(horizontalLayout_6);

        label_5 = new QLabel(confirmWidget);
        label_5->setObjectName("label_5");

        confirmLayout->addWidget(label_5, 0, Qt::AlignmentFlag::AlignHCenter);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(-1, -1, -1, 0);
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        pushButton_3 = new QPushButton(confirmWidget);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout_4->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(confirmWidget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_4->addWidget(pushButton_2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);


        confirmLayout->addLayout(horizontalLayout_4);


        verticalLayout->addWidget(confirmWidget);


        retranslateUi(friendAddPopup);

        QMetaObject::connectSlotsByName(friendAddPopup);
    } // setupUi

    void retranslateUi(QWidget *friendAddPopup)
    {
        friendAddPopup->setWindowTitle(QCoreApplication::translate("friendAddPopup", "Form", nullptr));
        pushButton->setText(QString());
        label->setText(QCoreApplication::translate("friendAddPopup", "Add Friend", nullptr));
        idLabel1->setText(QCoreApplication::translate("friendAddPopup", "ID", nullptr));
        searchButton->setText(QCoreApplication::translate("friendAddPopup", "Search", nullptr));
        idLabel2->setText(QCoreApplication::translate("friendAddPopup", "ID :", nullptr));
        friendIDLabel->setText(QCoreApplication::translate("friendAddPopup", "Friend ID", nullptr));
        label_2->setText(QCoreApplication::translate("friendAddPopup", "Username :", nullptr));
        friendUsernameLabel->setText(QCoreApplication::translate("friendAddPopup", "Friend Username", nullptr));
        label_5->setText(QCoreApplication::translate("friendAddPopup", "Add this user as a friend?", nullptr));
        pushButton_3->setText(QCoreApplication::translate("friendAddPopup", "Back", nullptr));
        pushButton_2->setText(QCoreApplication::translate("friendAddPopup", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class friendAddPopup: public Ui_friendAddPopup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDADDPOPUP_H
