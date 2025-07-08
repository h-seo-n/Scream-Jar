#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QSharedPointer>

#include "user.h"
#include "scream.h"
#include "jarpopup.h"
#include "serverapi.h"
class FeedPopup;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

#include "startpage.h"
#include "mainpage.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showjarPopup();
    void showFeedPopup();
    ServerAPI* server;


private slots:
    void localLogin(const QString& userID);
    void signUp(QSharedPointer<User> user);
    // void switchToMainPage(const QString& name, const QString& ID);
    void onAppClosing();

private:
    Ui::MainWindow *ui;
    StartPage *startPage;
    MainPage *mainPage;
    jarPopup* jarPopupInstance = nullptr;
    FeedPopup* feedPopupInstance = nullptr;




};
#endif // MAINWINDOW_H
