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
//    bool isUnlocked(int levelId);

private:
    std::vector<QString> backgrounds;
    std::vector<QString> ingredients;
    std::vector<QString> levelMaps;
//    std::vector<bool> unlocked;
};

#endif // LEVELDATA_H
