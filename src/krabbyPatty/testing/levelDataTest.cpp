#include "Headers/leveldata.h"
#include "testing/catch.hpp"

TEST_CASE("LevelData()", "[function]") {
  SECTION(
      "Kada se kreira nova instanca, dimenzije ekrana su pozitivni brojevi") {
    //        arrange
    Settings* settings = new Settings();

    //        act
    LevelData* levelData = new LevelData(settings);

    //        assert
    REQUIRE(levelData->screenHeight > 0);
    REQUIRE(levelData->screenWidth > 0);
  }

  SECTION("Kada se kreira nova instanca, parametri skaliranja su pozitivni "
          "brojevi") {
    //        arrange
    Settings* settings = new Settings();

    //        act
    LevelData* levelData = new LevelData(settings);

    //        assert
    REQUIRE(levelData->sceneSizeX > 0);
    REQUIRE(levelData->platformOffset > 0);
    REQUIRE(levelData->itemOffset > 0);
  }
}


TEST_CASE("getBackground", "[function]") {
  SECTION("za nevalidnu vrednost nivoa funkcija izbacuje izuzetak") {
    //        arrange
    Settings* settings = new Settings();
    LevelData* levelData = new LevelData(settings);
    int ulaz = -1;

    //        act and assert
    REQUIRE_THROWS(levelData->getBackground(ulaz));
  }

  SECTION(
      "za validnu vrednost nivoa funkcija vraca odgovarajucu sliku pozadine") {
    //        arrange
    Settings* settings = new Settings();
    LevelData* levelData = new LevelData(settings);
    int ulaz = 1;
    QString ocekivani_izlaz = ":/images/level1.jpg";

    //        act
    QString dobijeni_izlaz = levelData->getBackground(ulaz);

    //        assert

    REQUIRE(QString::compare(ocekivani_izlaz, dobijeni_izlaz) == 0);
  }
}


TEST_CASE("getTile", "[function]") {
  SECTION("za nevalidnu vrednost nivoa funkcija izbacuje izuzetak") {
    //        arrange
    Settings* settings = new Settings();
    LevelData* levelData = new LevelData(settings);
    int ulaz = 7;

    //        act and assert
    REQUIRE_THROWS(levelData->getTile(ulaz));
  }

  SECTION(
      "za validnu vrednost nivoa funkcija vraca odgovarajucu sliku plocica") {
    //        arrange
    Settings* settings = new Settings();
    LevelData* levelData = new LevelData(settings);
    int ulaz = 2;
    QString ocekivani_izlaz = ":/images/tile2.png";

    //        act
    QString dobijeni_izlaz = levelData->getTile(ulaz);

    //        assert

    REQUIRE(QString::compare(ocekivani_izlaz, dobijeni_izlaz) == 0);
  }
}

TEST_CASE("getSlowingTile", "[function]") {
  SECTION("za nevalidnu vrednost nivoa funkcija izbacuje izuzetak") {
    //        arrange
    Settings* settings = new Settings();
    LevelData* levelData = new LevelData(settings);
    int ulaz = -5;

    //        act and assert
    REQUIRE_THROWS(levelData->getSlowingTile(ulaz));
  }

  SECTION("za validnu vrednost nivoa funkcija vraca odgovarajucu sliku bare") {
    //        arrange
    Settings* settings = new Settings();
    LevelData* levelData = new LevelData(settings);
    int ulaz = 3;
    QString ocekivani_izlaz = ":/images/SlowingTile3.png";

    //        act
    QString dobijeni_izlaz = levelData->getSlowingTile(ulaz);

    //        assert

    REQUIRE(QString::compare(ocekivani_izlaz, dobijeni_izlaz) == 0);
  }
}


TEST_CASE("getIngredient", "[function]") {
  SECTION("za nevalidnu vrednost nivoa funkcija izbacuje izuzetak") {
    //        arrange
    Settings* settings = new Settings();
    LevelData* levelData = new LevelData(settings);
    int ulaz = 10;

    //        act and assert
    REQUIRE_THROWS(levelData->getIngredient(ulaz));
  }

  SECTION(
      "za validnu vrednost nivoa funkcija vraca odgovarajucu sliku sastojka") {
    //        arrange
    Settings* settings = new Settings();
    LevelData* levelData = new LevelData(settings);
    int ulaz = 4;
    QString ocekivani_izlaz = ":/images/lettuce.png";

    //        act
    QString dobijeni_izlaz = levelData->getIngredient(ulaz);

    //        assert

    REQUIRE(QString::compare(ocekivani_izlaz, dobijeni_izlaz) == 0);
  }
}


TEST_CASE("getLevelMap", "[function]") {
  SECTION("za nevalidnu vrednost nivoa funkcija izbacuje izuzetak") {
    //        arrange
    Settings* settings = new Settings();
    LevelData* levelData = new LevelData(settings);
    int ulaz = 0;

    //        act and assert
    REQUIRE_THROWS(levelData->getLevelMap(ulaz));
  }

  SECTION("za validnu vrednost nivoa funkcija vraca odgovarajuci fajl mape") {
    //        arrange
    Settings* settings = new Settings();
    LevelData* levelData = new LevelData(settings);
    int ulaz = 5;
    QString ocekivani_izlaz = ":/LevelMaps/level5.txt";

    //        act
    QString dobijeni_izlaz = levelData->getLevelMap(ulaz);

    //        assert

    REQUIRE(QString::compare(ocekivani_izlaz, dobijeni_izlaz) == 0);
  }
}
