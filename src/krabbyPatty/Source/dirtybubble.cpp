#include "Headers/dirtybubble.h"


DirtyBubble::DirtyBubble(qreal playerWidth){
    this->width = playerWidth * 0.75;
    this->height = width;
    setPixmap(QPixmap(":/images/dirtyBubble.png").scaled(width, height));

}

void DirtyBubble::move(){
    stepForward();
    changeDirectionIfNeeded();
}

void DirtyBubble::stepForward(){
    setPos(x() + move_x, y() - move_y);
    steps++;
}

void DirtyBubble::changeDirectionIfNeeded(){
    if(steps == max_steps) {
        steps = 0;
        move_x = -move_x;
        move_y = -move_y;
    }
}

qreal DirtyBubble::getWidth(){
    return this->width;
}

qreal DirtyBubble::getHeight(){
    return this->height;
}
DirtyBubble::~DirtyBubble(){}

