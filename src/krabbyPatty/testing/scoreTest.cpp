#include "testing/catch.hpp"
#include "Headers/score.h"

TEST_CASE("increase()", "[function]")
{
    SECTION("Nakon kreiranja instance klase Score, trenutni skor treba da bude inicijalizovan na 0")
    {
        // Arrange
        Settings *settings = new Settings();
        LevelData *level_data = new LevelData(settings);
        Score *score = new Score(level_data);

        int expectedValue = 0;

        // Act
        int currentValue = score->current_score;


        // Assert
        REQUIRE(currentValue == expectedValue);

        delete settings;
        delete level_data;
        delete score;
    }

    SECTION("Trenutni skor se uvecava za 1 pri svakom pozivu funkcije")
    {
        // Arrange
        Settings *settings = new Settings();
        LevelData *level_data = new LevelData(settings);
        Score *score = new Score(level_data);

        score->current_score = 10;
        int expectedValue1 = 11;



        // Act
        score->increase();
        int returnValue1 = score->current_score;


        // Assert
        REQUIRE(returnValue1 == expectedValue1);

        delete settings;
        delete level_data;
        delete score;
    }
}

TEST_CASE("addLife()", "function")
{
    SECTION("Broj trenutnih zivota pri pozivanju konstuktora iznosi 3")
    {
        // Arrange
        Settings *settings = new Settings();
        LevelData *level_data = new LevelData(settings);
        Score *score = new Score(level_data);

        int expectedValue = 3;

        // Act
        int returnValue = score->getLives();

        // Assert
        REQUIRE(returnValue == expectedValue);

        delete settings;
        delete level_data;
        delete score;

    }

    SECTION("Broj trenutnih zivota se uvecava za 1")
    {

        // Arrange
        Settings *settings = new Settings();
        LevelData *level_data = new LevelData(settings);
        Score *score = new Score(level_data);

        int expectedValue = 4;

        // Act
        score->addLife();
        int returnValue = score->getLives();

        // Assert
        REQUIRE(returnValue == expectedValue);

        delete settings;
        delete level_data;
        delete score;
    }
}


TEST_CASE("takeLife()", "[function]")
{
    SECTION("Umanjivanje preostalog broja zivota za 1 i trenutni skor postavlja na 0")
    {
        // Arrange

        Settings *settings = new Settings();
        LevelData *level_data = new LevelData(settings);
        Score *score = new Score(level_data);

        int expectedValue = 2;
        int expectedValue1 = 0;

        // Act
        score->takeLife();
        int returnValue = score->getLives();
        int returnValue1 = score->current_score;

        // Assert
        REQUIRE(returnValue == expectedValue);
        REQUIRE(returnValue1 == expectedValue1);

        delete settings;
        delete level_data;
        delete score;

    }
}

TEST_CASE("countLevelScore()", "[function]")
{
    SECTION("Vraca rezultat 0 nakon odigranog nivoa ukoliko je preostalo vreme 0")
    {
        // Arrange
        Settings *settings = new Settings();
        LevelData *level_data = new LevelData(settings);
        Score *score = new Score(level_data);

        int currentValue = 0;
        int expectedValue = 0;

        // Act
        int returnValue = score->countLevelScore(currentValue);

        // Assert
        REQUIRE(expectedValue == returnValue);

        delete settings;
        delete level_data;
        delete score;
    }

    SECTION("Vraca rezultat 0 nakon odigranog nivoa ukoliko je trenutni skor 0")
    {
        // Arrange
        Settings *settings = new Settings();
        LevelData *level_data = new LevelData(settings);
        Score *score = new Score(level_data);

        int currentValue = 60;
        int expectedValue = 0;
        score->current_score = 0;

        // Act
        int returnValue = score->countLevelScore(currentValue);

        // Assert
        REQUIRE(expectedValue == returnValue);

        delete settings;
        delete level_data;
        delete score;
    }

    SECTION("Racunanje skora nakon odigranog nivoa prema zadatoj formuli")
    {
         // Arrange
         Settings *settings = new Settings();
         LevelData *level_data = new LevelData(settings);
         Score *score = new Score(level_data);

         int currentValue = 60;
         score->current_score = 10;

         int expectedValue = 10*5*60*0.1 + 3*10;

         // Act
         int returnValue = score->countLevelScore(currentValue);

         // Assert
         REQUIRE(expectedValue == returnValue);

         delete settings;
         delete level_data;
         delete score;

    }

}

TEST_CASE("getTotalScore", "[function]")
{
    SECTION("Racunanje konacnog skora ukoliko nije predjen nijedan nivo")
    {
        // Arrange
        Settings *settings = new Settings();
        LevelData *level_data = new LevelData(settings);
        Score *score = new Score(level_data);

        int expectedValue = 0;

        // Act
        int returnValue = score->getTotalScore();

        // Assert
        REQUIRE(expectedValue == returnValue);

        delete settings;
        delete level_data;
        delete score;
    }
}

TEST_CASE("saveCurrentScore()", "[function]")
{
    SECTION("Izbacivanje izuzetka za nevalidan unos levelId-a pri pozivu funkcije za cuvanje trenuntnog skora")
    {
        // Arrange
        Settings *settings = new Settings();
        LevelData *level_data = new LevelData(settings);
        Score *score = new Score(level_data);

        int currentValue = -1;
        int remainingTime = 60;

        // Act and Assert
        REQUIRE_THROWS(score->saveCurrentScore(currentValue,remainingTime));

        delete settings;
        delete level_data;
        delete score;
    }

   }
