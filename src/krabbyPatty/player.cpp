#include "player.h"
#include <thread>
#include <QKeyEvent>
#include<iostream>

#include "level.h"

extern Level *level;

Player::Player()
{
    setPixmap(QPixmap(":images/player.png").scaled(70,100));
    setPos(100, 275);
}

void Player::keyPressEvent(QKeyEvent *event){

    if(event->key() == Qt::Key_Right){
        setPixmap(QPixmap(":images/playerRight.png").scaled(70,100));
        setPos(x()+10,y());

    }if(event->key() == Qt::Key_Left){
        setPixmap(QPixmap(":images/playerLeft.png").scaled(70,100));
        setPos(x()-10,y());
    }if(event->key() == Qt::Key_Up && m_isOnGround)
    {
        m_velocityY = -15;
        setPos(x(), y() + m_velocityY);
        m_isOnGround = false;
    }


}
void Player::keyReleaseEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Right){
        setPixmap(QPixmap(":images/player.png").scaled(70,100));
        setPos(x(),y());
    }
    if(event->key() == Qt::Key_Left){
        setPixmap(QPixmap(":images/player.png").scaled(70,100));
        setPos(x(),y());
    }
}


void Player::advance(int phase)
{

    QGraphicsItem::advance(phase);
    if(m_canMove)
    {
        walk();
    }
    jump();
    level->centerOn(this);
}
void Player::jump()
{

    if(!m_isOnGround)
    {
//        if(y() < 0) // player is hitting the top of the scene
//        {
//            setPos(x(), 0);
//            m_velocityY = 5;
//        }

       // m_velocityY = 3;

        if(m_velocityY < 10)
            m_velocityY += m_gravity;

         setPos(x(), y() + m_velocityY);
         //m_isOnGround = true;
    }
    if(isOnGround(this))
        m_isOnGround = true;

    level->centerOn(this);
}
bool Player::isOnGround(Player *p){
    if(p->y() >=275)
        return true;
return false;
}
void Player::walk()
{
    setPos(x() + m_velocityX, y());

    level->centerOn(this);
}

