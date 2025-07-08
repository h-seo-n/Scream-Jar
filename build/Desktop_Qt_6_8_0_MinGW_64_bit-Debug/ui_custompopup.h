/********************************************************************************
** Form generated from reading UI file 'custompopup.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMPOPUP_H
#define UI_CUSTOMPOPUP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_customPopup
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QLabel *jarLabel;
    QSpacerItem *horizontalSpacer;
    QToolButton *jarToolButton;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *toolButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *backgroundLabel;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *backgroundToolButton;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *toolButton_2;

    void setupUi(QWidget *customPopup)
    {
        if (customPopup->objectName().isEmpty())
            customPopup->setObjectName("customPopup");
        customPopup->resize(400, 159);
        verticalLayout = new QVBoxLayout(customPopup);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        pushButton = new QPushButton(customPopup);
        pushButton->setObjectName("pushButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMaximumSize(QSize(25, 25));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::EditClear));
        pushButton->setIcon(icon);

        horizontalLayout_4->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_4);

        widget_3 = new QWidget(customPopup);
        widget_3->setObjectName("widget_3");
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        jarLabel = new QLabel(widget_3);
        jarLabel->setObjectName("jarLabel");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(jarLabel->sizePolicy().hasHeightForWidth());
        jarLabel->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamilies({QString::fromUtf8("System")});
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        jarLabel->setFont(font);

        horizontalLayout->addWidget(jarLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        jarToolButton = new QToolButton(widget_3);
        jarToolButton->setObjectName("jarToolButton");
        jarToolButton->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/palette.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        jarToolButton->setIcon(icon1);
        jarToolButton->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(jarToolButton);

        horizontalSpacer_3 = new QSpacerItem(5, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        toolButton = new QToolButton(widget_3);
        toolButton->setObjectName("toolButton");
        toolButton->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy2);
        toolButton->setMinimumSize(QSize(30, 30));
        toolButton->setMaximumSize(QSize(30, 30));
        toolButton->setBaseSize(QSize(30, 30));
        toolButton->setIconSize(QSize(30, 30));

        horizontalLayout->addWidget(toolButton);


        verticalLayout->addWidget(widget_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        backgroundLabel = new QLabel(customPopup);
        backgroundLabel->setObjectName("backgroundLabel");
        sizePolicy1.setHeightForWidth(backgroundLabel->sizePolicy().hasHeightForWidth());
        backgroundLabel->setSizePolicy(sizePolicy1);
        backgroundLabel->setFont(font);

        horizontalLayout_2->addWidget(backgroundLabel);

        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        backgroundToolButton = new QToolButton(customPopup);
        backgroundToolButton->setObjectName("backgroundToolButton");
        backgroundToolButton->setIcon(icon1);
        backgroundToolButton->setIconSize(QSize(30, 30));

        horizontalLayout_2->addWidget(backgroundToolButton);

        horizontalSpacer_4 = new QSpacerItem(5, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        toolButton_2 = new QToolButton(customPopup);
        toolButton_2->setObjectName("toolButton_2");
        toolButton_2->setEnabled(false);
        toolButton_2->setMaximumSize(QSize(30, 30));
        toolButton_2->setBaseSize(QSize(30, 30));
        toolButton_2->setIconSize(QSize(30, 30));

        horizontalLayout_2->addWidget(toolButton_2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(customPopup);

        QMetaObject::connectSlotsByName(customPopup);
    } // setupUi

    void retranslateUi(QWidget *customPopup)
    {
        customPopup->setWindowTitle(QCoreApplication::translate("customPopup", "Form", nullptr));
        pushButton->setText(QString());
        jarLabel->setText(QCoreApplication::translate("customPopup", "Jar Color : ", nullptr));
        jarToolButton->setText(QString());
        toolButton->setText(QString());
        backgroundLabel->setText(QCoreApplication::translate("customPopup", "Background Color :", nullptr));
        backgroundToolButton->setText(QString());
        toolButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class customPopup: public Ui_customPopup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMPOPUP_H
