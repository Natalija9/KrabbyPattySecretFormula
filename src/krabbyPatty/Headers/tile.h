#ifndef TILE_H
#define TILE_H

#include <QGraphicsPixmapItem>
#include "playerparameters.h"

class Tile : QObject, public QGraphicsPixmapItem
{
public:
    Tile();
    virtual void changeSpeed(PlayerParameters *playerParameters) = 0;
    ~Tile();
};

#endif // TILE_H
