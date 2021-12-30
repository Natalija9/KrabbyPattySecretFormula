#include "testing/catch.hpp"
#include "Headers/jellyfish.h"

#include "Headers/deadlybarrier.h"
#include <QRandomGenerator>


TEST_CASE("JellyFish()", "[function]"){
     SECTION("u odnosu na sirinu igraca se postavlja se sirina meduze"){
        // Arrange

        Jellyfish *jellyFish = new Jellyfish(10);
        qreal expectedWidth = 5;

        // Act
        qreal currentWidth = jellyFish->getWidth();

        // Assert
        REQUIRE(currentWidth == expectedWidth);
     }
     SECTION("u odnosu na sirinu igraca se postavljaja se visina meduze"){
        // Arrange

        Jellyfish *jellyFish = new Jellyfish(10);
        qreal expectedHeight = 5;

        // Act
        qreal currentHeight = jellyFish->getHeight();

        // Assert
        REQUIRE(currentHeight == expectedHeight);
     }
}



TEST_CASE("JellyFish::move()", "[function]"){
     SECTION("proveravamo da li poziv stepForward() menja x koordinatu igraca"){
        // Arrange
        Jellyfish *jellyFish = new Jellyfish(10);
        qreal posX = jellyFish->pos().x();
        int expectedValueX = posX;

        // Act
        jellyFish->move();
        int currentValueX = jellyFish->pos().x();
        delete jellyFish;

        // Assert
        REQUIRE(currentValueX == expectedValueX);
     }
     SECTION("proveravamo da li poziv stepForward() menja y koordinatu igraca"){
        // Arrange
        Jellyfish *jellyFish = new Jellyfish(10);
        qreal posY = jellyFish->pos().y();
        int expectedValueY = posY - jellyFish->getMoveY();

        // Act
        jellyFish->move();
        int currentValueY = jellyFish->pos().y();
        delete jellyFish;

        // Assert
        REQUIRE(currentValueY == expectedValueY);
     }
     SECTION("proveravamo da li poziv stepForward() menja broj koraka"){
        // Arrange
        Jellyfish *jellyFish = new Jellyfish(10);
        int steps = jellyFish->getSteps();
        int expectedValueSteps = steps + 1;

        // Act
        jellyFish->move();
        int currentValueSteps = jellyFish->getSteps();
        delete jellyFish;

        // Assert
        REQUIRE(currentValueSteps == expectedValueSteps);
     }
     SECTION("proveravamo da li poziv changeDirectionIfNeeded() menja smer kretanja igraca"){
        // Arrange
        Jellyfish *jellyFish = new Jellyfish(10);
        int moveY = jellyFish->getMoveY();
        int steps = jellyFish->getSteps();
        int expectedValueMoveY = -moveY;

        // Act
        for(int i = steps; i < jellyFish->max_steps; i++){
            jellyFish->move();
        }
        int currentValueMoveY = jellyFish->getMoveY();
        delete jellyFish;

        // Assert
        REQUIRE(currentValueMoveY == expectedValueMoveY);
     }
     SECTION("proveravamo da li poziv changeDirectionIfNeeded() resetuje broj koraka na 0"){
        // Arrange
        Jellyfish *jellyFish = new Jellyfish(10);
        int steps = 0;
        int expectedValueMaxSteps = 0;

        // Act
        for(int i = 0; i < jellyFish->max_steps; i++){
            jellyFish->move();
            steps=jellyFish->getSteps();
        }
        int currentValueSteps = steps;
        delete jellyFish;

        // Assert
        REQUIRE(currentValueSteps == expectedValueMaxSteps);
     }
}
