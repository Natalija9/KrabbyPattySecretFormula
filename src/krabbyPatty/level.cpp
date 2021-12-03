#include "level.h"
#include "player.h"


#include<QGraphicsScene>
#include<QGraphicsView>

Level::Level()
{

}
Level::~Level(){}

void Level::start(){
    QGraphicsScene *scene =new QGraphicsScene(0,0,1000,500);



    Player *player = new Player();

    scene->addItem(player);

    player-> setFlag(QGraphicsItem::ItemIsFocusable);
    player ->setFocus();
    centerOn(player);
    QGraphicsView *view = new QGraphicsView(scene);
    view->setBackgroundBrush(QPixmap(":/images/level1.jpg"));


    view->setWindowTitle("level 1");

    view->show();

}
//void nivo::keyPressEvent(QKeyEvent *event){
//    if(event->key() == Qt::Key_Escape){
//        event->accept();
//    }
//}


