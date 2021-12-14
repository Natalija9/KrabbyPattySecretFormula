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

    void startLevel(int levelId);
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
    QTimer *mainTimer;
    void parseLevelMap(QString file);
    void addObject(char type, int x,int y);
    QGraphicsScene *scene ;
    qreal playerWidth;
    qreal playerHeight;
};

#endif // LEVEL_H
