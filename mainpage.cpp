#include "mainpage.h"
#include "ui_mainpage.h"

#include "user.h"
#include "clickablelabel.h"
#include "custompopup.h"
#include "database.h"
#include "customtextedit.h"

#include <QPropertyAnimation>

#include <QDebug>
#include <QTimer>

#include "analysispopup.h"
#include "serverapi.h"
#include "friendspopup.h"

MainPage::MainPage(ServerAPI *serv, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainPage)
    , server(serv)
    , currentUser(new User(this))
{
    ui->setupUi(this);
    ui->screamTextEdit->installEventFilter(this);

    connect(ui->jar, &ClickableLabel::clicked, this, &MainPage::jarSlot);
    qDebug() << "Friend List" << currentUser->getFriendList();
}


MainPage::~MainPage()
{
    delete ui;
}

void MainPage::setTitleText(){

    ui->titleLabel->setText(currentUser->getUsername()+ QString("'s Scream Jar"));
}


void MainPage::updateWallColor(const QColor& color){
    currentUser->setWallColor(color);
    server->saveUserToServer(currentUser);

    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, color);
    setAutoFillBackground(true);
    setPalette(pal);
}

void MainPage::saveData(){

    if (saveUser(getCurrentuser())){
        qDebug() << "User data saved successfully.";
    } else{
        qWarning() << "Failed to save user data.";
    }

}


void MainPage::on_enterButton_clicked()
{
    if (!(ui->screamTextEdit->toPlainText().isEmpty())){

        currentUser->addScream(ui->categoryComboBox->currentIndex(), ui->screamTextEdit->toPlainText());
        const auto &lastScream = currentUser->getScreamList().last();

        if(!saveScream(currentUser->getUserID(), *lastScream)){
            qWarning() << "failed to save Scream to database.";
        }

        server->saveScreamToServer(currentUser->getUserID(), lastScream);

        ui->screamTextEdit->clear();
        shakeWidget(ui->jarWidget);
    }
}


void MainPage::jarSlot(){
    emit jarClicked();
}


void MainPage::shakeWidget(QWidget *widget){
    QPropertyAnimation* animation = new QPropertyAnimation(widget, "pos");

    animation->setDuration(500);
    int shakeDistance = 10;

    QPoint originalPos = widget->pos();

    animation->setKeyValueAt(0, originalPos);
    animation->setKeyValueAt(0.1, originalPos + QPoint(shakeDistance, 0));
    animation->setKeyValueAt(0.2, originalPos - QPoint(shakeDistance, 0));
    animation->setKeyValueAt(0.3, originalPos + QPoint(shakeDistance, 0));
    animation->setKeyValueAt(0.4, originalPos - QPoint(shakeDistance, 0));
    animation->setKeyValueAt(0.5, originalPos);

    QObject::connect(animation, &QPropertyAnimation::finished, animation, &QObject::deleteLater);

    animation->start();
}

void MainPage::on_customButton_clicked()
{
    customPopup* popup = new customPopup(this);
    connect(popup, &customPopup::backgroundColorChanged, this, &MainPage::updateWallColor);

    if(getCurrentuser()->getwallColor().isValid()) popup->customPopup::displayBackgroundColorButton(getCurrentuser()->getwallColor());

    popup->move(ui->customButton->mapToGlobal(QPoint(-2*(ui->customButton->width()),ui->customButton->height()))); // position below button
    popup->show();
}


void MainPage::on_feedButton_clicked()
{
    emit feedShow();
}




void MainPage::on_analysisButton_clicked() {
    // Prepare analysis data
    QMap<int, int> categoryCounts;
    QMap<QDate, int> dailyCounts;
    int totalScreams = 0;

    QDate startDate = QDate::currentDate();
    QDate endDate = QDate::currentDate();

    for (const auto &scream : getCurrentuser()->getScreamList()) {
        ++totalScreams;

        int category = scream->getCategoryIndex();
        categoryCounts[category]++;

        QDate screamDate = scream->getDate().date();
        dailyCounts[screamDate]++;

        if (screamDate < startDate) startDate = screamDate;
        if (screamDate > endDate) endDate = screamDate;
    }

    // Create and show the analysis widget
    AnalysisPopup *popup = new AnalysisPopup(this);
    popup->setAnalysisData(totalScreams, categoryCounts, dailyCounts, startDate, endDate);

    popup->setAttribute(Qt::WA_DeleteOnClose); // Automatically delete when closed
    popup->show(); // Use show() for non-modal widget
}




void MainPage::on_friendButton_clicked()
{
    FriendsPopup* popup = new FriendsPopup(server, this, currentUser->getFriendList());
    popup->move(ui->friendButton->mapToGlobal(QPoint(-2*(ui->friendButton->width()), ui->friendButton->height())));
    popup->show();
}

bool MainPage::eventFilter(QObject *obj, QEvent *event){
    if (obj==ui->screamTextEdit){
        if (event->type() == QEvent::KeyPress){
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);

            if (keyEvent->key()==Qt::Key_Return || keyEvent->key()==Qt::Key_Enter) {
                if (keyEvent->modifiers() & Qt::ShiftModifier){
                    // shift+Enter : Insert a new line in the QTextEdit
                    return false; // let the QTextEdit handle this event
                } else {
                    // Enter : Trigger the enter button
                    on_enterButton_clicked();
                    return true; // consume the event, prevent further handling
                }
            }
        }
    }
    // Default behavior for all other events
    return QWidget::eventFilter(obj, event);
}
