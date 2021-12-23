#ifndef LEVEL_H
#define LEVEL_H

#include <QKeyEvent>
#include<QGraphicsView>
#include <QLabel>

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
    void finishLevel();
    qreal screenWidth;
    qreal screenHeight;
    QGraphicsView *view;
    QTimer *levelTimer;

    virtual ~Level();

signals:
    void endLevel();

public slots:
    void decreaseScore();
    void death();
    void outOfTime();
    void setHealthBar();
    void setIngredientBar();

private:
    int levelId;
    LevelData *levelData;
    QTimer *mainTimer;
    void parseLevelMap();
    void addObject(char type, int x,int y);
    QGraphicsScene *scene ;
    qreal playerWidth;
    qreal playerHeight;
    QLabel *ingredientLabelPic;
    QLabel *ingredientLabelText;
};

#endif // LEVEL_H
