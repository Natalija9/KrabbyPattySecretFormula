#include "widget.h"
#include "ui_widget.h"
#include "level.h"

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
    Level *level = new Level();
    level->start();
    this->hide();
    ui->stackedWidget->setCurrentIndex(2);

}

