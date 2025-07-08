/********************************************************************************
** Form generated from reading UI file 'mainpage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPAGE_H
#define UI_MAINPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "clickablelabel.h"

QT_BEGIN_NAMESPACE

class Ui_MainPage
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *titleLayout;
    QSpacerItem *verticalSpacer_5;
    QLabel *titleLabel;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *mainLayOut;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *friendLayout;
    QPushButton *friendButton;
    QSpacerItem *verticalSpacer_4;
    QPushButton *feedButton;
    QWidget *jarWidget;
    QVBoxLayout *jarLayout;
    ClickableLabel *jar;
    QGridLayout *gridLayout;
    QPushButton *analysisButton;
    QPushButton *customButton;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *rowLayout;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *categoryComboBox;
    QTextEdit *screamTextEdit;
    QPushButton *enterButton;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *MainPage)
    {
        if (MainPage->objectName().isEmpty())
            MainPage->setObjectName("MainPage");
        MainPage->resize(606, 519);
        MainPage->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 700 12pt \"System\";\n"
"background-color : rgb(230, 230, 230);\n"
"border-width : 0px;\n"
"border-radius: 45px;\n"
"padding: 23px;\n"
"}\n"
"\n"
"\n"
"QComboBox{\n"
"	font: 12pt \"System\";\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color : rgb(215, 215, 215);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color : rgb(180, 180, 180);\n"
"\n"
"}\n"
"\n"
"QLabel{\n"
"font: 700 16pt \"System\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(MainPage);
        verticalLayout->setObjectName("verticalLayout");
        titleLayout = new QVBoxLayout();
        titleLayout->setObjectName("titleLayout");
        verticalSpacer_5 = new QSpacerItem(20, 11, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        titleLayout->addItem(verticalSpacer_5);

        titleLabel = new QLabel(MainPage);
        titleLabel->setObjectName("titleLabel");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(titleLabel->sizePolicy().hasHeightForWidth());
        titleLabel->setSizePolicy(sizePolicy);
        titleLabel->setMinimumSize(QSize(0, 50));
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        titleLayout->addWidget(titleLabel);


        verticalLayout->addLayout(titleLayout);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        mainLayOut = new QHBoxLayout();
        mainLayOut->setObjectName("mainLayOut");
        mainLayOut->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        mainLayOut->addItem(horizontalSpacer_2);

        friendLayout = new QVBoxLayout();
        friendLayout->setSpacing(10);
        friendLayout->setObjectName("friendLayout");
        friendLayout->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        friendButton = new QPushButton(MainPage);
        friendButton->setObjectName("friendButton");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/users.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        friendButton->setIcon(icon);
        friendButton->setIconSize(QSize(50, 50));

        friendLayout->addWidget(friendButton);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        friendLayout->addItem(verticalSpacer_4);

        feedButton = new QPushButton(MainPage);
        feedButton->setObjectName("feedButton");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(feedButton->sizePolicy().hasHeightForWidth());
        feedButton->setSizePolicy(sizePolicy1);
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::FolderOpen));
        feedButton->setIcon(icon1);
        feedButton->setIconSize(QSize(50, 50));

        friendLayout->addWidget(feedButton);


        mainLayOut->addLayout(friendLayout);

        jarWidget = new QWidget(MainPage);
        jarWidget->setObjectName("jarWidget");
        jarWidget->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        jarLayout = new QVBoxLayout(jarWidget);
        jarLayout->setSpacing(7);
        jarLayout->setObjectName("jarLayout");
        jarLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        jar = new ClickableLabel(jarWidget);
        jar->setObjectName("jar");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(jar->sizePolicy().hasHeightForWidth());
        jar->setSizePolicy(sizePolicy2);
        jar->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        jar->setStyleSheet(QString::fromUtf8("image: url(:/images/jar.png);"));
        jar->setTextFormat(Qt::TextFormat::MarkdownText);
        jar->setScaledContents(true);
        jar->setAlignment(Qt::AlignmentFlag::AlignCenter);
        jar->setIndent(-3);

        jarLayout->addWidget(jar);


        mainLayOut->addWidget(jarWidget);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        analysisButton = new QPushButton(MainPage);
        analysisButton->setObjectName("analysisButton");
        sizePolicy1.setHeightForWidth(analysisButton->sizePolicy().hasHeightForWidth());
        analysisButton->setSizePolicy(sizePolicy1);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/chart.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        analysisButton->setIcon(icon2);
        analysisButton->setIconSize(QSize(50, 50));

        gridLayout->addWidget(analysisButton, 2, 0, 1, 1);

        customButton = new QPushButton(MainPage);
        customButton->setObjectName("customButton");
        customButton->setEnabled(true);
        sizePolicy1.setHeightForWidth(customButton->sizePolicy().hasHeightForWidth());
        customButton->setSizePolicy(sizePolicy1);
        customButton->setStyleSheet(QString::fromUtf8(""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/brush.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        customButton->setIcon(icon3);
        customButton->setIconSize(QSize(50, 50));

        gridLayout->addWidget(customButton, 0, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout->addItem(verticalSpacer_6, 1, 0, 1, 1);


        mainLayOut->addLayout(gridLayout);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        mainLayOut->addItem(horizontalSpacer);


        verticalLayout->addLayout(mainLayOut);

        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        rowLayout = new QHBoxLayout();
        rowLayout->setSpacing(20);
        rowLayout->setObjectName("rowLayout");
        rowLayout->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        rowLayout->addItem(horizontalSpacer_3);

        categoryComboBox = new QComboBox(MainPage);
        categoryComboBox->addItem(QString());
        categoryComboBox->addItem(QString());
        categoryComboBox->addItem(QString());
        categoryComboBox->addItem(QString());
        categoryComboBox->addItem(QString());
        categoryComboBox->setObjectName("categoryComboBox");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(categoryComboBox->sizePolicy().hasHeightForWidth());
        categoryComboBox->setSizePolicy(sizePolicy3);
        categoryComboBox->setMinimumSize(QSize(100, 50));
        categoryComboBox->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);

        rowLayout->addWidget(categoryComboBox);

        screamTextEdit = new QTextEdit(MainPage);
        screamTextEdit->setObjectName("screamTextEdit");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(screamTextEdit->sizePolicy().hasHeightForWidth());
        screamTextEdit->setSizePolicy(sizePolicy4);
        screamTextEdit->setMinimumSize(QSize(0, 60));
        screamTextEdit->setMaximumSize(QSize(16777215, 16777215));
        screamTextEdit->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::IBeamCursor)));

        rowLayout->addWidget(screamTextEdit);

        enterButton = new QPushButton(MainPage);
        enterButton->setObjectName("enterButton");
        enterButton->setStyleSheet(QString::fromUtf8("border-radius: 10px;"));

        rowLayout->addWidget(enterButton);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        rowLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(rowLayout);

        verticalSpacer = new QSpacerItem(20, 32, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(MainPage);

        QMetaObject::connectSlotsByName(MainPage);
    } // setupUi

    void retranslateUi(QWidget *MainPage)
    {
        MainPage->setWindowTitle(QCoreApplication::translate("MainPage", "Form", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainPage", "SeoYeon's Scream Jar", nullptr));
        friendButton->setText(QString());
        feedButton->setText(QString());
        jar->setText(QString());
        analysisButton->setText(QString());
        customButton->setText(QString());
        categoryComboBox->setItemText(0, QCoreApplication::translate("MainPage", "Study / School", nullptr));
        categoryComboBox->setItemText(1, QCoreApplication::translate("MainPage", "Work", nullptr));
        categoryComboBox->setItemText(2, QCoreApplication::translate("MainPage", "Relationship", nullptr));
        categoryComboBox->setItemText(3, QCoreApplication::translate("MainPage", "Financial issues", nullptr));
        categoryComboBox->setItemText(4, QCoreApplication::translate("MainPage", "Politics / Society", nullptr));

        enterButton->setText(QCoreApplication::translate("MainPage", "Scream!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainPage: public Ui_MainPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGE_H
