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
    setPos(100, _posY);

}

void Player::keyPressEvent(QKeyEvent *event){

    if(event->key() == Qt::Key_Escape){
        level->finishLevel(MessageText::Esc);
    }
    if(event->key() == Qt::Key_Right){
        setPixmap(QPixmap(":images/playerRight.png").scaled(_width, _height));
        _velocityX = _stepX;
    }if(event->key() == Qt::Key_Left){
        setPixmap(QPixmap(":images/playerLeft.png").scaled(_width, _height));
        _velocityX = -_stepX;
    }if(event->key() == Qt::Key_Up && _isOnGround){
        if(!_slowed){
            _velocityY = -_stepY;
            setPos(x(), y() + _velocityY);
            _isOnGround = false;
        }
        else{
            event->ignore();
        }
    }
}

void Player::keyReleaseEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Right){
        _velocityX = 0;
        setPixmap(QPixmap(":images/player.png").scaled(_width, _height));
    }
    if(event->key() == Qt::Key_Left){
        _velocityX = 0;
        setPixmap(QPixmap(":images/player.png").scaled(_width, _height));
    }
}


void Player::advance(int phase)
{

    if(!phase){
        return;
    }

    if(isDead()){
        level->finishLevel(MessageText::LostLife);
    }
    else{
        level->view->centerOn(this);
    }

    if(_canMove)
    {
        walk();
    }
    jump();
    detectCollision();

    emit activeTimer();
}

void Player::jump()
{

    if(!_isOnGround)
    {
        if(_velocityY < 10)
            _velocityY += _gravity;

         setPos(x(), y() + _velocityY);
    }
}


void Player::walk()
{

    if(_velocityX > 0 && _isOnGround){
        _tmp ++;
        if(_tmp <= 4){
            setPixmap(QPixmap(":images/playerRight1.png").scaled(_width, _height));
            show();
        }else if(_tmp <= 8){
            setPixmap(QPixmap(":images/playerRight2.png").scaled(_width, _height));
            show();
        }
    }else if(_velocityX < 0 && _isOnGround){
        _tmp ++;
        if(_tmp <= 4){
            setPixmap(QPixmap(":images/playerLeft1.png").scaled(_width, _height));
            show();
        }else if(_tmp <= 8){
            setPixmap(QPixmap(":images/playerLeft2.png").scaled(_width, _height));
            show();
        }
    }
    if(_tmp == 8)
        _tmp = 0;
    setPos(x() + _velocityX, y());
}


void Player::detectCollision() {

    QList<QGraphicsItem *> colliding_items = collidingItems();

    if(colliding_items.size())
    {
        for (auto &colliding_item : colliding_items)
        {
            if (typeid(*(colliding_item)) == typeid(Flag))
            {
                level->finishLevel(MessageText::LevelCompleted);
            }
            if(dynamic_cast<Item*>(colliding_item))
            {
                dynamic_cast<Item*>(colliding_item)->collect();
                scene()->removeItem(colliding_item);

                emit countChanged();
            }
            if (typeid(*(colliding_item)) == typeid(SlowingBarrier))
            {
                _slowed = true;
                changeSpeed();
                _isOnGround = true;
                emit slowingBarrier();
            }
            if (dynamic_cast<DeadlyBarrier*>(colliding_item))
            {
                level->finishLevel(MessageText::LostLife);
            }
            if (typeid(*(colliding_item)) == typeid(Tile))
             {
                _slowed = false;
                changeSpeed();

                QRectF tileRect          = colliding_item->boundingRect();
                QPolygonF tileRectPoints = colliding_item->mapToScene(tileRect);

                _playerRectPoints = mapToScene(boundingRect());
                // 0 1
                // 3 2

                if(_playerRectPoints[2].y() <= tileRectPoints[0].y() + 22) // on the platform
                {
                   _isOnGround = true;
                }
                else if(!_isOnGround && _playerRectPoints[3].x() <= tileRectPoints[3].x() - 25 &&
                        _playerRectPoints[1].y() <= tileRectPoints[3].y() - 20) // on the left side
                {
                   setPos(x() - 8, y());
                }

                else if(!_isOnGround && _playerRectPoints[2].x() >= tileRectPoints[2].x() + 25 &&
                        _playerRectPoints[1].y() <= tileRectPoints[3].y() - 20) // on the right side
                {
                    setPos(x() + 8, y());
                }
                 if(!_isOnGround && _playerRectPoints[1].y() <= tileRectPoints[3].y() + 5 &&
                     _playerRectPoints[2].x() > tileRectPoints[3].x() + 2 &&
                     _playerRectPoints[3].x() < tileRectPoints[2].x() - 2) // under the platform
                {
                        _velocityY = 5;
                }
             }
        }
    }
    else
        {
            _isOnGround = false;
        }


}
void Player::changeSpeed(){
    if(_slowed){
        _stepX = 3;
    }else{
        _stepX = 8;
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
    _stepY = _height *0.13;
    _gravity = 0.05 *_stepY;
    _posY = screenHeight * 0.65;
}
