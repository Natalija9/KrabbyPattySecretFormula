#include "deadlybarrier.h"

DeadlyBarrier::DeadlyBarrier(qreal playerWidth, QString imagePath)
{
    qreal width = playerWidth * 0.5;
    qreal height = width;
    setPixmap(QPixmap(imagePath).scaled(width, height));
}
