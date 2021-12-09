#include "level.h"
#include "player.h"
#include "life.h"
#include "ingredient.h"
#include <QTimer>


#include<QGraphicsScene>
#include<QGraphicsView>

Level::Level()
{
    QGraphicsScene *scene =new QGraphicsScene(0,0,5000,1000);
    mainTimer = new QTimer(this);
    Player *player = new Player();
    player-> setFlag(QGraphicsItem::ItemIsFocusable);

    player ->setFocus();
    QObject::connect(mainTimer, SIGNAL(timeout()), scene, SLOT(advance()));
    mainTimer->start(20);


    Ingredient *ingredient = new Ingredient();
    Life *life = new Life();

    scene->addItem(player);
    scene->addItem(ingredient);
    scene->addItem(life);



    this->view = new QGraphicsView(scene);
    view->setBackgroundBrush(QPixmap(":/images/level1.jpg"));

    view->ensureVisible(player);
    view->centerOn(player);


    QObject::connect(player, SIGNAL(ingredientPicked()), this, SLOT(increaseScore()));
    QObject::connect(player, SIGNAL(lifePicked()), this, SLOT(increaseLife()));
    QObject::connect(player, SIGNAL(slowingBarrier()), this, SLOT(decreaseScore()));
    QObject::connect(player, SIGNAL(deadlyBarrier()), this, SLOT(death()));


    view->setWindowTitle("level 1");

    view->show();



}


void Level::center(QGraphicsItem *i){
    this->view->centerOn(i);
}

void Level::increaseScore() {

}

void Level::increaseLife() {

}

void Level::decreaseScore() {

}

void Level::death() {

}

Level::~Level(){

}




