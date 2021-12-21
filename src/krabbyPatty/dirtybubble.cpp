#include "dirtybubble.h"


DirtyBubble::DirtyBubble(qreal playerWidth)
{
    qreal width = playerWidth * 0.75;
    qreal height = width;
    setPixmap(QPixmap(":/images/dirtyBubble.png").scaled(width, height));

    this->up = true;
}

void DirtyBubble::move() {
    if(this->up) {
        setPos(x() + 1, y() - 1);

        steps++;
        if(steps == 60) {
            up = false;
            steps = 0;
        }
    }
    else {
        setPos(x() - 1, y() + 1);

        steps++;
        if(steps == 60) {
            up = true;
            steps = 0;
        }
    }
}
