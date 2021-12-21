#ifndef FLAG_H
#define FLAG_H

#include "item.h"

class Flag : public QObject, public QGraphicsPixmapItem
{
public:
    Flag(qreal playerWidth);

private:
    int number_of_points;
};


#endif // FLAG_H
