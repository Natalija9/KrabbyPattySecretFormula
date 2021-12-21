#include "life.h"
#include "score.h"

extern Score *score;

Life::Life(qreal playerWidth)
{
    qreal width = playerWidth * 0.5;
    qreal height = width;
    setPixmap(QPixmap(":images/star.png").scaled(width, height));
}

void Life::collect(){
    score->addLife();
}
