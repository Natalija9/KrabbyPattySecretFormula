#include "widget.h"
#include "ui_widget.h"
#include "level.h"
#include "settings.h"
#include "score.h"
#include "ranglist.h"
#include<QFile>


#include<iostream>

Level *level;
Score *score;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , settings(new Settings)
    , ranglist (new RangList)
{
    ui->setupUi(this);

    ui->checkSound->setChecked(true);
    ui->rbEasy->setChecked(true);

    score = new Score();
    levelData = new LevelData();


    QObject::connect(ui->Level1, SIGNAL(clicked()), this, SLOT(createLevel()));
    QObject::connect(ui->Level2, SIGNAL(clicked()), this, SLOT(createLevel()));
    QObject::connect(ui->Level3, SIGNAL(clicked()), this, SLOT(createLevel()));
    QObject::connect(ui->Level4, SIGNAL(clicked()), this, SLOT(createLevel()));
    QObject::connect(ui->Level5, SIGNAL(clicked()), this, SLOT(createLevel()));
    QObject::connect(ui->Level6, SIGNAL(clicked()), this, SLOT(createLevel()));
}

void Widget::createLevel(){
    int levelId = sender()->objectName().toStdString()[5] - '0';
    level = new Level(levelId, levelData);
    level->startLevel();
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



void Widget::on_rangListButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
   // ui->text_rang_list->setAlignment(Qt::AlignCenter);
    ui->text_rang_list->setText(ranglist->printListToRangList());
    //this->hide();
}



void Widget::on_pushButtonMainMenu_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

