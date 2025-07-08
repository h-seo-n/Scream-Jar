#include "feedpopup.h"
#include "ui_feedpopup.h"
#include "mainpage.h"
#include "feedmodel.h"

class ServerAPI;

FeedPopup::FeedPopup(MainPage* mainPage, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FeedPopup)
    , feedModel(new FeedModel(mainPage->getCurrentuser(), mainPage->server))
{
    ui->setupUi(this);
    setWindowTitle("Scream Feed");
    setWindowIcon(QIcon(":/icons/users.svg"));


    ui->tableView->setModel(feedModel);
    ui->tableView->setWordWrap(true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

    ui->tableView->resizeRowsToContents();
}

FeedPopup::~FeedPopup()
{
    delete ui;
}
