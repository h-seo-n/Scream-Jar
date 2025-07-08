#include "friendspopup.h"
#include "ui_friendspopup.h"
#include <QMessageBox>
#include "friendaddpopup.h"
#include "serverapi.h"

FriendsPopup::FriendsPopup(ServerAPI *serv, MainPage *page, QList<QString> friends, QWidget *parent)
    : QWidget(parent, Qt::Popup | Qt::FramelessWindowHint)
    , ui(new Ui::FriendsPopup)
    , server(serv)
    , mainPage(page)
    , friendModel(new FriendModel(serv, friends, this))
{
    ui->setupUi(this);

    auto loadingLabel = new QLabel("Loading friends...", this);
    loadingLabel->setAlignment(Qt::AlignCenter);
    loadingLabel->show();
    ui->tableView->hide(); // hide table until ready

    ui->verticalLayout_2->insertWidget(0, loadingLabel);

    ui->tableView->setModel(friendModel);
    ui->tableView->setWordWrap(true);
    ui->tableView->resizeRowsToContents();
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    QItemSelectionModel* selectionModel = new QItemSelectionModel(friendModel, this);
    ui->tableView->setSelectionModel(selectionModel);

    /*
    connect(selectionModel, &QItemSelectionModel::selectionChanged, this, [=](const QItemSelection& selected, const QItemSelection&){
        if(!selected.indexes().isEmpty()) {
            QModelIndex index = selected.indexes().first();
            QSharedPointer<User> selectedUser = model->getUserAt(index.row());
            qDebug() << "selected friend:" << selectedUser->getUserName();
        }
    });
    */

    // loading label
    connect(friendModel, &FriendModel::loadingComplete, this, [=]() {
        loadingLabel->hide();
        ui->tableView->show();
    });


    // close slot
    connect(ui->closeButton, &QPushButton::clicked, this, &FriendsPopup::close);

    // delete slot
    /*
    connect(ui->deleteButton, &QPushButton::clicked, this, [this, selectionModel](){
        QModelIndexList selected = selectionModel->selectedRows();

        if (selected.isEmpty()) return;

        QList<int> rowsToDelete;
        QList<QString> userIDsToDelete;

        for (const QModelIndex& index : selected) {
            rowsToDelete.append(index.row());
            QSharedPointer<User> user = friendModel->getUserAt(index.row());
            if (user) userIDsToDelete.append(user->getUserID());
        }

        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirm Deletion",
                                      "Are you sure you want to delete the selected friend(s)?",
                                      QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            friendModel->removeFriendsAt(rowsToDelete);

            for (const QString &id : userIDsToDelete) {
                server->deleteFriend(id);
            }
        }

    });
    */
}

FriendsPopup::~FriendsPopup()
{
    delete ui;
}

void FriendsPopup::updateFriends() {
    friendModel->refreshData(mainPage->getCurrentuser()->getFriendList());
}

void FriendsPopup::on_addButton_clicked()
{
    friendAddPopup* popup = new friendAddPopup(server, mainPage, this);
    popup->move(ui->addButton->mapToGlobal(QPoint(-2*(ui->addButton->width()), ui->addButton->height())));
    popup->show();
    connect(popup, &friendAddPopup::friendAdd, this, [this]() {
        this->updateFriends();
        this->close();  // optional
    });
}

