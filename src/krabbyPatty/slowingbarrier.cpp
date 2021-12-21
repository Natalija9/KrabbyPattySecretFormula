#include "slowingbarrier.h"

SlowingBarrier::SlowingBarrier(qreal playerWidth, QString imagePath)
{
    qreal width = playerWidth*0.5;
    qreal height = width*0.5;
    setPixmap(QPixmap(imagePath).scaled(width, height));
}
