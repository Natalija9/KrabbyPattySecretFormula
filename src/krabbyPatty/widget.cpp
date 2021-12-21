#include "widget.h"
#include "ui_widget.h"
#include "level.h"
#include "settings.h"
#include "score.h"
#include "ranglist.h"
#include<QFile>
#include<QVector>
#include <QMessageBox>

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

    levelData = new LevelData(settings);

    score = new Score();
    QVector<QLabel*> labels;
    labels.append(ui->Score1);
    labels.append(ui->Score2);
    labels.append(ui->Score3);
    labels.append(ui->Score4);
    labels.append(ui->Score5);
    labels.append(ui->Score6);
    score->setScoreLabels(labels);

    QVector<QPushButton*> buttons;
    buttons.append(ui->Level1);
    buttons.append(ui->Level2);
    buttons.append(ui->Level3);
    buttons.append(ui->Level4);
    buttons.append(ui->Level5);
    buttons.append(ui->Level6);
    score->setLevelButtons(buttons);



    QObject::connect(ui->Level1, SIGNAL(clicked()), this, SLOT(createLevel()));
    QObject::connect(ui->Level2, SIGNAL(clicked()), this, SLOT(createLevel()));
    QObject::connect(ui->Level3, SIGNAL(clicked()), this, SLOT(createLevel()));
    QObject::connect(ui->Level4, SIGNAL(clicked()), this, SLOT(createLevel()));
    QObject::connect(ui->Level5, SIGNAL(clicked()), this, SLOT(createLevel()));
    QObject::connect(ui->Level6, SIGNAL(clicked()), this, SLOT(createLevel()));
}


Widget::~Widget()
{
    delete ui;
}


void Widget::createLevel(){
    int levelId = sender()->objectName().toStdString()[5] - '0';
    level = new Level(levelId, levelData);

    QObject::connect(level, SIGNAL(endLevel()), this, SLOT(updateScore()));
    level->startLevel();
}



void Widget::updateScore(){

    delete level;

    if(score->isSuccessful()){
        ui->Give_up->setText("Save Score");
    }

    if(score->getLives() == 0){
        score->reset();

        QMessageBox msgBox;
        msgBox.setText("No spare lives left. Better luck next time!");
        msgBox.setWindowTitle(" ");
        msgBox.setStyleSheet("font-size: 20px; font-style: bolid italic;  color: rgb(0, 0, 0);");
        msgBox.exec();

        ui->stackedWidget->setCurrentIndex(0);

    }

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
    ui->text_rang_list->setText(ranglist->printListToRangList());
}



void Widget::on_pushButtonMainMenu_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void Widget::on_helpButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}




void Widget::on_buttonBox_accepted()
{
     ui->stackedWidget->setCurrentIndex(1);
}


void Widget::on_buttonBox_rejected()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void Widget::on_Give_up_clicked()
{
    if(!score->isSuccessful()){
        ui->stackedWidget->setCurrentIndex(0);
        score->reset();

    }
    else {
        ui->stackedWidget->setCurrentIndex(3);
        ui->text_rang_list->setText(ranglist->printListToRangList());

        // za sada se ovde resetuje rezultat, treba povezati upisivanje novog rezultata u rang listu
        score->reset();
    }

}

