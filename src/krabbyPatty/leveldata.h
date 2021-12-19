#ifndef LEVELDATA_H
#define LEVELDATA_H

#include <vector>
#include <string>
#include <QString>

class LevelData
{
public:
    LevelData();
    QString getBackground(int levelId);
    QString getIngredient(int levelId);
    QString getLevelMap(int levelId);
    QString getDeadlyBarrier();
//    bool isUnlocked(int levelId);

private:
    std::vector<QString> backgrounds;
    std::vector<QString> ingredients;
    std::vector<QString> levelMaps;
    std::vector<QString> deadlyBarriers;
//    std::vector<bool> unlocked;
};

#endif // LEVELDATA_H
