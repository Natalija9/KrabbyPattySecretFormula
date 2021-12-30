#include "testing/catch.hpp"
#include "Headers/settings.h"


TEST_CASE("settings()", "[function]"){
    SECTION("Kada se kreira nova instanca muzika je ukljucena"){
        // Arrange
        Settings *settings = new Settings();
        bool expectedValue = true;

        // Act
        bool currentValue = settings->getSound();

        // Assert
        REQUIRE(currentValue == expectedValue);
    }
    SECTION("Kada se kreira nova instanca tezina je na easy"){
        // Arrange
        Settings *settings = new Settings();
        Mode expectedValue = Mode::EasyMode;

        // Act
        Mode currentValue = settings->getMode();

        // Assert
        REQUIRE(currentValue == expectedValue);
    }
}

TEST_CASE("setSound()", "[function]"){
     SECTION("Kada se ugasi opcija zvuka ocekivano je da nema muzike"){
        // Arrange
        Settings *settings = new Settings();
        settings->setSound(0);
        bool expectedValue = false;

        // Act
        bool currentValue = settings->getSound();

        // Assert
        REQUIRE(currentValue == expectedValue);
     }
}

TEST_CASE("setMode()", "[function]"){
    SECTION("Kada se promeni opcija tezine na hard ocekivano je da bude hard"){
        // Arrange
        Settings *settings = new Settings();
        settings->setMode(Mode(1));
        Mode expectedValue = Mode::HardMode;

        // Act
        Mode currentValue = settings->getMode();


        // Assert
        REQUIRE(currentValue == expectedValue);
    }
}

