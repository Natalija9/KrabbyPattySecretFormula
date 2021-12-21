#include "karen.h"


Karen::Karen(qreal playerWidth)
{
    qreal width = playerWidth * 0.75;
    qreal height = width * 1.3;
    setPixmap(QPixmap(":/images/karen.png").scaled(width, height));

    this->left = true;
}

void Karen::move() {
    if(this->left) {
        setPos(x() - 2, y());

        steps++;
        if(steps == 100) {
            left = false;
            steps = 0;
        }
    }
    else {
        setPos(x() + 2, y());

        steps++;
        if(steps == 100) {
            left = true;
            steps = 0;
        }
    }
}
