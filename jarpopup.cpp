#include "jarpopup.h"
#include "ui_jarpopup.h"
#include "scream.h"
#include "user.h"

jarPopup::jarPopup(MainPage* mainPage, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::jarPopup)
    , screamModel(new ScreamModel(this))
{
    ui->setupUi(this);
    screamModel->setScreams(mainPage->getCurrentuser()->getScreamList());
    setWindowTitle("Your Scream List");
    setWindowIcon(QIcon(":/images/jar.png"));

    // sort
    JarSortProxyModel* proxyModel = new JarSortProxyModel(this);
    proxyModel->setSourceModel(screamModel);
    proxyModel->setSortCaseSensitivity(Qt::CaseInsensitive);
    ui->screamTableView->setModel(proxyModel);
    ui->screamTableView->setSortingEnabled(true);

    // ui->screamTableView->setModel(screamModel);
    ui->screamTableView->setWordWrap(true);
    ui->screamTableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

    ui->screamTableView->resizeRowsToContents();
    ui->label->setText(mainPage->getCurrentuser()->getUsername() + QString("'s List of Screams"));

}


jarPopup::~jarPopup()
{
    delete ui;
}

void jarPopup::closePopup(){
    jarPopup::close();
}
