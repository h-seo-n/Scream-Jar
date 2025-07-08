#ifndef FRIENDSPOPUP_H
#define FRIENDSPOPUP_H

#include <QWidget>
#include "friendmodel.h"
class ServerAPI;
class MainPage;

namespace Ui {
class FriendsPopup;
}

class FriendsPopup : public QWidget
{
    Q_OBJECT

public:
    explicit FriendsPopup(ServerAPI *serv, MainPage *page, QList<QString> friends, QWidget *parent = nullptr);
    void updateFriends();
    ~FriendsPopup();
    ServerAPI *server;

private slots:
    void on_addButton_clicked();

private:
    Ui::FriendsPopup *ui;
    MainPage *mainPage;
    FriendModel* friendModel;
};

#endif // FRIENDSPOPUP_H
