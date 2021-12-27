#include "slowingtile.h"
#include <iostream>

SlowingTile::SlowingTile(qreal playerWidth, QString imagePath)
{
    qreal width = playerWidth*0.5;
    qreal height = width*0.5;
    setPixmap(QPixmap(imagePath).scaled(width, height));
}

void SlowingTile::changeSpeed(Player *player){
    player->changeSpeed(true);
}
