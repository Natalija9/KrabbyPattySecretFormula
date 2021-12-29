#ifndef FLAG_H
#define FLAG_H

#include "item.h"
#include "level.h"

class Flag : public Item
{
public:
    Flag(Level *parent, qreal playerWidth);
    void collect() override;
    ~Flag();
private:
    int number_of_points;
    Level *lvl;
};


#endif // FLAG_H
