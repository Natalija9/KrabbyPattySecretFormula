#include "player.h"

#include <QKeyEvent>


Player::Player()
{
    setPixmap(QPixmap(":images/player.png").scaled(100,100));
    setPos(100, 100);

}

void Player::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Right){
        setPos(x()+10,y());
    }if(event->key() == Qt::Key_Left){
        setPos(x()-10,y());
    }if(event->key() == Qt::Key_Up){
        setPos(x(),y() - 10);
    }
}


