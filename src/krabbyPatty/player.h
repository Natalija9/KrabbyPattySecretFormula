#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>

class Player:  public QObject, public QGraphicsPixmapItem
{
public:
    Player();
    void keyPressEvent(QKeyEvent *evet);
};

#endif // PLAYER_H
