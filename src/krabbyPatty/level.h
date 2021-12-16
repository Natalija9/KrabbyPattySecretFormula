#ifndef LEVEL_H
#define LEVEL_H

#include <QKeyEvent>
#include<QGraphicsView>
#include "player.h"
#include "leveldata.h"

class Level: public QGraphicsView
{
    Q_OBJECT
    public:
        // Methods
        Level(int levelId, LevelData *levelData);

public:

    void startLevel();
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
    int levelId;
    LevelData *levelData;
    QTimer *mainTimer;
    void parseLevelMap();
    void addObject(char type, int x,int y);
    QGraphicsScene *scene ;
    qreal playerWidth;
    qreal playerHeight;
};

#endif // LEVEL_H
