#ifndef LEVEL_H
#define LEVEL_H

#include <QKeyEvent>
#include<QGraphicsView>
#include <QLabel>

#include "player.h"
#include "leveldata.h"
#include "message.h"
#include "informationbar.h"
#include "sound.h"

class Level: public QGraphicsView
{
    Q_OBJECT
    public:
        Level(int levelId, LevelData *levelData);

        void startLevel();
        void finishLevel(MessageText msgText);
        QGraphicsView *view;
        QTimer *levelTimer;
     QGraphicsScene *scene ;
        ~Level();

    signals:
        void endLevel();

    public slots:
        void outOfTime();
        void setInformationBar();
        void updateTimerLabel();

    private:
        void setView();
        int levelId;
        LevelData *levelData;
        QTimer *mainTimer;

        qreal playerWidth;
        qreal playerHeight;
        InformationBar *informationBar;
        QLabel *timerLabel;
        Sound *music;
        void parseLevelMap();
        void addObject(char type, qreal x, qreal y);

};

#endif // LEVEL_H
