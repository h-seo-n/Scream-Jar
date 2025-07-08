#ifndef FRIENDADDPOPUP_H
#define FRIENDADDPOPUP_H

#include <QWidget>
class ServerAPI;
class User;
class MainPage;

namespace Ui {
class friendAddPopup;
}

class friendAddPopup : public QWidget
{
    Q_OBJECT

public:
    explicit friendAddPopup(ServerAPI *serv, MainPage *page, QWidget *parent = nullptr);
    ~friendAddPopup();
    ServerAPI *server;
    void showTemporaryMessage(const QString& message, int duration = 3000);

private slots:
    void on_searchButton_clicked();
    void onFriendFound(QSharedPointer<User> user);
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();


private:
    Ui::friendAddPopup *ui;
    QSharedPointer<User> friendInstance;
    MainPage *mainPage;
    bool eventFilter(QObject *obj, QEvent *event);

signals:
    void friendAdd();

};

#endif // FRIENDADDPOPUP_H
