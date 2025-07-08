#include "analysispopup.h"
#include "ui_analysispopup.h"
#include <QTextCharFormat>
#include <QColor>
#include <QBrush>
#include "scream.h"

AnalysisPopup::AnalysisPopup(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::AnalysisPopup) {
    ui->setupUi(this); // Link the UI generated from the .ui file
    setWindowTitle("Analysis");
    setWindowIcon(QIcon(":/icons/chart.svg"));
}

AnalysisPopup::~AnalysisPopup() {
    delete ui; // Clean up the UI object
}

void AnalysisPopup::setAnalysisData(
    int totalScreams,
    const QMap<int, int> &categoryCounts,
    const QMap<QDate, int> &dailyCounts,
    const QDate &startDate,
    const QDate &endDate
    ) {
    displayCategoryAnalysis(categoryCounts, totalScreams);
    displayCalendarAnalysis(dailyCounts, startDate, endDate);
}

void AnalysisPopup::displayCategoryAnalysis(const QMap<int, int> &categoryCounts, int totalScreams) {
    QString summary = QString("Total Screams: %1\n").arg(totalScreams);
    for (auto category : categoryCounts.keys()) {
        int count = categoryCounts[category];
        float percentage = (float(count) / totalScreams) * 100;
        summary += QString("Category %1: %2 screams (%3%)\n").arg(getCategoryString(category)).arg(count).arg(percentage, 0, 'f', 2);
    }

    // Assuming `categoryLabel` is a QLabel in your .ui file for displaying the category analysis
    ui->categoryLabel->setText(summary);
}

void AnalysisPopup::displayCalendarAnalysis(const QMap<QDate, int> &dailyCounts, const QDate &startDate, const QDate &endDate) {
    ui->calendarWidget->setMinimumDate(startDate);
    ui->calendarWidget->setMaximumDate(endDate);

    // Determine the maximum count for normalization
    int maxCount = 10;
    if (!dailyCounts.isEmpty()) {
        maxCount = *std::max_element(dailyCounts.begin(), dailyCounts.end());
    }

    for (const auto &date : dailyCounts.keys()) {
        int count = dailyCounts[date];

        // Normalize count to range 0-1
        double normalized = qMin(1.0, static_cast<double>(count) / maxCount);

        // Set color based on scream frequency
        int hue = 240 - static_cast<int>(normalized * 240);

        // less scream - blue, more screams - red
        QColor color = QColor::fromHsv(hue, 255, 200);
        QTextCharFormat format;
        format.setBackground(QBrush(color));
        ui->calendarWidget->setDateTextFormat(date, format);
    }
}

QString AnalysisPopup::getCategoryString(int index) const {
    switch(index){
    case 0: return QString("Study/School");
    case 1: return QString("Work");
    case 2: return QString("Relationship");
    case 3: return QString("Financial issues");
    case 4:return QString("Politics/Society");
    default: return QString("Unknown");
    }
}
