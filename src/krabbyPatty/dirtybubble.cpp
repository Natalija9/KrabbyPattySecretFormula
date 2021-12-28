#include "dirtybubble.h"


DirtyBubble::DirtyBubble(qreal playerWidth)
{
    qreal width = playerWidth * 0.75;
    qreal height = width;
    setPixmap(QPixmap(":/images/dirtyBubble.png").scaled(width, height));

}

void DirtyBubble::move()
{
    stepForward();
    changeDirectionIfNeeded();
}

void DirtyBubble::stepForward()
{
    setPos(x() + move_x, y() + move_y);
    steps++;
}

void DirtyBubble::changeDirectionIfNeeded()
{
    if(steps == max_steps) {
        steps = 0;
        move_x = -move_x;
        move_y = -move_y;
    }
}

