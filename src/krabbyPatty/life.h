#ifndef LIFE_H
#define LIFE_H

#include "item.h"

class Life : public Item
{
public:
    Life(qreal playerWidth);
    void collect() override;


private:
    int number_of_lives;
};

#endif // LIFE_H
