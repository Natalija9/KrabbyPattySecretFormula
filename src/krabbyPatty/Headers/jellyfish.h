#ifndef JELLYFISH_H
#define JELLYFISH_H

#include "deadlybarrier.h"
#include <QRandomGenerator>

class Jellyfish : public DeadlyBarrier
{
public:
    Jellyfish(qreal playerWidth);

    void move() override;
    int getSteps();
    int getMoveY();
    int getWidth();
    int getHeight();
    const int max_steps = 60;

    ~Jellyfish();
private:
    int steps = 0;
    int move_y = 1;
    qreal width = 0;
    qreal height = 0;
    void stepForward();
    void changeDirectionIfNeeded();
    QRandomGenerator *generator;
};

#endif // JELLYFISH_H
