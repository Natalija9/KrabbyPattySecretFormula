#include <QGraphicsScene>
#include <QGraphicsView>
#include <QApplication>
#include <QMessageBox>
#include <QTimer>
#include <QFile>

#include "Headers/level.h"
#include "Headers/player.h"
#include "Headers/life.h"
#include "Headers/ingredient.h"
#include "Headers/score.h"
#include "Headers/regulartile.h"
#include "Headers/flag.h"
#include "Headers/deadlybarrier.h"
#include "Headers/slowingtile.h"

#include <iostream>

extern Score *score;

Level::Level(int levelId, LevelData *levelData)
{
    if(levelId < 1 || levelId > 6)
        throw "Invalid levelId";

    if(levelData == nullptr)
        throw "Invalid levelData";

    this->levelId = levelId;
    this->levelData = levelData;
}

void Level::startLevel(){

    scene = new QGraphicsScene(0, 0, levelData->sceneSizeX, levelData->screenHeight);

    this->setView();

    Player *player = new Player();
    player-> setFlag(QGraphicsItem::ItemIsFocusable);
    player ->setFocus();

    scene->addItem(player);
    view->ensureVisible(player);
    view->centerOn(player);

    playerWidth = player->parameters->_width;
    playerHeight = player->parameters->_height;

    this->parseLevelMap();

    mainTimer = new QTimer(this);
    mainTimer->start(20);

    levelTimer = new QTimer(this);
    levelTimer->start(120000);

    informationBar = new InformationBar(view, levelData->getIngredient(levelId));
    timerLabel = new QLabel(view);
    music = new Sound(levelData->getSound());

    QObject::connect(mainTimer, SIGNAL(timeout()), scene, SLOT(advance()));
    QObject::connect(levelTimer, SIGNAL(timeout()), this, SLOT(outOfTime()));
    QObject::connect(player, SIGNAL(countChanged()), this, SLOT(setInformationBar()));
    QObject::connect(player, SIGNAL(activeTimer()), this, SLOT(updateTimerLabel()));

    QApplication::setOverrideCursor(Qt::BlankCursor);

    view->showFullScreen();
}

void Level::setView(){
    this->view = new QGraphicsView(scene);

    QString path = levelData->getBackground(levelId);
    view->setBackgroundBrush(QPixmap(path).scaledToHeight(levelData->screenHeight));
    view->resize(levelData->screenWidth, levelData->screenHeight);

    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->setWindowTitle(QString::fromStdString("Level " + std::to_string(levelId)));
    view->setFocus();
}


void Level::setInformationBar(){
    informationBar->updateInformation();
}

void Level::updateTimerLabel(){
    timerLabel->setText("time: " + QString::number(levelTimer->remainingTime()/1000) + " s");
    timerLabel->setStyleSheet("font-size: 23px; font: bold;");
    timerLabel->setGeometry(levelData->screenWidth-140, 10, 120, 20);
    timerLabel->show();
}

void Level::finishLevel(MessageText msgText){
    music->stopMusic();
    QApplication::setOverrideCursor(Qt::ArrowCursor);
    if(msgText != MessageText::LevelCompleted)
        score->takeLife();

    score->saveCurrentScore(levelId, levelTimer->remainingTime());
    levelTimer->stop();
    score->msg->setMessageText(msgText);

    this->view->close();

    emit endLevel();
}


void Level::outOfTime() {
    this->finishLevel(MessageText::OutOfTime);
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
    qreal sizeX = line[0].toInt();
    qreal sizeY = line[1].toInt();

    for(int y = 0; y < sizeY; y++){
        QString sceneObjects = in.readLine();
        for( int x = 0; x < sizeX - 1; x++){
            addObject(sceneObjects[x].toLatin1(), x * levelData->sceneSizeX / sizeX, y / sizeY);
        }
    }

    file.close();
}


void Level::addObject(char type, qreal x, qreal y){
    switch(type){
        case '-' :
            break;
    case '*' :{
            if(score->getLives() < 4){
                Life *life = new Life(playerWidth);
                life->setPos(x,  y * levelData->screenHeight + levelData->itemOffset);
                scene->addItem(life);
            }
            break;
    }
    case '_' :{
            RegularTile *tile = new RegularTile(playerWidth,levelData->getTile(levelId));
            tile->setPos(x, y * levelData->screenHeight + levelData->platformOffset);
            scene->addItem(tile);
            break;
    }
    case '$' :{
            Ingredient *ingredient = new Ingredient(playerWidth, levelData->getIngredient(levelId));
            ingredient->setPos(x,  y * levelData->screenHeight + levelData->itemOffset);
            scene->addItem(ingredient);
            break;
    }
    case 'X' :{

            if(levelData->getRandomDecision()){
                DeadlyBarrier *barrier = levelData->getDeadlyBarrier(playerWidth);
                barrier->setPos(x,  y * levelData->screenHeight + levelData->itemOffset);
                scene->addItem(barrier);
            }
            break;

    }
    case 'S' :{

            if(levelData->getRandomDecision()){
                SlowingTile *waterTiles = new SlowingTile(playerWidth, levelData->getSlowingTile(levelId));
                waterTiles->setPos(x, y * levelData->screenHeight + levelData->platformOffset);
                scene->addItem(waterTiles);
            }
            else{
                RegularTile *tile = new RegularTile(playerWidth,levelData->getTile(levelId));
                tile->setPos(x, y * levelData->screenHeight + levelData->platformOffset);
                scene->addItem(tile);
                }
            break;

    }
    case 'B' :{
                SlowingTile *waterTiles = new SlowingTile(playerWidth, levelData->getSlowingTile(levelId));
                waterTiles->setPos(x,  y * levelData->screenHeight + levelData->platformOffset);
                scene->addItem(waterTiles);
            break;
    }
    case '+' :{
            Flag *flag = new Flag(this, playerHeight*1.41);
            flag->setPos(x,  y * levelData->screenHeight + levelData->itemOffset);
            scene->addItem(flag);
            break;
    }
        default :
            break;
    }
}

Level::~Level(){

    QList<QGraphicsItem *> items = scene->items();

    foreach( QGraphicsItem *item, items ){
            scene->removeItem(item);
    }
    items.clear();

    delete this->music;
    delete this->mainTimer;
    delete this->levelTimer;
    delete this->informationBar;
    delete this->timerLabel;

}




