#ifndef LEVELDATA_H
#define LEVELDATA_H

#include <vector>
#include <QRandomGenerator>
#include <QString>

#include "settings.h"
#include "deadlybarrier.h"

class LevelData
{
public:
    LevelData(Settings *settings);
    qreal screenWidth;
    qreal screenHeight;
    qreal sceneSizeX;
    qreal platformOffset;
    qreal itemOffset;
    QString getBackground(int levelId);
    QString getTile(int levelId);
    QString getSlowingTile(int levelId);
    QString getIngredient(int levelId);
    QString getLevelMap(int levelId);
    DeadlyBarrier* getDeadlyBarrier(int playerWidth);
    bool getRandomDecision();
    bool getSound();
    ~LevelData();

private:
    std::vector<QString> backgrounds;
    std::vector<QString> tiles;
    std::vector<QString> ingredients;
    std::vector<QString> levelMaps;
    std::vector<QString> deadlyBarriers;
    std::vector<QString> slowingBarriers;
    Settings *settings;
    QRandomGenerator *generator;
    double decisionMaker;
    void getScreenDimensions();
    void calculateScalingParameters();

};

#endif // LEVELDATA_H
