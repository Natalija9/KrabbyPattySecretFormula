#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>

#include "level.h"

class Player:  public QObject, public QGraphicsPixmapItem
{
    public:
        Player();
        void keyPressEvent(QKeyEvent *event) override;
        void keyReleaseEvent(QKeyEvent *event) override;

    protected:
        virtual void advance(int phase) override;
    private:
        bool isOnGround(Player *p);
        void jump();
        void walk();
        qreal m_velocityX = 0;
        qreal m_velocityY = 1;
        qreal m_gravity   = 1;
        bool m_canMove    = true;
        bool m_isOnGround = true;
};

#endif // PLAYER_H
