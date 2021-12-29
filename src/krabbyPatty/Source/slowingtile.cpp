#include "Headers/slowingtile.h"

SlowingTile::SlowingTile(qreal playerWidth, QString imagePath)
{
    qreal width = playerWidth*0.5;
    qreal height = width*0.5;
    setPixmap(QPixmap(imagePath).scaled(width, height));
}

void SlowingTile::changeSpeed(PlayerParameters *playerParameters){
    playerParameters->setSpeed(Speed::Slow);
}

SlowingTile::~SlowingTile(){

}
