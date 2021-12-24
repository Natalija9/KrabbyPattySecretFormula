#include "tile.h"

#include <iostream>

Tile::Tile(qreal playerWidth, QString imagePath)
{
    qreal width = playerWidth*0.5;
    qreal height = width*0.5;
    setPixmap(QPixmap(imagePath).scaled(width, height));
}
