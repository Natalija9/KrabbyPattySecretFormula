#include "leveldata.h"

#include <cstdlib>

LevelData::LevelData(Settings *settings)
{

    this->settings = settings;

    backgrounds = {":/images/level1.jpg",
                  ":/images/level2.png",
                  ":/images/level3.png",
                  ":/images/level4.png",
                  ":/images/level5.png",
                  ":/images/level6.png"};
    tiles = {":/images/tile.png",
             ":/images/tile2.png",
             ":/images/tile3.png",
             ":/images/tile4.png",
             ":/images/tile5.png",
             ":/images/tile6.png"};

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
                     ":/images/jellyfish_blue.png",
                     ":/images/EvilSpongeBob.png",
                     ":/images/dirtyBubble1.png",
                     ":/images/keren.png"};

    slowingBarriers = {":/images/SlowingTile.png",
                       ":/images/SlowingTile2.png",
                       ":/images/SlowingTile3.png",
                       ":/images/SlowingTile4.png",
                       ":/images/SlowingTile5.png",
                       ":/images/SlowingTile6.png"};

}


QString LevelData::getBackground(int levelId){
    return this->backgrounds[levelId - 1];
}
QString LevelData::getTiles(int levelId){
    return this->tiles[levelId - 1];
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
QString LevelData::getSlowingBarrier(int levelId){
    return this->slowingBarriers[levelId - 1];
}


bool LevelData::getRandomDecision(){
    double x = ((double) rand() / (RAND_MAX));
    decisionMaker = settings->getMode() ? 0.9 : 0.6;
    return x < decisionMaker;
}
