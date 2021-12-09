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
    qreal screenWidth;
    qreal screenHeight;
    QGraphicsView *view;

    virtual ~Level();

public slots:
    void increaseScore();
    void increaseLife();
    void decreaseScore();
    void death();

private:
    //Player *player;

    QTimer *mainTimer;


};

#endif // LEVEL_H
