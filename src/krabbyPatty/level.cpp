#include "level.h"
#include "player.h"
#include "life.h"
#include "ingredient.h"
#include "score.h"
#include <QTimer>


#include<QGraphicsScene>
#include<QGraphicsView>
#include <QApplication>

extern Score *score;

Level::Level()
{
    QScreen *screen = QApplication::screens().at(0);
    screenHeight = screen->availableSize().height();
    screenWidth = screen->availableSize().width();

    QGraphicsScene *scene =new QGraphicsScene(0,0,5000,screenHeight);
    mainTimer = new QTimer(this);
    Player *player = new Player();
    player-> setFlag(QGraphicsItem::ItemIsFocusable);

    player ->setFocus();
    QObject::connect(mainTimer, SIGNAL(timeout()), scene, SLOT(advance()));
    mainTimer->start(20);


    Ingredient *ingredient = new Ingredient(player->_width, player->_height);
    Life *life = new Life(player->_width, player->_height);

    scene->addItem(player);
    scene->addItem(ingredient);
    scene->addItem(life);



    this->view = new QGraphicsView(scene);
    view->setBackgroundBrush(QPixmap(":/images/level1.jpeg").scaledToHeight(screenHeight));

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


void Level::center(QGraphicsItem *i){
    this->view->centerOn(i);
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

Level::~Level(){

}




