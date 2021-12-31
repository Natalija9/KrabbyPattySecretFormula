#ifndef EVILSPONGEBOB_H
#define EVILSPONGEBOB_H

#include "deadlybarrier.h"


class EvilSpongeBob : public DeadlyBarrier
{
public:
    EvilSpongeBob(qreal playerWidth);
    void move() override;
    qreal getWidth();
    qreal getHeight();
    ~EvilSpongeBob();

private:
    qreal width = 0;
    qreal height = 0;
    bool left;
    int move_x = 2;
    int move_y = 2;
    int steps = 0;
    const int max_steps = 100;
    const int changeVertical = 25;
    void moveVertically();
    void stepForward();
    void changeVerticalDirectionIfNeeded();
    void changeHorizontalDirectionIfNeeded();
};


#endif // EVILSPONGEBOB_H
