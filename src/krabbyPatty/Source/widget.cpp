#include "Headers/widget.h"
#include "ui_widget.h"
#include "Headers/level.h"
#include "Headers/settings.h"
#include "Headers/score.h"
#include "Headers/ranglist.h"
#include <QFile>
#include <QVector>
#include <QMessageBox>
#include <QInputDialog>
#include <QDir>

#include<iostream>

Level *level;
Score *score;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , settings(new Settings)
    , ranglist (new RangList)
{

//Using custom font
    fontSetUp();

    ui->setupUi(this);

    ui->checkSound->setChecked(true);
    ui->rbEasy->setChecked(true);



    levelData = new LevelData(settings);

    score = new Score(levelData);
    QVector<QLabel*> labels;
    labels.append(ui->Score1);
    labels.append(ui->Score2);
    labels.append(ui->Score3);
    labels.append(ui->Score4);
    labels.append(ui->Score5);
    labels.append(ui->Score6);

    QVector<QPushButton*> buttons;
    buttons.append(ui->Level1);
    buttons.append(ui->Level2);
    buttons.append(ui->Level3);
    buttons.append(ui->Level4);
    buttons.append(ui->Level5);
    buttons.append(ui->Level6);

    score->setScoreLabels(labels);
    score->setLevelButtons(buttons);

    QObject::connect(ui->Level1, SIGNAL(clicked()), this, SLOT(createLevel()));
    QObject::connect(ui->Level2, SIGNAL(clicked()), this, SLOT(createLevel()));
    QObject::connect(ui->Level3, SIGNAL(clicked()), this, SLOT(createLevel()));
    QObject::connect(ui->Level4, SIGNAL(clicked()), this, SLOT(createLevel()));
    QObject::connect(ui->Level5, SIGNAL(clicked()), this, SLOT(createLevel()));
    QObject::connect(ui->Level6, SIGNAL(clicked()), this, SLOT(createLevel()));
}

void Widget::fontSetUp(){
    int id = QFontDatabase::addApplicationFont(":/fonts/KrabbyPatty.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont krabbyPatty(family);
    QApplication::setFont(krabbyPatty);
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
        score->msg->setMessageText(MessageText::NoMoreLives);
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
    settings->setMode(Mode::EasyMode);
    score->settingsModeParameter = 0.1;
}

void Widget::on_rbHard_clicked()
{
    settings->setMode(Mode::HardMode);
    score->settingsModeParameter = 0.15;
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
        bool ok = true;
        QInputDialog diag;
        diag.setWindowTitle("");
        diag.setStyleSheet("font-size: 20px; font-style: bolid italic;");
        setStyleSheet("QInputDialog {background-color: rgb(148, 153, 0);}");

        QString username = diag.getText(this, tr(" "), tr("Username: "), QLineEdit::Normal, "", &ok);

        if(ok && !username.isEmpty()){
            ranglist->addPlayer(username, score->getTotalScore());
            ui->stackedWidget->setCurrentIndex(3);
        }else{
            ui->stackedWidget->setCurrentIndex(0);
        }

        ui->text_rang_list->setText(ranglist->printListToRangList());
        score->reset();
        ui->Give_up->setText("Give up");
    }
}

Widget::~Widget()
{
    delete ui;
    delete levelData;
    delete score;
    delete ranglist;
    delete settings;
}

