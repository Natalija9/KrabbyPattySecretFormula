#include<QGraphicsScene>
#include<QGraphicsView>
#include <QApplication>
#include <QMessageBox>
#include <QTimer>
#include <QFile>

#include "level.h"
#include "player.h"
#include "life.h"
#include "ingredient.h"
#include "score.h"
#include "tile.h"
#include "flag.h"
#include "deadlybarrier.h"

#include <iostream>




extern Score *score;

Level::Level(int levelId, LevelData *levelData)
{

    this->levelId = levelId;
    this->levelData = levelData;

}

void Level::startLevel(){

    std::cout << "level:" << levelId << std::endl;
    QScreen *screen = QApplication::screens().at(0);
    screenHeight = screen->size().height();
    screenWidth = screen->size().width();

    scene =new QGraphicsScene(0,0,5 * screenWidth ,screenHeight);
    mainTimer = new QTimer(this);
    Player *player = new Player();
    player-> setFlag(QGraphicsItem::ItemIsFocusable);

    player ->setFocus();
    QObject::connect(mainTimer, SIGNAL(timeout()), scene, SLOT(advance()));
    mainTimer->start(20);

    levelTimer = new QTimer(this);
    levelTimer->start(120000);
    QObject::connect(levelTimer, SIGNAL(timeout()), this, SLOT(outOfTime()));


    playerWidth = player->_width;
    playerHeight = player->_height;

    scene->addItem(player);
    parseLevelMap();

    this->view = new QGraphicsView(scene);

    QString path = levelData->getBackground(levelId);
    view->setBackgroundBrush(QPixmap(path).scaledToHeight(screenHeight));

    view->resize(screenWidth,screenHeight);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->ensureVisible(player);
    view->centerOn(player);


    QObject::connect(player, SIGNAL(ingredientPicked()), this, SLOT(increaseScore()));
    QObject::connect(player, SIGNAL(lifePicked()), this, SLOT(increaseLife()));
    QObject::connect(player, SIGNAL(slowingBarrier()), this, SLOT(decreaseScore()));
    QObject::connect(player, SIGNAL(deadlyBarrier()), this, SLOT(death()));


    view->setWindowTitle(QString::fromStdString("Level " + std::to_string(levelId)));

    view->setFocus();
    view->showFullScreen();

}

void Level::finishLevel(){
//    std::cout << "life: " <<score->getLives() << std::endl;
    score->saveCurrentScore(levelId);
    score->saveCurrentTime(levelId, levelTimer->interval() - levelTimer->remainingTime());
    levelTimer->stop();
    this->view->close();

    emit endLevel();
}

void Level::increaseScore() {
    score->increase();
}

void Level::increaseLife() {
    score->addLife();
}

void Level::decreaseScore() {
    score->decrease();
}

void Level::death() {
    score->takeLife();
    QMessageBox msgBox;
    msgBox.setText("Ooops, you lost a life!");
    msgBox.setWindowTitle(" ");
    msgBox.setStyleSheet("font-size: 20px; font-style: bolid italic;  color: rgb(0, 0, 0);");
    msgBox.exec();

    this->finishLevel();

}

void Level::outOfTime() {
    score->takeLife();
    QMessageBox msgBox;
    msgBox.setText("Ooops, you ran out of time!");
    msgBox.setWindowTitle("No more time");
    msgBox.setStyleSheet("font-size: 20px; font-style: bolid italic;  color: rgb(0, 0, 0);");
    msgBox.exec();

    this->finishLevel();

}

void Level::parseLevelMap(){
    QFile file(levelData->getLevelMap(levelId));
    if(!file.exists()){
        qDebug() << "File does not exist";
        return ;
    }
    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << "Opening failed";
        return ;
    }

    QTextStream in(&file);
    QStringList line = in.readLine().split(" ");
    int sizeX = line[0].toInt();
    int sizeY = line[1].toInt();

    for(int y = 0; y < sizeY; y++){
        QString sceneObjects = in.readLine();
        for( int x = 0; x < sizeX - 1; x++){
            addObject(sceneObjects[x].toLatin1(), x*screenWidth*5/200,y);
        }
    }

    file.close();
}
void Level::addObject(char type, int x,int y){
    switch(type){
        case '-' :
            break;
    case '*' :{
            Life *life = new Life(playerWidth);
            life->setPos(x, (0.225 + y * 0.25 )*screenHeight);
            scene->addItem(life);
            break;
    }
    case '_' :{
            Tile *tile = new Tile(playerWidth);
            tile->setPos(x, (0.1 + y * 0.25)*screenHeight);
            scene->addItem(tile);
            break;
    }
    case '$' :{
            Ingredient *ingredient = new Ingredient(playerWidth, levelData->getIngredient(levelId));
            ingredient->setPos(x, (0.225 + y * 0.25 )*screenHeight);
            scene->addItem(ingredient);
            break;
    }
    case 'X' :{
            DeadlyBarrier *jellyfish = new DeadlyBarrier(playerWidth, levelData->getDeadlyBarrier());
            jellyfish->setPos(x, (0.225 + y * 0.25 )*screenHeight);
            scene->addItem(jellyfish);
            break;
    }
    case '+' :{
            Flag *flag = new Flag(playerHeight*1.41);
            flag->setPos(x, (0.225 + y * 0.23 )*screenHeight);
            scene->addItem(flag);
            break;
    }
        default :
            break;
    }
}

Level::~Level(){
    std::cout << score->getLevelTime(levelId) / 1000 << "s" << std::endl;
}




