#include "flag.h"

Flag::Flag(qreal playerWidth)
{
    qreal width = playerWidth * 0.5;
    qreal height = width;
    setPixmap(QPixmap(":images/flag.png").scaled(width, height));
}
