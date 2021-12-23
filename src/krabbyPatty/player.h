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
        void ingredientPicked();
        void lifePicked();
        void slowingBarrier();
        void deadlyBarrier();
        void healthChanged();
        void ingredientChanged();

    protected:
        virtual void advance(int phase) override;



    private:
        bool isOnGround(Player *p);
        void jump();
        void walk();
        void detectCollision();
        void calculateDimension();
        void changeSpeed();
        qreal m_velocityX = 0;
        qreal m_velocityY = 1;
        qreal m_gravity = 1;
        bool m_canMove    = true;
        bool m_isOnGround = true;
        qreal stepX = 8;
        qreal stepY;
        qreal posY;
        QPolygonF m_playerRectPoints;
        bool m_slowed = false;
};

#endif // PLAYER_H
