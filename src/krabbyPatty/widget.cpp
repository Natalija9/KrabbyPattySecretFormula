#include "widget.h"
#include "ui_widget.h"
#include "level.h"

Level *level;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}



void Widget::onEsc(QKeyEvent *event){
    if(event->key() == Qt::Key_Escape)
        ui->stackedWidget->setCurrentIndex(0);
}

void Widget::on_quitButton_clicked()
{
    this->close();
}


void Widget::on_Level1_clicked()
{
    level = new Level();

    this->hide();


}


void Widget::on_settingsButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}


void Widget::on_pushButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

