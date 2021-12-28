#include "karen.h"


Karen::Karen(qreal playerWidth)
{
    qreal width = playerWidth * 0.75;
    qreal height = width * 1.3;
    setPixmap(QPixmap(":/images/karen.png").scaled(width, height));
}

void Karen::move()
{
    stepForward();
    changeDirectionIfNeeded();
}

void Karen::stepForward()
{
    setPos(x() - move_x, y());
    steps++;
}

void Karen::changeDirectionIfNeeded()
{
    if(steps == max_steps) {
        steps = 0;
        move_x = -move_x;
    }
}

