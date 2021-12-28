#ifndef KAREN_H
#define KAREN_H

#include "deadlybarrier.h"


class Karen : public DeadlyBarrier
{
public:
    Karen(qreal playerWidth);
    void move() override;

private:
    int steps = 0;
    const int max_steps = 100;
    int move_x = 2;
    void stepForward();
    void changeDirectionIfNeeded();
};

#endif // KAREN_H
