#include "custompopup.h"
#include "ui_custompopup.h"
#include <QApplication>
#include <QColorDialog>

customPopup::customPopup(QWidget *parent)
    : QWidget(parent, Qt::Popup | Qt::FramelessWindowHint)
    , ui(new Ui::customPopup)
{
    ui->setupUi(this);
    // setAttribute(Qt::WA_DeleteOnClose); // Automatically delete when closed

    connect(ui->pushButton, &QPushButton::clicked, this, &customPopup::close);
    ui->widget_3->hide();

}

customPopup::~customPopup()
{
    delete ui;
}





void customPopup::on_jarToolButton_clicked()
{
    selectJarColorButton();
}


void customPopup::on_backgroundToolButton_clicked()
{
    selectBackgroundColorButton();
}

void customPopup::selectJarColorButton(){
    QColor jarColor = QColorDialog::getColor();
    if (jarColor.isValid()){
        QPixmap px(30,30);
        px.fill(jarColor);
        ui->toolButton->setIcon(px);
        // ui->toolButton->setAutoFillBackground(true);
        // ui->toolButton->setPalette(QPalette(jarColor));

        emit jarColorChanged(jarColor);
    }
}


void customPopup::selectBackgroundColorButton(){
    QColor backgroundColor = QColorDialog::getColor();
    if (backgroundColor.isValid()){

        displayBackgroundColorButton(backgroundColor);

        emit backgroundColorChanged(backgroundColor);
    }
}

void customPopup::displayBackgroundColorButton(QColor backgroundColor){

    // QPixmap px(30,30);
    //    px.fill(backgroundColor); // Fill the pixmap with the desired color
    //    ui->toolButton_2->setIcon(QIcon(px));
    ui->toolButton_2->setStyleSheet(QString("background-color: %1;").arg(backgroundColor.name()));

}


