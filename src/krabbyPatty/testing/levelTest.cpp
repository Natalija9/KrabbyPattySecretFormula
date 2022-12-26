#include "Headers/level.h"
#include "Headers/leveldata.h"
#include "Headers/score.h"
#include "Headers/settings.h"
#include "testing/catch.hpp"

TEST_CASE("Level", "[funtion]") {
  SECTION("Poziv konstruktora sa nevalidnim levelId ispaljuje izuzetak") {
    // Arrange
    Settings* settings = new Settings();
    LevelData* levelData = new LevelData(settings);

    // Act + Assert
    REQUIRE_THROWS(Level(-5, levelData));
    delete settings;
    delete levelData;
  }

  SECTION("Poziv konstruktora sa nevalidnim levelData ispaljuje izuzetak") {
    // Arrange
    int levelId = 3;

    // Act + Assert
    REQUIRE_THROWS(Level(levelId, nullptr));
  }
}
