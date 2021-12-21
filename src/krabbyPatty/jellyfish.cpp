#include "jellyfish.h"
#include <cstdlib>

Jellyfish::Jellyfish(qreal playerWidth)
{
    qreal width = playerWidth * 0.5;
    qreal height = width;

    int x = rand() % 2;

    if (x == 0)
        setPixmap(QPixmap(":/images/jellyfish.png").scaled(width, height));
    else
        setPixmap(QPixmap(":/images/jellyfish_blue.png").scaled(width, height));

    this->up = true;
}

void Jellyfish::move() {
    if(this->up) {
        setPos(x(), y() - 1);

        steps++;
        if(steps == 60) {
            up = false;
            steps = 0;
        }
    }
    else {
        setPos(x(), y() + 1);

        steps++;
        if(steps == 60) {
            up = true;
            steps = 0;
        }
    }
}
