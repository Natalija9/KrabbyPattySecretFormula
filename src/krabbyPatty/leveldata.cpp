#include "leveldata.h"

#include <cstdlib>

LevelData::LevelData(Settings *settings)
{

    this->settings = settings;

    backgrounds = {":/images/level1.jpg",
                  ":/images/level2.png",
                  ":/images/level3.png",
                  ":/images/level4.png",
                  ":/images/level1.jpg",
                  ":/images/level1.jpg"};

    ingredients = {":/images/bun.png",
                  ":/images/patty.png",
                  ":/images/tomato.png",
                  ":/images/lettuce.png",
                  ":/images/cheese.png",
                  ":/images/pickles.png"};

    levelMaps = {":/LevelMaps/level1.txt",
                ":/LevelMaps/level2.txt",
                ":/LevelMaps/level1.txt",
                ":/LevelMaps/level1.txt",
                ":/LevelMaps/level1.txt",
                ":/LevelMaps/level1.txt"};

    deadlyBarriers = {":/images/jellyfish.png",
                     ":/images/jellyfish_blue.png"};

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

QString LevelData::getDeadlyBarrier(){
    int i = rand() % (deadlyBarriers.size());
    return deadlyBarriers[i];
}

bool LevelData::getRandomDecision(){
    double x = ((double) rand() / (RAND_MAX));
    decisionMaker = settings->getMode() ? 0.9 : 0.6;
    return x < decisionMaker;
}
