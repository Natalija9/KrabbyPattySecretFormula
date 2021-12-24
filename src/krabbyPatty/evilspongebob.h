#ifndef EVILSPONGEBOB_H
#define EVILSPONGEBOB_H

#include "deadlybarrier.h"


class EvilSpongeBob : public DeadlyBarrier
{
public:
    EvilSpongeBob(qreal playerWidth);
    void move() override;

private:
    bool left;
    bool up;
    int steps = 0;
};


#endif // EVILSPONGEBOB_H
