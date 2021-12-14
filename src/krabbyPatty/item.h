#ifndef ITEM_H
#define ITEM_H

#include <QGraphicsPixmapItem>

class Item : QObject, public QGraphicsPixmapItem
{
        Q_OBJECT
public:
    Item();
    bool check_overlap();
    int collect();
};

#endif // ITEM_H
