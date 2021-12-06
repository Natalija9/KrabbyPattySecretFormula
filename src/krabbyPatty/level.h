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

    virtual ~Level();
private:
    QTimer *mainTimer;

};

#endif // LEVEL_H
