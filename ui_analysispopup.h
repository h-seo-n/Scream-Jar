/********************************************************************************
** Form generated from reading UI file 'analysispopup.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANALYSISPOPUP_H
#define UI_ANALYSISPOPUP_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AnalysisPopup
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QSpacerItem *verticalSpacer;
    QLabel *categoryLabel;
    QSpacerItem *verticalSpacer_2;
    QCalendarWidget *calendarWidget;

    void setupUi(QDialog *AnalysisPopup)
    {
        if (AnalysisPopup->objectName().isEmpty())
            AnalysisPopup->setObjectName("AnalysisPopup");
        AnalysisPopup->resize(553, 469);
        verticalLayout_2 = new QVBoxLayout(AnalysisPopup);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        titleLabel = new QLabel(AnalysisPopup);
        titleLabel->setObjectName("titleLabel");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(titleLabel->sizePolicy().hasHeightForWidth());
        titleLabel->setSizePolicy(sizePolicy);
        titleLabel->setMinimumSize(QSize(0, 40));
        titleLabel->setStyleSheet(QString::fromUtf8("font: 700 18pt \"System\";"));

        verticalLayout->addWidget(titleLabel);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        categoryLabel = new QLabel(AnalysisPopup);
        categoryLabel->setObjectName("categoryLabel");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(categoryLabel->sizePolicy().hasHeightForWidth());
        categoryLabel->setSizePolicy(sizePolicy1);
        categoryLabel->setMinimumSize(QSize(0, 50));
        categoryLabel->setStyleSheet(QString::fromUtf8("font: 12pt \"System\";"));
        categoryLabel->setLineWidth(3);

        verticalLayout->addWidget(categoryLabel);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        calendarWidget = new QCalendarWidget(AnalysisPopup);
        calendarWidget->setObjectName("calendarWidget");
        sizePolicy1.setHeightForWidth(calendarWidget->sizePolicy().hasHeightForWidth());
        calendarWidget->setSizePolicy(sizePolicy1);
        calendarWidget->setMinimumSize(QSize(0, 300));
        calendarWidget->setSelectedDate(QDate(2027, 7, 8));
        calendarWidget->setGridVisible(true);
        calendarWidget->setVerticalHeaderFormat(QCalendarWidget::VerticalHeaderFormat::NoVerticalHeader);
        calendarWidget->setNavigationBarVisible(true);
        calendarWidget->setDateEditEnabled(false);

        verticalLayout->addWidget(calendarWidget);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(AnalysisPopup);

        QMetaObject::connectSlotsByName(AnalysisPopup);
    } // setupUi

    void retranslateUi(QDialog *AnalysisPopup)
    {
        AnalysisPopup->setWindowTitle(QCoreApplication::translate("AnalysisPopup", "Dialog", nullptr));
        titleLabel->setText(QCoreApplication::translate("AnalysisPopup", "Scream Analysis", nullptr));
        categoryLabel->setText(QCoreApplication::translate("AnalysisPopup", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AnalysisPopup: public Ui_AnalysisPopup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANALYSISPOPUP_H
