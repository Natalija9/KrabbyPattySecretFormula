#ifndef FLAG_H
#define FLAG_H

#include "item.h"
#include "level.h"

class Flag : public Item
{
public:
    Flag(qreal playerWidth);
    void collect() override;

private:
    int number_of_points;
};


#endif // FLAG_H
