#include "testing/catch.hpp"

#include "Headers/deadlybarrier.h"
#include "Headers/flag.h"
#include "Headers/ingredient.h"
#include "Headers/level.h"
#include "Headers/life.h"
#include "Headers/player.h"
#include "Headers/playerparameters.h"
#include "Headers/regulartile.h"
#include "Headers/slowingtile.h"

#include <QApplication>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QTimer>
#include <thread>

extern Level* level;

TEST_CASE("keyPressEvent", "[function]") {
  SECTION(
      "Postavljanje brzine na velicinu koraka pritiskom strelice na desno") {
    // Arrange
    Player* player = new Player();
    PlayerParameters* parameters = new PlayerParameters();
    qreal expectedValue = parameters->_stepX;

    // Act
    QKeyEvent* event =
        new QKeyEvent(QEvent::KeyPress, Qt::Key_Right, Qt::NoModifier);
    player->keyPressEvent(event);
    qreal currentValue = player->getVelocityX();


    delete player;
    delete parameters;
    delete event;

    REQUIRE(currentValue == expectedValue);
  }
  SECTION("Postavljanje brzine na velicinu koraka pritiskom strelice na levo") {
    // Arrange
    Player* player = new Player();
    PlayerParameters* parameters = new PlayerParameters();
    qreal expectedValue = -parameters->_stepX;

    // Act
    QKeyEvent* event =
        new QKeyEvent(QEvent::KeyPress, Qt::Key_Left, Qt::NoModifier);
    player->keyPressEvent(event);
    qreal currentValue = player->getVelocityX();


    delete player;
    delete parameters;
    delete event;

    REQUIRE(currentValue == expectedValue);
  }
}

TEST_CASE("keyRealeaseEvent", "[function]") {

  SECTION("Postavljanje brzine na 0  pustanjem strelice na desno") {
    // Arrange
    Player* player = new Player();
    PlayerParameters* parameters = new PlayerParameters();
    qreal expectedValue = 0;

    // Act
    QKeyEvent* event =
        new QKeyEvent(QEvent::KeyPress, Qt::Key_Right, Qt::NoModifier);
    player->keyReleaseEvent(event);
    qreal currentValue = player->getVelocityX();


    delete player;
    delete parameters;
    delete event;

    REQUIRE(currentValue == expectedValue);
  }
  SECTION("Postavljanje brzine na 0  pustanjem strelice na levo") {
    // Arrange
    Player* player = new Player();
    PlayerParameters* parameters = new PlayerParameters();
    qreal expectedValue = 0;

    // Act
    QKeyEvent* event =
        new QKeyEvent(QEvent::KeyPress, Qt::Key_Left, Qt::NoModifier);
    player->keyReleaseEvent(event);
    qreal currentValue = player->getVelocityX();


    delete player;
    delete parameters;
    delete event;

    REQUIRE(currentValue == expectedValue);
  }
}
