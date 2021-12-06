#include "level.h"
#include "player.h"
#include "life.h"
#include "ingredient.h"
#include <QTimer>

#include<QGraphicsScene>
#include<QGraphicsView>

Level::Level()
{
    QGraphicsScene *scene =new QGraphicsScene(0,0,1000,5000);
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



    QGraphicsView *view = new QGraphicsView(scene);
    view->setBackgroundBrush(QPixmap(":/images/level1.jpg"));


    //view->resize(500,500);
    view->ensureVisible(player);
    view->centerOn(player);



    view->setWindowTitle("level 1");

    view->show();
}
Level::~Level(){}

void Level::start(){


}

//void nivo::keyPressEvent(QKeyEvent *event){
//    if(event->key() == Qt::Key_Escape){
//        event->accept();
//    }
//}


