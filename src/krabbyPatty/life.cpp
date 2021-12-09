#include "life.h"

Life::Life(qreal playerWidth, qreal playerHeight)
{
    qreal width = playerWidth * 0.5;
    qreal height = width;
    setPixmap(QPixmap(":images/star.png").scaled(width, height));
    setPos(180, 150);
}
