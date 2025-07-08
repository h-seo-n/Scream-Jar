#ifndef FEEDPOPUP_H
#define FEEDPOPUP_H

#include <QDialog>
class MainPage;
class FeedModel;

namespace Ui {
class FeedPopup;
}

class FeedPopup : public QDialog
{
    Q_OBJECT

public:
    explicit FeedPopup(MainPage *mainPage, QWidget *parent = nullptr);
    ~FeedPopup();

private:
    Ui::FeedPopup *ui;
    FeedModel* feedModel;
};

#endif // FEEDPOPUP_H
