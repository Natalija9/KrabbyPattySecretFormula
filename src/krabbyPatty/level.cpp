#include "level.h"
#include "player.h"


#include<QGraphicsScene>
#include<QGraphicsView>

Level::Level()
{
    QGraphicsScene *scene =new QGraphicsScene(0,0,1000,500);

    Player *player = new Player();
    player-> setFlag(QGraphicsItem::ItemIsFocusable);

    player ->setFocus();

    scene->addItem(player);



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


