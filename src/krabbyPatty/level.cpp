#include "level.h"
#include "player.h"
#include "life.h"
#include "ingredient.h"
#include "score.h"
#include <QTimer>
#include <QFile>
#include "tile.h"
#include <iostream>

#include<QGraphicsScene>
#include<QGraphicsView>
#include <QApplication>

extern Score *score;

Level::Level()
{
    QScreen *screen = QApplication::screens().at(0);
    screenHeight = screen->availableSize().height();
    screenWidth = screen->availableSize().width();

    scene =new QGraphicsScene(0,0,5 * screenWidth ,screenHeight);
    mainTimer = new QTimer(this);
    Player *player = new Player();
    player-> setFlag(QGraphicsItem::ItemIsFocusable);

    player ->setFocus();
    QObject::connect(mainTimer, SIGNAL(timeout()), scene, SLOT(advance()));
    mainTimer->start(20);

    playerWidth = player->_width;
    playerHeight = player->_height;

    scene->addItem(player);
    parseLevelMap(":/LevelMaps/level1.txt");

    this->view = new QGraphicsView(scene);
    view->setBackgroundBrush(QPixmap(":/images/level1.jpg").scaledToHeight(screenHeight));

    view->resize(screenWidth,screenHeight);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->ensureVisible(player);
    view->centerOn(player);


    QObject::connect(player, SIGNAL(ingredientPicked()), this, SLOT(increaseScore()));
    QObject::connect(player, SIGNAL(lifePicked()), this, SLOT(increaseLife()));
    QObject::connect(player, SIGNAL(slowingBarrier()), this, SLOT(decreaseScore()));
    QObject::connect(player, SIGNAL(deadlyBarrier()), this, SLOT(death()));


    view->setWindowTitle("level 1");

    view->show();



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
}

void Level::parseLevelMap(QString filePath){
    QFile file(filePath);
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
            Ingredient *ingredient = new Ingredient(playerWidth);
            ingredient->setPos(x, (0.225 + y * 0.25 )*screenHeight);
            scene->addItem(ingredient);
            break;
    }
        default :
            break;
    }
}

Level::~Level(){

}




