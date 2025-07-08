#include "signupwidget.h"
#include "ui_signupwidget.h"
#include "startpage.h"
#include "serverapi.h"
#include "user.h"
#include <QPropertyAnimation>
#include <QTimer>

SignupWidget::SignupWidget(ServerAPI *serv, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SignupWidget)
    , server(serv)
{
    ui->setupUi(this);
    idDuplicatePass = false; // whether ID passes duplicate check(confirmed at idCheck)

    // serverAPI's checkUserExist - sends userExists signal, & idCheck slot recieves the signal
    connect(server, &ServerAPI::userExists, this, &SignupWidget::idCheck);
}

SignupWidget::~SignupWidget()
{
    delete ui;
}

void SignupWidget::on_continueButton_clicked()
{
    // sign user up

    QString userpw = ui->passwordInput->text();
    if (userpw != ui->passwordcheckInput->text()){
        showTemporaryMessage("Password isn't consistent. Please try again");
        return;
    }

    QString username = ui->usernameInput->text();
    QString userID = ui->useridInput->text();
    if (!idDuplicatePass){
        showTemporaryMessage("Please check your ID");
        return;
    }

    // send signup info to mainwindow (so it can set currentUser)
    auto user = QSharedPointer<User>::create();
    user->setUserID(userID);
    user->setUsername(username);

    emit signupUser(user);

    // sign up in server
    server->registerUser(user, userpw);

}

void SignupWidget::idCheck(bool exists) {
    if (exists){
        idDuplicatePass = false;
        ui->idcheckLabel->setStyleSheet("{color: #008000}");
        ui->idcheckLabel->setText("ID taken :'(");

    } else {
        idDuplicatePass = true;
        ui->idcheckLabel->setStyleSheet("{color: #FF0000}");
        ui->idcheckLabel->setText("ID available!");
    }
}

void SignupWidget::showTemporaryMessage(const QString &message, int duration) {
    // Create a QLabel dynamically
    QLabel *errorLabel = new QLabel(message, this);
    errorLabel->setStyleSheet("background-color: rgba(255, 0, 0, 200); "
                              "color: white; "
                              "border-radius: 5px; "
                              "padding: 5px; "
                              "font-size: 14px; "
                              "font-weight: bold;");
    errorLabel->setAttribute(Qt::WA_DeleteOnClose); // Automatically delete when closed

    // Position the label in the center above the UI
    QSize parentSize = this->size();
    errorLabel->adjustSize(); // Ensure the QLabel resizes to fit the text
    int x = (parentSize.width() - errorLabel->width()) / 2;
    int y = 50; // Floating above the UI
    errorLabel->move(x, y);

    // Show the label
    errorLabel->show();

    // Fade-out animation
    QPropertyAnimation *animation = new QPropertyAnimation(errorLabel, "opacity");
    animation->setDuration(1000); // 1 second fade-out
    animation->setStartValue(1.0); // Fully visible
    animation->setEndValue(0.0);   // Fully invisible
    animation->setEasingCurve(QEasingCurve::OutQuad);

    // Auto-remove the label after the duration
    QTimer::singleShot(duration, [errorLabel, animation]() {
        animation->start();
        QObject::connect(animation, &QPropertyAnimation::finished, errorLabel, &QLabel::close);
    });
}

void SignupWidget::on_idAvailableButton_clicked()
{
    QString userID = ui->useridInput->text();
    server->ServerAPI::checkUserExists(userID);
}


void SignupWidget::on_loginButton_clicked()
{
    emit goToLogin();
}

