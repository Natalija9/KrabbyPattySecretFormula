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
        Level(int levelId, LevelData *levelData);

        void startLevel();
        void finishLevel();
        qreal screenWidth;
        qreal screenHeight;
        QGraphicsView *view;
        QTimer *levelTimer;

        ~Level();

    signals:
        void endLevel();

    public slots:
        void death();
        void outOfTime();
        void setInformationBar();

    private:
        int levelId;
        LevelData *levelData;
        QTimer *mainTimer;
        QGraphicsScene *scene ;
        qreal playerWidth;
        qreal playerHeight;
        QLabel *ingredientLabelPic;
        QLabel *ingredientLabelText;
        QVector<QLabel*> lifeBar;

        void parseLevelMap();
        void addObject(char type, int x,int y);

};

#endif // LEVEL_H
