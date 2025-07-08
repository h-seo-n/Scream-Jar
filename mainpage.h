#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>
#include "scream.h"
class ServerAPI;

namespace Ui {
class MainPage;
}

class User;
class ServerAPI;

class MainPage : public QWidget
{
    Q_OBJECT

public:
    explicit MainPage(ServerAPI *serv, QWidget *parent = nullptr);
    ~MainPage();
    QSharedPointer<User> getCurrentuser(){ return currentUser; }
    void setCurrentuser(QSharedPointer<User> user){ currentUser = user; }
    void setTitleText();
    void saveData();
    ServerAPI *server;

public slots:
    void updateWallColor(const QColor& color);

private slots:
    void on_enterButton_clicked();

    void on_customButton_clicked();
    void jarSlot();

    void on_feedButton_clicked();

    void on_analysisButton_clicked();

    void on_friendButton_clicked();

signals:
    void jarClicked(); // signal to emit to mainwindow when jar is clicked (responds to 'jar' widget's signal)
    void feedShow();

private:
    Ui::MainPage *ui;

    QSharedPointer<User> currentUser;
    QList<QSharedPointer<Scream>> *wholeScreamList;

    void setLabelImage(const QString& imagePath);
    void shakeWidget(QWidget* widget);
    bool eventFilter(QObject *obj, QEvent *event);

};

#endif // MAINPAGE_H
