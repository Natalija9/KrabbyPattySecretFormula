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
        void standOnPlatform(QGraphicsItem *tile);
        qreal _width;
        qreal _height;
        void changeSpeed(bool slowed);

    signals:
        void slowingBarrier();
        void countChanged();
        void activeTimer();

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
        int _tmp = 0;
        void jump();
        void walk();
        void detectCollision();
        void calculateDimension();

};

#endif // PLAYER_H
