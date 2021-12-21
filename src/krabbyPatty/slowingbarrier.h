#ifndef SLOWINGBARRIER_H
#define SLOWINGBARRIER_H

#include "item.h"

class SlowingBarrier: public QObject, public QGraphicsPixmapItem
{
public:
     SlowingBarrier(qreal playerWidth, QString imagePath);
};

#endif // SLOWINGBARRIER_H
