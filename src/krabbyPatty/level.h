#ifndef LEVEL_H
#define LEVEL_H

#include <QKeyEvent>
#include<QGraphicsView>
#include "player.h"

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

public slots:
    void increaseScore();
    void increaseLife();
    void decreaseScore();
    void death();

private:
    //Player *player;
    QGraphicsView *view;
    QTimer *mainTimer;


};

#endif // LEVEL_H
