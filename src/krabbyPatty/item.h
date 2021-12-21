#ifndef ITEM_H
#define ITEM_H

#include <QGraphicsPixmapItem>

class Item : QObject, public QGraphicsPixmapItem
{
        Q_OBJECT
public:
    Item();

    virtual void collect() = 0;
};

#endif // ITEM_H
