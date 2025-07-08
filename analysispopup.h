#ifndef ANALYSISPOPUP_H
#define ANALYSISPOPUP_H

#include <QDialog>
#include <QMap>
#include <QDate>

namespace Ui {
class AnalysisPopup;
}

class AnalysisPopup : public QDialog
{
    Q_OBJECT

public:
    explicit AnalysisPopup(QWidget *parent = nullptr);
    ~AnalysisPopup();

    void setAnalysisData(
        int totalScreams,
        const QMap<int, int> &categoryCounts,
        const QMap<QDate, int> &dailyCounts,
        const QDate &startDate,
        const QDate &endDate
        );

private:
    Ui::AnalysisPopup *ui;

    void displayCategoryAnalysis(const QMap<int, int> &categoryCounts, int totalScreams);
    void displayCalendarAnalysis(const QMap<QDate, int> &dailyCounts, const QDate &startDate, const QDate &endDate);
    QString getCategoryString(int index) const;
};

#endif // ANALYSISPOPUP_H
