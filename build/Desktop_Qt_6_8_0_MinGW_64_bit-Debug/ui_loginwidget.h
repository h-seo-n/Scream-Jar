/********************************************************************************
** Form generated from reading UI file 'loginwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *RegisterLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_5;
    QWidget *inputWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *usernameLayout;
    QLabel *usernameLabel;
    QSpacerItem *horizontalSpacer;
    QLineEdit *usernameInput;
    QHBoxLayout *useridLayout;
    QLabel *useridLabel;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *useridInput;
    QHBoxLayout *passwordLayout;
    QLabel *passwordLabel;
    QSpacerItem *horizontalSpacer_9;
    QLineEdit *passwordInput;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout_3;
    QPushButton *continueButton;
    QPushButton *signupButton;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *LoginWidget)
    {
        if (LoginWidget->objectName().isEmpty())
            LoginWidget->setObjectName("LoginWidget");
        LoginWidget->resize(834, 315);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoginWidget->sizePolicy().hasHeightForWidth());
        LoginWidget->setSizePolicy(sizePolicy);
        LoginWidget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QLabel{font: 12pt \"System\";}\n"
""));
        verticalLayout_2 = new QVBoxLayout(LoginWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        RegisterLayout = new QVBoxLayout();
        RegisterLayout->setSpacing(0);
        RegisterLayout->setObjectName("RegisterLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        label_2 = new QLabel(LoginWidget);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Arial\";"));
        label_2->setWordWrap(true);

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        inputWidget = new QWidget(LoginWidget);
        inputWidget->setObjectName("inputWidget");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(inputWidget->sizePolicy().hasHeightForWidth());
        inputWidget->setSizePolicy(sizePolicy2);
        inputWidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(inputWidget);
        verticalLayout->setObjectName("verticalLayout");
        usernameLayout = new QHBoxLayout();
        usernameLayout->setObjectName("usernameLayout");
        usernameLabel = new QLabel(inputWidget);
        usernameLabel->setObjectName("usernameLabel");
        usernameLabel->setStyleSheet(QString::fromUtf8("font: 700 12pt;"));

        usernameLayout->addWidget(usernameLabel);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        usernameLayout->addItem(horizontalSpacer);

        usernameInput = new QLineEdit(inputWidget);
        usernameInput->setObjectName("usernameInput");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(usernameInput->sizePolicy().hasHeightForWidth());
        usernameInput->setSizePolicy(sizePolicy3);
        usernameInput->setMinimumSize(QSize(0, 0));
        usernameInput->setMaximumSize(QSize(16777215, 40));

        usernameLayout->addWidget(usernameInput);


        verticalLayout->addLayout(usernameLayout);

        useridLayout = new QHBoxLayout();
        useridLayout->setObjectName("useridLayout");
        useridLabel = new QLabel(inputWidget);
        useridLabel->setObjectName("useridLabel");
        useridLabel->setStyleSheet(QString::fromUtf8("font: 700 12pt;"));

        useridLayout->addWidget(useridLabel);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        useridLayout->addItem(horizontalSpacer_2);

        useridInput = new QLineEdit(inputWidget);
        useridInput->setObjectName("useridInput");
        sizePolicy3.setHeightForWidth(useridInput->sizePolicy().hasHeightForWidth());
        useridInput->setSizePolicy(sizePolicy3);
        useridInput->setMaximumSize(QSize(16777215, 40));

        useridLayout->addWidget(useridInput);


        verticalLayout->addLayout(useridLayout);

        passwordLayout = new QHBoxLayout();
        passwordLayout->setObjectName("passwordLayout");
        passwordLabel = new QLabel(inputWidget);
        passwordLabel->setObjectName("passwordLabel");
        passwordLabel->setStyleSheet(QString::fromUtf8("font: 700 12pt;"));

        passwordLayout->addWidget(passwordLabel);

        horizontalSpacer_9 = new QSpacerItem(10, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        passwordLayout->addItem(horizontalSpacer_9);

        passwordInput = new QLineEdit(inputWidget);
        passwordInput->setObjectName("passwordInput");
        passwordInput->setEnabled(true);
        sizePolicy3.setHeightForWidth(passwordInput->sizePolicy().hasHeightForWidth());
        passwordInput->setSizePolicy(sizePolicy3);
        passwordInput->setMinimumSize(QSize(0, 0));
        passwordInput->setMaximumSize(QSize(16777215, 40));
        passwordInput->setEchoMode(QLineEdit::EchoMode::Password);

        passwordLayout->addWidget(passwordInput);


        verticalLayout->addLayout(passwordLayout);


        horizontalLayout->addWidget(inputWidget);

        horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        RegisterLayout->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        RegisterLayout->addItem(verticalSpacer_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        verticalLayout_3->setContentsMargins(0, -1, -1, -1);
        continueButton = new QPushButton(LoginWidget);
        continueButton->setObjectName("continueButton");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(continueButton->sizePolicy().hasHeightForWidth());
        continueButton->setSizePolicy(sizePolicy4);
        continueButton->setMinimumSize(QSize(200, 50));
        QFont font;
        font.setFamilies({QString::fromUtf8("System")});
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        continueButton->setFont(font);
        continueButton->setToolTipDuration(5);
        continueButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"background-color: rgb(0, 255, 127);\n"
"font: 12pt \"System\";\n"
"border: 0px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color: rgb(194, 194, 194);\n"
"font: 12pt \"System\";\n"
"border: 0px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"font: 12pt \"System\";\n"
"background-color: rgb(184, 184, 184);\n"
"border: 0px;\n"
"}"));

        verticalLayout_3->addWidget(continueButton);

        signupButton = new QPushButton(LoginWidget);
        signupButton->setObjectName("signupButton");
        sizePolicy4.setHeightForWidth(signupButton->sizePolicy().hasHeightForWidth());
        signupButton->setSizePolicy(sizePolicy4);
        signupButton->setMinimumSize(QSize(200, 50));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("System")});
        font1.setPointSize(12);
        signupButton->setFont(font1);
        signupButton->setToolTipDuration(5);
        signupButton->setStyleSheet(QString::fromUtf8("\n"
"QPushButton{\n"
"background-color: rgba(255, 255, 255, 0)\n"
"font: 12pt \"System\";\n"
"border: 0px;\n"
"}"));

        verticalLayout_3->addWidget(signupButton);


        horizontalLayout_5->addLayout(verticalLayout_3);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);


        RegisterLayout->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        RegisterLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(RegisterLayout);


        retranslateUi(LoginWidget);

        QMetaObject::connectSlotsByName(LoginWidget);
    } // setupUi

    void retranslateUi(QWidget *LoginWidget)
    {
        LoginWidget->setWindowTitle(QCoreApplication::translate("LoginWidget", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWidget", "<html><head/><body><p align=\"center\">Log in to use ScreamJar!</p><p align=\"center\">If this is your first time, please sign up!</p></body></html>", nullptr));
        usernameLabel->setText(QCoreApplication::translate("LoginWidget", "Username", nullptr));
        useridLabel->setText(QCoreApplication::translate("LoginWidget", "User ID", nullptr));
        passwordLabel->setText(QCoreApplication::translate("LoginWidget", "Password", nullptr));
        continueButton->setText(QCoreApplication::translate("LoginWidget", "Login", nullptr));
        signupButton->setText(QCoreApplication::translate("LoginWidget", "Go To Signup", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWidget: public Ui_LoginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
