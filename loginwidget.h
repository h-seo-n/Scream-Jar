#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>

namespace Ui {
class LoginWidget;
}

class ServerAPI;

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(ServerAPI *serv, QWidget *parent = nullptr);
    ~LoginWidget();

private slots:
    void on_continueButton_clicked();
    void showLoginfailMessage();
    void showTemporaryMessage(const QString& message, int duration = 3000);

    void on_signupButton_clicked();

signals:
    void goToSignup();

private:
    Ui::LoginWidget *ui;
    ServerAPI *server;

    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // LOGINWIDGET_H
