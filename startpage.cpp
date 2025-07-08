#include "startpage.h"
#include "ui_startpage.h"
#include <QDebug>
#include "database.h"
#include <QPropertyAnimation>
#include <QTimer>
#include <loginwidget.h>
#include <signupwidget.h>

StartPage::StartPage(ServerAPI *serv, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StartPage)
    , server(serv)
    , loginWidget(new LoginWidget(serv, this))
    , signupWidget(new SignupWidget(serv, this))
{
    ui->setupUi(this);
    // connect(continueButton, &QPushButton::clicked, this, &StartPage::goToMain);
    ui->stackedWidget->addWidget(loginWidget);
    ui->stackedWidget->addWidget(signupWidget);
    ui->stackedWidget->setCurrentWidget(loginWidget);

    connect(loginWidget, &LoginWidget::goToSignup, this, [=](){
        ui->stackedWidget->setCurrentWidget(signupWidget);
    });

    connect(signupWidget, &SignupWidget::goToLogin, this, [=](){
        ui->stackedWidget->setCurrentWidget(loginWidget);
    });
}

StartPage::~StartPage()
{
    delete ui;
}


/*
void StartPage::on_continueButton_clicked()
{
    if (ui->usernameInput->text().isEmpty() || ui->passwordInput->text().isEmpty()) {
        showTemporaryMessage("Please enter both Username and Password.");
        return;
    }

    QString userID = ui->useridInput->text();
    QString username = ui->usernameInput->text();

    if (userExists(userID)){
        if (username != getUsernameByUserID(userID)){
            showTemporaryMessage("The User ID is already used; Or if you are a previous user, "
                                 "please check if your username input is correct.");

            return;
        }
    }


    emit goToMain(username, userID);
    qDebug() << username;
}
*/
void StartPage::showTemporaryMessage(const QString &message, int duration) {
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

