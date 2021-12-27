#include "regulartile.h"

#include <iostream>

RegularTile::RegularTile(qreal playerWidth, QString imagePath)
{
    qreal width = playerWidth*0.5;
    qreal height = width*0.5;
    setPixmap(QPixmap(imagePath).scaled(width, height));
}

void RegularTile::changeSpeed(Player *player){
    player->changeSpeed(false);
}
