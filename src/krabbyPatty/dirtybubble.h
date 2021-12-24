#ifndef DIRTYBUBBLE_H
#define DIRTYBUBBLE_H

#include "deadlybarrier.h"

class DirtyBubble : public DeadlyBarrier
{
public:
    DirtyBubble(qreal playerWidth);
    void move() override;

private:
    bool up;
    int steps = 0;
};

#endif // DIRTYBUBBLE_H
