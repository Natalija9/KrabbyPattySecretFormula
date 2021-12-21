#include "evilspongebob.h"

EvilSpongeBob::EvilSpongeBob(qreal playerWidth)
{
    qreal width = playerWidth;
    qreal height = width;
    setPixmap(QPixmap(":/images/EvilSpongeBob.png").scaled(width, height));

    this->left = true;
    this->up = true;
}

void EvilSpongeBob::move() {
    if(this->left) {
        if(this->up)
            setPos(x() - 2, y() - 2);
        else
            setPos(x() - 2, y() + 2);

        steps++;
        if(steps % 25 == 0)
            up = !up;

        if(steps == 100) {
            left = false;
            steps = 0;
        }
    }
    else {
        if(this->up)
            setPos(x() + 2, y() - 2);
        else
            setPos(x() + 2, y() + 2);

        steps++;
        if(steps % 25 == 0)
            up = !up;
        if(steps == 100) {
            left = true;
            steps = 0;
        }
    }
}
