/********************************************************************************
** Form generated from reading UI file 'signupwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPWIDGET_H
#define UI_SIGNUPWIDGET_H

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

class Ui_SignupWidget
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
    QVBoxLayout *useridBigLayout;
    QHBoxLayout *useridLayout;
    QLabel *useridLabel;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *useridInput;
    QHBoxLayout *horizontalLayout_2;
    QLabel *idcheckLabel;
    QPushButton *idAvailableButton;
    QVBoxLayout *passwordBigLayout;
    QHBoxLayout *passwordLayout;
    QLabel *passwordLabel;
    QSpacerItem *horizontalSpacer_9;
    QLineEdit *passwordInput;
    QHBoxLayout *passwordcheckLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *passwordcheckInput;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout_4;
    QPushButton *continueButton;
    QPushButton *loginButton;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *SignupWidget)
    {
        if (SignupWidget->objectName().isEmpty())
            SignupWidget->setObjectName("SignupWidget");
        SignupWidget->resize(814, 452);
        SignupWidget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QLabel{font: 12pt \"System\";}\n"
"\n"
"QPushButton{\n"
"background-color: rgb(218, 218, 218)\n"
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
        verticalLayout_2 = new QVBoxLayout(SignupWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        RegisterLayout = new QVBoxLayout();
        RegisterLayout->setObjectName("RegisterLayout");
        RegisterLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        label_2 = new QLabel(SignupWidget);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Arial\";"));
        label_2->setWordWrap(true);

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_5 = new QSpacerItem(13, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        inputWidget = new QWidget(SignupWidget);
        inputWidget->setObjectName("inputWidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(inputWidget->sizePolicy().hasHeightForWidth());
        inputWidget->setSizePolicy(sizePolicy1);
        inputWidget->setMinimumSize(QSize(0, 160));
        inputWidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(inputWidget);
        verticalLayout->setSpacing(11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(-1, 0, -1, 0);
        usernameLayout = new QHBoxLayout();
        usernameLayout->setObjectName("usernameLayout");
        usernameLabel = new QLabel(inputWidget);
        usernameLabel->setObjectName("usernameLabel");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(usernameLabel->sizePolicy().hasHeightForWidth());
        usernameLabel->setSizePolicy(sizePolicy2);
        usernameLabel->setMaximumSize(QSize(16777215, 26));
        usernameLabel->setStyleSheet(QString::fromUtf8("font: 700 12pt;"));

        usernameLayout->addWidget(usernameLabel);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        usernameLayout->addItem(horizontalSpacer);

        usernameInput = new QLineEdit(inputWidget);
        usernameInput->setObjectName("usernameInput");
        usernameInput->setMinimumSize(QSize(0, 30));
        usernameInput->setMaximumSize(QSize(16777215, 40));
        usernameInput->setBaseSize(QSize(0, 30));

        usernameLayout->addWidget(usernameInput);


        verticalLayout->addLayout(usernameLayout);

        useridBigLayout = new QVBoxLayout();
        useridBigLayout->setObjectName("useridBigLayout");
        useridBigLayout->setContentsMargins(-1, 0, -1, 0);
        useridLayout = new QHBoxLayout();
        useridLayout->setObjectName("useridLayout");
        useridLabel = new QLabel(inputWidget);
        useridLabel->setObjectName("useridLabel");
        useridLabel->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(useridLabel->sizePolicy().hasHeightForWidth());
        useridLabel->setSizePolicy(sizePolicy3);
        useridLabel->setMaximumSize(QSize(16777215, 26));
        useridLabel->setStyleSheet(QString::fromUtf8("font: 700 12pt;"));

        useridLayout->addWidget(useridLabel);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        useridLayout->addItem(horizontalSpacer_2);

        useridInput = new QLineEdit(inputWidget);
        useridInput->setObjectName("useridInput");
        useridInput->setMinimumSize(QSize(0, 30));
        useridInput->setMaximumSize(QSize(16777215, 40));
        useridInput->setBaseSize(QSize(0, 30));

        useridLayout->addWidget(useridInput);


        useridBigLayout->addLayout(useridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(-1, 0, 0, -1);
        idcheckLabel = new QLabel(inputWidget);
        idcheckLabel->setObjectName("idcheckLabel");

        horizontalLayout_2->addWidget(idcheckLabel, 0, Qt::AlignmentFlag::AlignLeft);

        idAvailableButton = new QPushButton(inputWidget);
        idAvailableButton->setObjectName("idAvailableButton");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(idAvailableButton->sizePolicy().hasHeightForWidth());
        idAvailableButton->setSizePolicy(sizePolicy4);
        idAvailableButton->setMinimumSize(QSize(180, 30));
        idAvailableButton->setBaseSize(QSize(200, 0));
        idAvailableButton->setStyleSheet(QString::fromUtf8("font: 12pt \"System\";\n"
"background-color: rgb(218, 218, 218);\n"
"border-color: rgb(218, 218, 218);\n"
"border: 50px;\n"
""));

        horizontalLayout_2->addWidget(idAvailableButton);


        useridBigLayout->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(useridBigLayout);

        passwordBigLayout = new QVBoxLayout();
        passwordBigLayout->setObjectName("passwordBigLayout");
        passwordBigLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
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
        passwordInput->setMinimumSize(QSize(0, 30));
        passwordInput->setMaximumSize(QSize(16777215, 40));
        passwordInput->setBaseSize(QSize(0, 30));
        passwordInput->setEchoMode(QLineEdit::EchoMode::Password);

        passwordLayout->addWidget(passwordInput);


        passwordBigLayout->addLayout(passwordLayout);

        passwordcheckLayout = new QHBoxLayout();
        passwordcheckLayout->setObjectName("passwordcheckLayout");
        label = new QLabel(inputWidget);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("System")});
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        label->setFont(font);

        passwordcheckLayout->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        passwordcheckLayout->addItem(horizontalSpacer_3);

        passwordcheckInput = new QLineEdit(inputWidget);
        passwordcheckInput->setObjectName("passwordcheckInput");
        passwordcheckInput->setMinimumSize(QSize(0, 30));
        passwordcheckInput->setBaseSize(QSize(0, 30));
        passwordcheckInput->setEchoMode(QLineEdit::EchoMode::Password);

        passwordcheckLayout->addWidget(passwordcheckInput);


        passwordBigLayout->addLayout(passwordcheckLayout);


        verticalLayout->addLayout(passwordBigLayout);


        horizontalLayout->addWidget(inputWidget);

        horizontalSpacer_6 = new QSpacerItem(13, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        RegisterLayout->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        RegisterLayout->addItem(verticalSpacer_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        verticalLayout_4->setContentsMargins(0, -1, -1, -1);
        continueButton = new QPushButton(SignupWidget);
        continueButton->setObjectName("continueButton");
        sizePolicy4.setHeightForWidth(continueButton->sizePolicy().hasHeightForWidth());
        continueButton->setSizePolicy(sizePolicy4);
        continueButton->setMinimumSize(QSize(200, 50));
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

        verticalLayout_4->addWidget(continueButton);

        loginButton = new QPushButton(SignupWidget);
        loginButton->setObjectName("loginButton");
        sizePolicy4.setHeightForWidth(loginButton->sizePolicy().hasHeightForWidth());
        loginButton->setSizePolicy(sizePolicy4);
        loginButton->setMinimumSize(QSize(200, 50));
        loginButton->setFont(font);
        loginButton->setToolTipDuration(5);
        loginButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border: 0px;\n"
"font: 12pt \"System\";\n"
"}"));

        verticalLayout_4->addWidget(loginButton);


        horizontalLayout_5->addLayout(verticalLayout_4);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);


        RegisterLayout->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::MinimumExpanding);

        RegisterLayout->addItem(verticalSpacer);


        verticalLayout_2->addLayout(RegisterLayout);


        retranslateUi(SignupWidget);

        QMetaObject::connectSlotsByName(SignupWidget);
    } // setupUi

    void retranslateUi(QWidget *SignupWidget)
    {
        SignupWidget->setWindowTitle(QCoreApplication::translate("SignupWidget", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("SignupWidget", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:700;\">To start, please input your username, ID,<br/>and password to use!<br/>(your ID must be unique)</span></p></body></html>", nullptr));
        usernameLabel->setText(QCoreApplication::translate("SignupWidget", "Username", nullptr));
        useridLabel->setText(QCoreApplication::translate("SignupWidget", "User ID", nullptr));
        idcheckLabel->setText(QString());
        idAvailableButton->setText(QCoreApplication::translate("SignupWidget", "Duplication Check", nullptr));
        passwordLabel->setText(QCoreApplication::translate("SignupWidget", "Password", nullptr));
        label->setText(QCoreApplication::translate("SignupWidget", "Password Check", nullptr));
        continueButton->setText(QCoreApplication::translate("SignupWidget", "Sign Up", nullptr));
        loginButton->setText(QCoreApplication::translate("SignupWidget", "Go To Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignupWidget: public Ui_SignupWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPWIDGET_H
