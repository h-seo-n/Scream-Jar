#ifndef CUSTOMPOPUP_H

#define CUSTOMPOPUP_H

#include <QWidget>

namespace Ui {
class customPopup;
}

class customPopup : public QWidget
{
    Q_OBJECT

public:
    explicit customPopup(QWidget *parent = nullptr);
    ~customPopup();
    void displayBackgroundColorButton(QColor backgroundColor);


private slots:
    void on_jarToolButton_clicked();

    void on_backgroundToolButton_clicked();

    void selectJarColorButton();
    void selectBackgroundColorButton();


private:
    Ui::customPopup *ui;

signals:
    void jarColorChanged(const QColor& color);
    void backgroundColorChanged(const QColor& color);


};

#endif // CUSTOMPOPUP_H
