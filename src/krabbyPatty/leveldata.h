#ifndef LEVELDATA_H
#define LEVELDATA_H

#include <vector>
#include <string>
#include <QRandomGenerator>
#include <QString>

#include "settings.h"
#include "deadlybarrier.h"

class LevelData
{
public:
    LevelData(Settings *settings);
    QString getBackground(int levelId);
    QString getTiles(int levelId);
    QString getIngredient(int levelId);
    QString getLevelMap(int levelId);
    DeadlyBarrier* getDeadlyBarrier(int playerWidth);
    QString getSlowingBarrier(int levelId);
    bool getRandomDecision();
    int getSound();
    ~LevelData();


private:
    std::vector<QString> backgrounds;
    std::vector<QString> tiles;
    std::vector<QString> ingredients;
    std::vector<QString> levelMaps;
    std::vector<QString> deadlyBarriers;
    std::vector<QString> slowingBarriers;

    Settings *settings;
    double decisionMaker;
    QRandomGenerator *generator;

};

#endif // LEVELDATA_H
