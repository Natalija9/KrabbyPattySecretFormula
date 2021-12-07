#ifndef LEVEL_H
#define LEVEL_H

#include <QKeyEvent>
#include<QGraphicsView>


class Level: public QGraphicsView
{
    Q_OBJECT
    public:
        // Methods
        Level();

public:

    void start();
    void center(QGraphicsItem *i);

    virtual ~Level();
private:
    QGraphicsView *view;
    QTimer *mainTimer;

};

#endif // LEVEL_H
