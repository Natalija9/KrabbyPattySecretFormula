#ifndef LIFE_H
#define LIFE_H

#include "item.h"

class Life : public Item
{
public:
    Life();
    //virtual ~Life();
private:
    int number_of_lives;
};

#endif // LIFE_H
