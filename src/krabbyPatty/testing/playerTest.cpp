#include "testing/catch.hpp"

#include "Headers/player.h"
#include "Headers/playerparameters.h"
#include "Headers/level.h"
#include "Headers/ingredient.h"
#include "Headers/life.h"
#include "Headers/slowingtile.h"
#include "Headers/deadlybarrier.h"
#include "Headers/regulartile.h"
#include "Headers/flag.h"

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <thread>
#include<QApplication>
#include<QTimer>

extern Level *level;

TEST_CASE("Postavljanje brzine na velicinu koraka pritiskom strelice na desno", "[function]"){
    // Arrange
    Player *player = new Player();
    PlayerParameters *parameters = new PlayerParameters();
    qreal expectedValue = parameters->_stepX;

    // Act
    QKeyEvent *event = new QKeyEvent(QEvent::KeyPress,Qt::Key_Right,Qt::NoModifier);
    player->keyPressEvent(event);
    qreal currentValue = player->getVelocityX();


    delete player;
    delete parameters;
    delete event;

    REQUIRE(currentValue == expectedValue);
}
