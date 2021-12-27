#ifndef TILE_H
#define TILE_H

#include <QGraphicsPixmapItem>
#include "player.h"

class Tile : QObject, public QGraphicsPixmapItem
{
public:
    Tile();
    virtual void changeSpeed(Player *player) = 0;
};

#endif // TILE_H
