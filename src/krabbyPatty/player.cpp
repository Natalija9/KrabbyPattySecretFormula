#include "player.h"
#include <thread>
#include <QKeyEvent>
#include <iostream>
#include "level.h"
#include "ingredient.h"
#include "life.h"
#include "slowingtile.h"
#include "deadlybarrier.h"
#include "regulartile.h"
#include "flag.h"

#include<QApplication>
#include<QTimer>

extern Level *level;

Player::Player()
{
    parameters = new PlayerParameters();
    setPixmap(QPixmap(":images/player.png").scaled(parameters->_width, parameters->_height));
    setPos(parameters->_posX, parameters->_posY);

}

void Player::keyPressEvent(QKeyEvent *event){

    if(event->key() == Qt::Key_Escape){
        level->finishLevel(MessageText::Esc);
    }
    if(event->key() == Qt::Key_Right){
        setPixmap(QPixmap(":images/playerRight1.png").scaled(parameters->_width, parameters->_height));
        _velocityX = parameters->_stepX;
    }if(event->key() == Qt::Key_Left){
        setPixmap(QPixmap(":images/playerLeft1.png").scaled(parameters->_width, parameters->_height));
        _velocityX = - parameters->_stepX;
    }if(event->key() == Qt::Key_Up && _isOnGround){
        if(parameters->getSpeed() == Speed::Fast){
            _velocityY = - parameters->_stepY;
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
        setPixmap(QPixmap(":images/player.png").scaled(parameters->_width, parameters->_height));
    }
    if(event->key() == Qt::Key_Left){
        _velocityX = 0;
        setPixmap(QPixmap(":images/player.png").scaled(parameters->_width, parameters->_height));
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

    walk();
    jump();
    detectCollision();

    emit activeTimer();
}

void Player::jump()
{

    if(!_isOnGround)
    {
        if(_velocityY < 10)
            _velocityY += parameters->_gravity;

         setPos(x(), y() + _velocityY);
    }
}


void Player::walk()
{

    if(_velocityX > 0 && _isOnGround){
        _stepsCounter ++;
        if(_stepsCounter <= 4){
            setPixmap(QPixmap(":images/playerRight1.png").scaled(parameters->_width, parameters->_height));
            show();
        }else if(_stepsCounter <= 8){
            setPixmap(QPixmap(":images/playerRight2.png").scaled(parameters->_width, parameters->_height));
            show();
        }
    }else if(_velocityX < 0 && _isOnGround){
        _stepsCounter ++;
        if(_stepsCounter <= 4){
            setPixmap(QPixmap(":images/playerLeft1.png").scaled(parameters->_width, parameters->_height));
            show();
        }else if(_stepsCounter <= 8){
            setPixmap(QPixmap(":images/playerLeft2.png").scaled(parameters->_width, parameters->_height));
            show();
        }
    }
    if(_stepsCounter == 8)
        _stepsCounter = 0;
    setPos(x() + _velocityX, y());
}


void Player::detectCollision() {

    QList<QGraphicsItem *> colliding_items = collidingItems();

    if(colliding_items.size())
{
        for (auto &colliding_item : colliding_items)
        {
            if(dynamic_cast<Item*>(colliding_item)){
                dynamic_cast<Item*>(colliding_item)->collect();
                scene()->removeItem(colliding_item);

                emit countChanged();
            }
            else if (dynamic_cast<DeadlyBarrier*>(colliding_item))
            {
                level->finishLevel(MessageText::LostLife);
            }
            else if(dynamic_cast<Tile*>(colliding_item))
            {
                dynamic_cast<Tile*>(colliding_item)->changeSpeed(parameters);

                this->standOnPlatform(colliding_item);
            }
        }
    }
    else
        {
            _isOnGround = false;
        }
}


void Player::standOnPlatform(QGraphicsItem *tile){

    QRectF tileRect          = tile->boundingRect();
    QPolygonF tileRectPoints = tile->mapToScene(tileRect);

    QPolygonF _playerRectPoints = mapToScene(boundingRect());
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


bool Player::isDead(){
    return y() > level->screenHeight;
}

