#ifndef KAREN_H
#define KAREN_H

#include "deadlybarrier.h"


class Karen : public DeadlyBarrier
{
public:
    Karen(qreal playerWidth);
    void move() override;

private:
    bool left;
    int steps = 0;
};

#endif // KAREN_H
