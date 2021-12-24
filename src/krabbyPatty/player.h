#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>

#include "level.h"

class Player:  public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    public:
        Player();
        void keyPressEvent(QKeyEvent *event) override;
        void keyReleaseEvent(QKeyEvent *event) override;
        bool isDead();
        qreal _width;
        qreal _height;

    signals:
        void slowingBarrier();
        void deadlyBarrier();
        void countChanged();

    protected:
        virtual void advance(int phase) override;

    private:

        bool _canMove = true;
        bool _isOnGround = true;
        bool _slowed = false;
        qreal _velocityX = 0;
        qreal _velocityY = 1;
        qreal _gravity = 1;
        qreal _stepX = 10;
        qreal _stepY;
        qreal _posY;
        QPolygonF _playerRectPoints;

        void jump();
        void walk();
        void detectCollision();
        void calculateDimension();
        void changeSpeed();

};

#endif // PLAYER_H
