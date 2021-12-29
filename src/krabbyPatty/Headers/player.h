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
        void keyPressEvent(QKeyEvent *event) override;
        void keyReleaseEvent(QKeyEvent *event) override;
        bool isDead();
        void standOnPlatform(QGraphicsItem *tile);
        PlayerParameters *parameters;

        ~Player();
    signals:
        void slowingBarrier();
        void countChanged();
        void activeTimer();

    protected:
        virtual void advance(int phase) override;

    private:
        bool _isOnGround = true;
        qreal _velocityX = 0;
        qreal _velocityY = 0;
        int _stepsCounter = 0;
        void jump();
        void walk();
        void detectCollision();

};

#endif // PLAYER_H
