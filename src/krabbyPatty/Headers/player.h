#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>

#include "level.h"
#include "playerparameters.h"

class Player:  public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    public:
        Player();
        PlayerParameters *parameters;
        void keyPressEvent(QKeyEvent *event) override;
        void keyReleaseEvent(QKeyEvent *event) override;
        void standOnPlatform(QGraphicsItem *tile);
        bool isDead();
        qreal getVelocityX();
        qreal getVelocityY();
        virtual void advance(int phase) override;
        ~Player();

    signals:
        void countChanged();
        void activeTimer();

    private:
        qreal _velocityX = 0;
        qreal _velocityY = 0;
        bool _isOnGround = true;
        int _stepsCounter = 0;
        void jump();
        void walk();
        void detectCollision();

};

#endif // PLAYER_H
