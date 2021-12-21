#ifndef TILE_H
#define TILE_H
#include "item.h"

class Tile : public QObject, public QGraphicsPixmapItem
{
public:
    Tile(qreal playerWidth, QString imagePath);
};

#endif // TILE_H
