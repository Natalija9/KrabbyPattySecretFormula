#ifndef DIRTYBUBBLE_H
#define DIRTYBUBBLE_H

#include "deadlybarrier.h"

class DirtyBubble : public DeadlyBarrier
{
public:
    DirtyBubble(qreal playerWidth);
    void move() override;
    qreal getWidth();
    qreal getHeight();
    ~DirtyBubble();
private:
    qreal width;
    qreal height;
    int steps = 0;
    int move_x = 1;
    int move_y = 1;
    const int max_steps = 60;
    void stepForward();
    void changeDirectionIfNeeded();
};

#endif // DIRTYBUBBLE_H
