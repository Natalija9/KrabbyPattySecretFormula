#include "widget.h"
#include "ui_widget.h"
#include "level.h"
#include "settings.h"
#include "score.h"
#include<QFile>
Level *level;
Score *score;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , settings(new Settings)

{
    ui->setupUi(this);

    ui->checkSound->setChecked(true);
    ui->rbEasy->setChecked(true);

    score = new Score();

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

void Widget::on_checkSound_stateChanged(int arg1)
{
    settings->setSound(arg1);
}

void Widget::on_rbEasy_clicked()
{
    settings->setMode(0);
}

void Widget::on_rbHard_clicked()
{
    settings->setMode(1);
}




