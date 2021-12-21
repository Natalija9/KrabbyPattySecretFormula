#ifndef JELLYFISH_H
#define JELLYFISH_H

#include "deadlybarrier.h"

class Jellyfish : public DeadlyBarrier
{
public:
    Jellyfish(qreal playerWidth);

    void move() override;

private:
    bool up;
    int steps = 0;
};

#endif // JELLYFISH_H
