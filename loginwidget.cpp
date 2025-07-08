#include "loginwidget.h"
#include "ui_loginwidget.h"
#include "serverapi.h"
#include "startpage.h"
#include <QPropertyAnimation>
#include <QTimer>
#include "customtextedit.h"

LoginWidget::LoginWidget(ServerAPI *serv, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWidget)
    , server(serv)
{
    ui->setupUi(this);
    ui->useridInput->installEventFilter(this);
    ui->passwordInput->installEventFilter(this);
    connect(this->server, &ServerAPI::loginFailed, this, &LoginWidget::showLoginfailMessage);
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

void LoginWidget::on_continueButton_clicked()
{
    // upon passive-login :
    /* user credentials weren't in local files - so check server file instead */
    QString userID = ui->useridInput->text();
    QString userPW = ui->passwordInput->text();
    this->server->login(userID, userPW); //result signal-> deal success in mainwindow, deal fail here
}

void LoginWidget::showTemporaryMessage(const QString &message, int duration) {
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

void LoginWidget::showLoginfailMessage(){
    showTemporaryMessage("Incorrect ID and Password! Please try again");
}


void LoginWidget::on_signupButton_clicked()
{
    emit goToSignup();
}

bool LoginWidget::eventFilter(QObject *obj, QEvent *event){
    if ((obj==ui->passwordInput) || (obj==ui->useridInput)){
        if (event->type() == QEvent::KeyPress){
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

            if (keyEvent->key()==Qt::Key_Return || keyEvent->key()==Qt::Key_Enter) {
                if (keyEvent->modifiers() & Qt::ShiftModifier){
                    // shift+Enter : Insert a new line in the QTextEdit
                    return false; // let the QTextEdit handle this event
                } else {
                    // Enter : Trigger the enter button
                    on_continueButton_clicked();
                    return true; // consume the event, prevent further handling
                }
            }
        }
    }
    // Default behavior for all other events
    return QWidget::eventFilter(obj, event);
}

