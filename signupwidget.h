#ifndef SIGNUPWIDGET_H
#define SIGNUPWIDGET_H

#include <QWidget>
#include <QSharedPointer>

class ServerAPI;
class User;

namespace Ui {
class SignupWidget;
}

class SignupWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SignupWidget(ServerAPI *serv, QWidget *parent = nullptr);
    ~SignupWidget();

    ServerAPI *server;

private slots:
    void on_continueButton_clicked();
    void idCheck(bool exists);
    void on_idAvailableButton_clicked();

    void on_loginButton_clicked();

signals:
    void signupUser(QSharedPointer<User> user);
    void goToLogin();

private:
    Ui::SignupWidget *ui;
    bool idDuplicatePass;
    bool idAvailable;

    void showTemporaryMessage(const QString& message, int duration = 3000);
    bool checkUserid(const QString &userID);
};

#endif // SIGNUPWIDGET_H
