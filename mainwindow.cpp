#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QScreen>
#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QApplication>
#include <QDebug>

#include "startpage.h"
#include "mainpage.h"
#include "clickablelabel.h"
#include "signupwidget.h"
#include "database.h"
#include "feedpopup.h"
#include "jarpopup.h"

class Scream;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    server(new ServerAPI(mainPage, this)),
    mainPage(new MainPage(this->server, this)),
    startPage(new StartPage(this->server, this))
{

    ui->setupUi(this);

    ui->stackedWidget->addWidget(startPage);
    ui->stackedWidget->addWidget(mainPage);
    setWindowTitle("Scream Jar");
    setWindowIcon(QIcon(":/images/jar.png"));


    if (!initializeDatabase()){
        qWarning() << "Database initialization failed!";
    }


    /* fetch saved credentials in user for login ;
        if exists -> load user, go to main immediately
        if no -> go to start page (default ; register)
    QString credentials = getSavedCredentials();
    if (!credentials.isEmpty()){
        QString savedUserID = credentials;
        qDebug() << "Found saved credentials. Attempting auto-login";
        this->localLogin(savedUserID); // emit loginSuccess()- receive in mainWindow right away
    } else {
        qDebug() << "No saved credentials. Showing login screen.";
        ui->stackedWidget->setCurrentWidget(startPage);
    }
    */
    ui->stackedWidget->setCurrentWidget(startPage);

    connect(server, &ServerAPI::loginSuccess, this, &MainWindow::localLogin);

    // connect(startPage, &StartPage::goToMain, this, &MainWindow::switchToMainPage);

    connect(mainPage, &MainPage::jarClicked, this, &MainWindow::showjarPopup);
    connect(mainPage, &MainPage::feedShow, this, &MainWindow::showFeedPopup);

    connect(qApp, &QApplication::aboutToQuit, this, &MainWindow::onAppClosing);

    // startPage's signupWidget sends QSharedPointer user
    connect(startPage->getSignupWidget(), &SignupWidget::signupUser, this, &MainWindow::signUp);
}


MainWindow::~MainWindow()
{
    delete ui;
}

// upon auto-login or login from widget : load user and change to mainPage screen
void MainWindow::localLogin(const QString &userID){
    this->mainPage->setCurrentuser(loadUser(userID));
    QColor color = this->mainPage->getCurrentuser()->getwallColor();
    this->mainPage->updateWallColor(color);

    ui->stackedWidget->setCurrentWidget(mainPage);
    this->mainPage->setTitleText();
}

// upon sign up signal from signupwidget : save new user and change to mainPage screen
void MainWindow::signUp(QSharedPointer<User> user){
    this->mainPage->setCurrentuser(user);
    ui->stackedWidget->setCurrentWidget(mainPage);
    saveUser(user);
    this->mainPage->setTitleText();
}


void MainWindow::showjarPopup(){

    // if dialog already open
    if (jarPopupInstance && jarPopupInstance->isVisible()) {
        jarPopupInstance->raise(); //bring to front
        jarPopupInstance->isActiveWindow(); //focus
        return;
    }

    // If not open - create new one
    jarPopupInstance = new jarPopup(mainPage, this);

    QScreen* screen = QGuiApplication::primaryScreen();
    if(screen){
        QRect screenGeometry = screen->geometry();
        QPoint center = screenGeometry.center();

        jarPopupInstance->move(center - QPoint(jarPopupInstance->width()/2, jarPopupInstance->height()/2));
    }

    // when closed clear pointer
    connect(jarPopupInstance, &QDialog::finished, this, [this]() {
        jarPopupInstance->deleteLater();
        jarPopupInstance = nullptr;
    });

    jarPopupInstance->show();

}

void MainWindow::showFeedPopup(){

    if (feedPopupInstance && feedPopupInstance->isVisible()) {
        feedPopupInstance->raise();
        feedPopupInstance->activateWindow();
        return;
    }

    feedPopupInstance = new FeedPopup(mainPage);
    QScreen* screen = QGuiApplication::primaryScreen();
    if(screen){
        QRect screenGeometry = screen->geometry();
        QPoint center = screenGeometry.center();

        int offSetX = 200;
        feedPopupInstance->move(center - QPoint(feedPopupInstance->width()/2 + offSetX, feedPopupInstance->height()/2));
    }

    connect(feedPopupInstance, &QDialog::finished, this, [this](){
        feedPopupInstance->deleteLater();
        feedPopupInstance = nullptr;
    });

    feedPopupInstance->show();

}

void MainWindow::onAppClosing(){
    if (mainPage) {
        mainPage->saveData();
        server->saveUserToServer(mainPage->getCurrentuser());
    }
}
