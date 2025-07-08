#include "friendaddpopup.h"
#include "ui_friendaddpopup.h"
#include "customtextedit.h"
#include "serverapi.h"
#include "user.h"
#include <QPropertyAnimation>
#include <QTimer>

friendAddPopup::friendAddPopup(ServerAPI *serv, MainPage* page, QWidget *parent)
    : QWidget(parent, Qt::Popup | Qt::FramelessWindowHint)
    , mainPage(page)
    , ui(new Ui::friendAddPopup)
    , server(serv)
{
    ui->setupUi(this);
    ui->confirmWidget->hide();
    ui->idInput->installEventFilter(this);;
    connect(ui->pushButton, &QPushButton::clicked, this, &friendAddPopup::close);

    // when user is searched
    connect(server, &ServerAPI::userLoaded, this, &friendAddPopup::onFriendFound);

    // search fail
    connect(server, &ServerAPI::userNotLoaded, this, [=](){
        showTemporaryMessage("User not found, please check ID!");
    });
}

friendAddPopup::~friendAddPopup()
{
    delete ui;
}

bool friendAddPopup::eventFilter(QObject *obj, QEvent *event){
    if (obj==ui->idInput){
        if (event->type() == QEvent::KeyPress){
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

            if (keyEvent->key()==Qt::Key_Return || keyEvent->key()==Qt::Key_Enter) {
                if (keyEvent->modifiers() & Qt::ShiftModifier){
                    // shift+Enter : Insert a new line in the QTextEdit
                    return false; // let the QTextEdit handle this event
                } else {
                    // Enter : Trigger the enter button
                    on_searchButton_clicked();
                    return true; // consume the event, prevent further handling
                }
            }
        }
    }
    // Default behavior for all other events
    return QWidget::eventFilter(obj, event);
}

void friendAddPopup::on_searchButton_clicked()
{
    server->loadUserFromServer(ui->idInput->text());

}

void friendAddPopup::onFriendFound(QSharedPointer<User> user)
{
    friendInstance = user;

    if (mainPage->getCurrentuser()->getFriendList().contains(user->getUserID()))
    {
        showTemporaryMessage("this user is already your friend");
        return;
    } else if (!friendInstance) {
        showTemporaryMessage("Friend data not loaded.");
        return;
    }

    ui->searchWidget->hide();
    ui->confirmWidget->show();
    ui->friendIDLabel->setText(user->getUserID());
    ui->friendUsernameLabel->setText(user->getUsername());
}

// friend add - back
void friendAddPopup::on_pushButton_3_clicked()
{
    ui->confirmWidget->hide();
    ui->searchWidget->show();
}

// friend add ok
void friendAddPopup::on_pushButton_2_clicked()
{
    server->addFriend(mainPage->getCurrentuser()->getUserID(), friendInstance->getUserID());
    mainPage->getCurrentuser()->addFriend(friendInstance->getUserID());
    this->close();
    emit friendAdd();
}

// textbox
void friendAddPopup::showTemporaryMessage(const QString& message, int duration)
{
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


