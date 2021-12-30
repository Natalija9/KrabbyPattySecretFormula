#include "testing/catch.hpp"
#include "Headers/jellyfish.h"

#include "Headers/deadlybarrier.h"
#include <QRandomGenerator>


TEST_CASE("JellyFish()", "[function]"){
     SECTION("u odnosu na sirinu igraca se postavljaju dimenzije meduze"){
        // Arrange

        Jellyfish *jellyFish = new Jellyfish(10);
        qreal expectedWidth = 5;
        qreal expectedHeight = 5;

        // Act
        qreal currentWidth = jellyFish->getWidth();
        qreal currentHeight = jellyFish->getHeight();

        // Assert
        REQUIRE(currentWidth == expectedWidth);
        REQUIRE(currentHeight == expectedHeight);
     }
}



TEST_CASE("move()", "[function]"){
     SECTION("proveravamo da li poziv stepForward() menja poziciju igraca i broj koraka"){
        // Arrange

        Jellyfish *jellyFish = new Jellyfish(10);
        qreal posX = jellyFish->pos().x();
        qreal posY = jellyFish->pos().y();
        int steps = jellyFish->getSteps();

        int expectedValueX = posX;
        int expectedValueY = posY - jellyFish->getMoveY();
        int expectedValueSteps = steps + 1;

        // Act

        jellyFish->move();

        int currentValueX = jellyFish->pos().x();
        int currentValueY = jellyFish->pos().y();
        int currentValueSteps = jellyFish->getSteps();

        delete jellyFish;

        // Assert
        REQUIRE(currentValueX == expectedValueX);
        REQUIRE(currentValueY == expectedValueY);
        REQUIRE(currentValueSteps == expectedValueSteps);

     }
     SECTION("proveravamo da li poziv changeDirectionIfNeeded() menja smer igraca i resetuje broj koraka na 0"){
        // Arrange

        Jellyfish *jellyFish = new Jellyfish(10);
        int moveY = jellyFish->getMoveY();
        int steps = 0;
        int expectedValueMaxSteps = 0;
        int expectedValueMoveY = -moveY;

        // Act

        for(int i = 0; i < jellyFish->max_steps; i++){
            jellyFish->move();
            steps=jellyFish->getSteps();
        }

        int currentValueSteps = steps;
        int currentValueMoveY = jellyFish->getMoveY();

        delete jellyFish;

        // Assert
        REQUIRE(currentValueSteps == expectedValueMaxSteps);
        REQUIRE(currentValueMoveY == expectedValueMoveY);
     }
}
