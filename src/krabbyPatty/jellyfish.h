#ifndef JELLYFISH_H
#define JELLYFISH_H

#include "deadlybarrier.h"
#include <QRandomGenerator>

class Jellyfish : public DeadlyBarrier
{
public:
    Jellyfish(qreal playerWidth);
    void move() override;

private:
    int steps = 0;
    int move_y = 1;
    const int max_steps = 60;
    void stepForward();
    void changeDirectionIfNeeded();
    QRandomGenerator *generator;
};

#endif // JELLYFISH_H
