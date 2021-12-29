#ifndef DEADLYBARRIER_H
#define DEADLYBARRIER_H

#include <QObject>
#include <QGraphicsPixmapItem>

class DeadlyBarrier : public QObject, public QGraphicsPixmapItem
{
public:
    DeadlyBarrier();
    ~DeadlyBarrier();
protected:
    virtual void advance(int phase) override;
    virtual void move() = 0;
};

#endif // DEADLYBARRIER_H
