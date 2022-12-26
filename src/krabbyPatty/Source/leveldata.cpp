#include "Headers/leveldata.h"
#include "Headers/dirtybubble.h"
#include "Headers/evilspongebob.h"
#include "Headers/jellyfish.h"
#include "Headers/karen.h"

#include <QApplication>
#include <QRandomGenerator>
#include <QScreen>

LevelData::LevelData(Settings* settings) {

  this->settings = settings;

  getScreenDimensions();
  calculateScalingParameters();

  backgrounds = {":/images/level1.jpg", ":/images/level2.png",
                 ":/images/level3.png", ":/images/level4.png",
                 ":/images/level5.png", ":/images/level6.png"};

  ingredients = {":/images/bun.png",    ":/images/patty.png",
                 ":/images/tomato.png", ":/images/lettuce.png",
                 ":/images/cheese.png", ":/images/pickles.png"};

  levelMaps = {":/LevelMaps/level1.txt", ":/LevelMaps/level2.txt",
               ":/LevelMaps/level3.txt", ":/LevelMaps/level4.txt",
               ":/LevelMaps/level5.txt", ":/LevelMaps/level6.txt"};

  tiles = {":/images/tile1.png", ":/images/tile2.png", ":/images/tile3.png",
           ":/images/tile4.png", ":/images/tile5.png", ":/images/tile6.png"};

  slowingBarriers = {":/images/SlowingTile1.png", ":/images/SlowingTile2.png",
                     ":/images/SlowingTile3.png", ":/images/SlowingTile4.png",
                     ":/images/SlowingTile5.png", ":/images/SlowingTile6.png"};

  deadlyBarriers = {":/images/jellyfish.png", ":/images/jellyfish_blue.png",
                    ":/images/EvilSpongeBob.png", ":/images/dirtyBubble1.png",
                    ":/images/keren.png"};

  this->generator = new QRandomGenerator();
}


QString LevelData::getBackground(int levelId) {
  if (levelId < 1 || levelId > 6)
    throw "Invalid id";
  return this->backgrounds[levelId - 1];
}
QString LevelData::getTile(int levelId) {
  if (levelId < 1 || levelId > 6)
    throw "Invalid id";
  return this->tiles[levelId - 1];
}

QString LevelData::getSlowingTile(int levelId) {
  if (levelId < 1 || levelId > 6)
    throw "Invalid id";
  return this->slowingBarriers[levelId - 1];
}

QString LevelData::getIngredient(int levelId) {
  if (levelId < 1 || levelId > 6)
    throw "Invalid id";
  return this->ingredients[levelId - 1];
}

bool LevelData::getSound() { return settings->getSound(); }


QString LevelData::getLevelMap(int levelId) {
  if (levelId < 1 || levelId > 6)
    throw "Invalid id";
  return this->levelMaps[levelId - 1];
}

DeadlyBarrier* LevelData::getDeadlyBarrier(int playerWidth) {

  int x = generator->bounded(100) % 4;

  switch (x) {
  case 0: {
    return new Jellyfish(playerWidth);
  }
  case 1: {
    return new DirtyBubble(playerWidth);
  }
  case 2: {
    return new Karen(playerWidth);
  }
  case 3: {
    return new EvilSpongeBob(playerWidth);
  }
  default: {
    return new Jellyfish(playerWidth);
  }
  }
}


bool LevelData::getRandomDecision() {

  double x = generator->bounded(1.0);
  decisionMaker = settings->getMode() == Mode::HardMode ? 0.9 : 0.7;
  return x < decisionMaker;
}

void LevelData::getScreenDimensions() {
  QScreen* screen = QApplication::screens().at(0);
  screenHeight = screen->size().height();
  screenWidth = screen->size().width();
}

void LevelData::calculateScalingParameters() {

  sceneSizeX = screenWidth * 5;
  platformOffset = screenHeight * 0.1;
  itemOffset = screenHeight * 0.225;
}

LevelData::~LevelData() { delete generator; }
