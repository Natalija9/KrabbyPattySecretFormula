#include "player.h"
#include <thread>
#include <QKeyEvent>
#include <iostream>
#include "level.h"
#include "ingredient.h"
#include "life.h"
#include "slowingbarrier.h"
#include "deadlybarrier.h"
#include "tile.h"
#include "flag.h"

#include<QApplication>
#include<QTimer>

extern Level *level;

Player::Player()
{
    calculateDimension();
    setPixmap(QPixmap(":images/player.png").scaled(_width, _height));
    setPos(100, posY);

}

void Player::keyPressEvent(QKeyEvent *event){

    if(event->key() == Qt::Key_Right){
        setPixmap(QPixmap(":images/playerRight.png").scaled(_width, _height));
        m_velocityX = stepX;
    }if(event->key() == Qt::Key_Left){
        setPixmap(QPixmap(":images/playerLeft.png").scaled(_width, _height));
        m_velocityX = -stepX;
    }if(event->key() == Qt::Key_Up && m_isOnGround){
        m_velocityY = -stepY;
        setPos(x(), y() + m_velocityY);
        m_isOnGround = false;
    }


}
void Player::keyReleaseEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Right){
        m_velocityX = 0;
        setPixmap(QPixmap(":images/player.png").scaled(_width, _height));
    }
    if(event->key() == Qt::Key_Left){
        m_velocityX = 0;
        setPixmap(QPixmap(":images/player.png").scaled(_width, _height));
    }
}


void Player::advance(int phase)
{

    if(!phase){
        return;
    }

    if(isDead()){
        level->death();
    }
    else{
        level->view->centerOn(this);
    }

    if(m_canMove)
    {
        walk();
    }
    jump();
    detectCollision();


}

void Player::jump()
{

    if(!m_isOnGround)
    {

        if(m_velocityY < 10)
            m_velocityY += m_gravity;

         setPos(x(), y() + m_velocityY);
    }
}


void Player::walk()
{
    setPos(x() + m_velocityX, y());
}


void Player::detectCollision() {

    QList<QGraphicsItem *> colliding_items = collidingItems();

    if(colliding_items.size())
    {
        for (auto &colliding_item : colliding_items)
        {
            if (typeid(*(colliding_item)) == typeid(Flag))
            {
                level->finishLevel();
            }
            if (typeid(*(colliding_item)) == typeid(Ingredient))
            {
                scene()->removeItem(colliding_item);
                emit ingredientPicked();
            }
            if (typeid(*(colliding_item)) == typeid(Life))
            {
                scene()->removeItem(colliding_item);
                emit lifePicked();
            }
            if (typeid(*(colliding_item)) == typeid(SlowingBarrier))
            {
                emit slowingBarrier();
            }
            if (typeid(*(colliding_item)) == typeid(DeadlyBarrier))
            {
                emit deadlyBarrier();
            }
            if (typeid(*(colliding_item)) == typeid(Tile))
             {

                QRectF tileRect          = colliding_item->boundingRect();
                QPolygonF tileRectPoints = colliding_item->mapToScene(tileRect);

                m_playerRectPoints = mapToScene(boundingRect());
                // 0 1
                // 3 2

                if(m_playerRectPoints[2].y() <= tileRectPoints[0].y() + 22)
                {
                   m_isOnGround = true;
                }   // stoji na platformi
                else if(!m_isOnGround && m_playerRectPoints[3].x() <= tileRectPoints[3].x() - 25 &&
                        m_playerRectPoints[1].y() <= tileRectPoints[3].y() - 20)
                {
                   setPos(x() - 8, y());
                }   // sa leve strane
                else if(!m_isOnGround && m_playerRectPoints[2].x() >= tileRectPoints[2].x() + 25 &&
                        m_playerRectPoints[1].y() <= tileRectPoints[3].y() - 20)
                {
                    setPos(x() + 8, y());
                }   // sa desne strane
                 if(!m_isOnGround && m_playerRectPoints[1].y() <= tileRectPoints[3].y() + 5 &&
                     m_playerRectPoints[2].x() > tileRectPoints[3].x() + 2 &&
                     m_playerRectPoints[3].x() < tileRectPoints[2].x() - 2)
                {
                        m_velocityY = 5;
                }
             }
        }
    }
    else
        {
            m_isOnGround = false;
        }


}

bool Player::isDead(){
    return y() > level->screenHeight;
}

void Player::calculateDimension(){
    QScreen *screen = QApplication::screens().at(0);
    qreal screenHeight = screen->availableSize().height();


    _height = screenHeight * 0.2;
    _width = _height * 0.7;
    stepY = _height *0.13;
    m_gravity = 0.05 *stepY;
    posY = screenHeight * 0.65;
}
