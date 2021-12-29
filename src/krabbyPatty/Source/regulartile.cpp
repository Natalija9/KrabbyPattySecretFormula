#include "Headers/regulartile.h"

RegularTile::RegularTile(qreal playerWidth, QString imagePath)
{
    qreal width = playerWidth * 0.5;
    qreal height = width * 0.5;
    setPixmap(QPixmap(imagePath).scaled(width, height));
}

void RegularTile::changeSpeed(PlayerParameters *playerParameters){
    playerParameters->setSpeed(Speed::Fast);
}
RegularTile::~RegularTile(){

}
