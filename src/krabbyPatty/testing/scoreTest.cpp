#include "testing/catch.hpp"
#include <QList>
#include "Headers/score.h"
#include <iostream>
#include <Headers/level.h>
#include <Headers/leveldata.h>
#include "Headers/leveldata.h"
#include "Headers/jellyfish.h"
#include "Headers/dirtybubble.h"
#include "Headers/karen.h"
#include "Headers/evilspongebob.h"
#include <Headers/settings.h>

#include <QRandomGenerator>
#include <QApplication>
#include <QScreen>
#include <vector>



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
    }

    SECTION("Trenutni skor se uvecava za 1 pri svakom pozivu funkcije")
    {
        // Arrange
        Settings *settings1 = new Settings();
        LevelData *level_data1 = new LevelData(settings1);
        Score *score1 = new Score(level_data1);

        score1->current_score = 10;
        int expectedValue1 = 11;



        // Act
        score1->increase();
        int returnValue1 = score1->current_score;


        // Assert
        REQUIRE(returnValue1 == expectedValue1);


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

    }

    SECTION("Broj trenutnih zivota se uvecava za 1")
    {

        // Arrange
        Settings *settings1 = new Settings();
        LevelData *level_data1 = new LevelData(settings1);
        Score *score1 = new Score(level_data1);

        int expectedValue1 = 4;

        // Act
        score1->addLife();
        int returnValue1 = score1->getLives();

        // Assert
        REQUIRE(returnValue1 == expectedValue1);
    }
}


TEST_CASE("takeLife()", "[function]")
{
    SECTION("Umanjivanje preostalog broja zivota za 1 i trenutni skor postavlja na 0")
    {
        // Arrange

        Settings *settings = new Settings();
        LevelData *level_data = new LevelData(settings);
        Score *score1 = new Score(level_data);

        int expectedValue = 2;
        int expectedValue1 = 0;

        // Act
        score1->takeLife();
        int returnValue = score1->getLives();
        int returnValue1 = score1->current_score;

        // Assert
        REQUIRE(returnValue == expectedValue);
        REQUIRE(returnValue1 == expectedValue1);


    }
}

TEST_CASE("countLevelScore()", "[function]")
{
    SECTION("Izbacivanje izuzetka nakon odigranog nivoa ukoliko je preostalo vreme 0")
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
    }

    SECTION("Izbacivanje izuzetka nakon odigranog nivoa ukoliko je trenutni skor 0")
    {
        // Arrange
        Settings *settings1 = new Settings();
        LevelData *level_data1 = new LevelData(settings1);
        Score *score1 = new Score(level_data1);

        int currentValue = 60;
        int expectedValue1 = 0;
        score1->current_score = 0;

        // Act
        int returnValue1 = score1->countLevelScore(currentValue);

        // Assert
        REQUIRE(expectedValue1 == returnValue1);
    }

    SECTION("Racunanje skora nakon odigranog nivoa prema zadatoj formuli")
    {
         // Arrange
         Settings *settings2 = new Settings();
         LevelData *level_data2 = new LevelData(settings2);
         Score *score2 = new Score(level_data2);

         int currentValue1 = 60;
         score2->current_score = 10;

         int expectedValue = 10*5*60*0.1 + 3*10;

         // Act
         int returnValue1 = score2->countLevelScore(currentValue1);

         // Assert
         REQUIRE(expectedValue == returnValue1);

    }

}

TEST_CASE("getTotalScore", "[function]")
{
    SECTION("Racunanje konacnog skora ukoliko nije sakupljen nijedan sastojak ni u jednom nivou")
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

    }

   }
