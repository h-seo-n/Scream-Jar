#ifndef STARTPAGE_H
#define STARTPAGE_H

#include <QObject>
#include <QWidget>

class LoginWidget;
class SignupWidget;
class ServerAPI;

namespace Ui {
class StartPage;
}

class StartPage : public QWidget
{
    Q_OBJECT

public:
    explicit StartPage(ServerAPI *serv, QWidget *parent = nullptr);
    ~StartPage();
    void showTemporaryMessage(const QString& message, int duration = 3000);
    SignupWidget* getSignupWidget() const {
        return signupWidget;
    }

    ServerAPI *server;

    /*
signals:
    void goToMain(const QString& username, const QString& userID);
*/
private:
    Ui::StartPage *ui;
    LoginWidget *loginWidget;
    SignupWidget *signupWidget;
};

#endif // STARTPAGE_H
