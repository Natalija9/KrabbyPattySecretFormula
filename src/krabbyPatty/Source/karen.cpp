#include "Headers/karen.h"


Karen::Karen(qreal playerWidth)
{
    width = playerWidth * 0.75;
    height = width * 1.3;
    setPixmap(QPixmap(":/images/karen.png").scaled(width, height));
}

qreal Karen::getWidth(){
    return width;
}
qreal Karen::getHeight(){
    return height;
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

Karen::~Karen(){

}
