#ifndef LEVELDATA_H
#define LEVELDATA_H

#include <vector>
#include <string>
#include <QString>

#include "settings.h"

class LevelData
{
public:
    LevelData(Settings *settings);
    QString getBackground(int levelId);
    QString getIngredient(int levelId);
    QString getLevelMap(int levelId);
    QString getDeadlyBarrier();
    bool getRandomDecision();


private:
    std::vector<QString> backgrounds;
    std::vector<QString> ingredients;
    std::vector<QString> levelMaps;
    std::vector<QString> deadlyBarriers;
    Settings *settings;
    double decisionMaker;


};

#endif // LEVELDATA_H
