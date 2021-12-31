#include "testing/catch.hpp"
#include "Headers/playerparameters.h"

TEST_CASE("PlayerParameters()", "[function]")
{
    SECTION("Pri kreiranju konstruktora _screenHeight je > 0")
    {


        // Arrange
         PlayerParameters *parameters = new PlayerParameters();

        // Act
        parameters->getScreenHeight();
        qreal returnValue = parameters->_screenHeight;

        delete parameters;

        // Assert
        REQUIRE(returnValue > 0 );
    }

    SECTION("Funkcija racuna visinu igraca kao 20% visine ekrana")
    {
        // Arrange
        PlayerParameters *parameters = new PlayerParameters();
        qreal expectedValue = 20;
        parameters->_screenHeight = 100;

        // Act
        parameters->calculateScalingParameters();
        qreal returnValue = parameters->_height;

        delete parameters;

        // Assert
        REQUIRE(returnValue == expectedValue);

    }

    SECTION("Funkcija racuna sirinu igraca kao 70% njegove visine")
    {
        // Arrange
        PlayerParameters *parameters = new PlayerParameters();
        parameters->_screenHeight = 100;
        qreal expectedValue = 20 * 0.7;

        // Act
        parameters->calculateScalingParameters();
        qreal returnValue = parameters->_width;

        delete parameters;

        // Assert
        REQUIRE(returnValue == expectedValue);
    }

    SECTION("Funkcija racuna korak po y osi kao 13% njegove visine")
    {
        // Arrange
        PlayerParameters *parameters = new PlayerParameters();
        parameters->_screenHeight = 100;
        qreal expectedValue = 20 * 0.13;

        // Act
        parameters->calculateScalingParameters();
        qreal returnValue = parameters->_stepY;

        delete parameters;

        // Assert
        REQUIRE(returnValue == expectedValue);
    }

    SECTION("Funkcija racuna koeficijent gravitacije kao 5% njegovog koraka po y osi")
    {
        // Arrange
        PlayerParameters *parameters = new PlayerParameters();
        parameters->_screenHeight = 100;
        qreal expectedValue = 20 * 0.13 * 0.05;


        // Act
        parameters->calculateScalingParameters();
        qreal returnValue = parameters->_gravity;

        delete parameters;

        // Assert
        REQUIRE(returnValue == expectedValue);
    }

    SECTION("Funkcija racuna poziciju igraca na y osi kao 65% visine ekrana")
    {
        // Arrange
        PlayerParameters *parameters = new PlayerParameters();
        qreal expectedValue = 65;
        parameters->_screenHeight = 100;

        // Act
        parameters->calculateScalingParameters();
        qreal returnValue = parameters->_posY;

        delete parameters;


        // Assert
        REQUIRE(returnValue == expectedValue);
    }

}


