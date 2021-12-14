#include "tile.h"

#include <iostream>
Tile::Tile(qreal playerWidth)
{
    qreal width = playerWidth*0.5;
    qreal height = width*0.5;
    setPixmap(QPixmap(":images/tile.png").scaled(width, height));
}
