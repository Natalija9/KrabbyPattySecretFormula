#include "leveldata.h"

LevelData::LevelData()
{

    backgrounds = {":/images/level1.jpg",
                  ":/images/level2.png",
                  ":/images/level3.png",
                  ":/images/level1.jpg",
                  ":/images/level1.jpg",
                  ":/images/level1.jpg"};

    ingredients = {":/images/bun.png",
                  ":/images/patty.png",
                  ":/images/tomato.png",
                  ":/images/lettuce.png",
                  ":/images/cheese.png",
                  ":/images/pickles.png"};

    levelMaps = {":/LevelMaps/level1.txt",
                ":/LevelMaps/level1.txt",
                ":/LevelMaps/level1.txt",
                ":/LevelMaps/level1.txt",
                ":/LevelMaps/level1.txt",
                ":/LevelMaps/level1.txt"};

    unlocked.resize(5, false);
    unlocked[0] = true;

}

QString LevelData::getBackground(int levelId){
    return this->backgrounds[levelId - 1];
}

QString LevelData::getIngredient(int levelId){
    return this->ingredients[levelId-1];
}

QString LevelData::getLevelMap(int levelId){
    return this->levelMaps[levelId-1];
}

bool LevelData::isUnlocked(int levelId){
    return this->unlocked[levelId - 1];
}
