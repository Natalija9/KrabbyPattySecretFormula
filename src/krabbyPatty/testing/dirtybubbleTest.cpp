#include "Headers/dirtybubble.h"
#include "testing/catch.hpp"

TEST_CASE("DirtyBubble", "[function]") {
  SECTION("Ukoliko pozovemo kostruktor sa argumentom 100, ocekujemo da width "
          "bude 75") {
    // Arrange
    DirtyBubble* dirtybubble = new DirtyBubble(100);
    qreal ocekivani_width = 75;

    // Act
    qreal dobijeni_width = dirtybubble->getWidth();

    delete dirtybubble;

    // Assert
    REQUIRE(ocekivani_width == dobijeni_width);
  }

  SECTION("Ukoliko pozovemo kostruktor sa argumentom 120, ocekujemo da height "
          "bude 90") {
    // Arrange
    DirtyBubble* dirtybubble = new DirtyBubble(120);
    qreal ocekivani_height = 90;

    // Act
    qreal dobijeni_height = dirtybubble->getHeight();

    delete dirtybubble;

    // Assert
    REQUIRE(ocekivani_height == dobijeni_height);
  }
}

TEST_CASE("move", "[function]") {
  SECTION("Nakon poziva funkcije prepreka ce promeniti poziciju") {
    // Arrange
    DirtyBubble* dirtybubble = new DirtyBubble(100);
    qreal y = dirtybubble->y();

    // Act
    dirtybubble->move();
    qreal y1 = dirtybubble->y();

    delete dirtybubble;

    // Assert
    REQUIRE_FALSE(y == y1);
  }

  SECTION("U pocetku se prepreka krece na desno i na gore") {
    // Arrange
    DirtyBubble* dirtybubble = new DirtyBubble(100);
    qreal x = dirtybubble->x();
    qreal y = dirtybubble->y();

    // Act
    dirtybubble->move();
    qreal x1 = dirtybubble->x();
    qreal y1 = dirtybubble->y();

    delete dirtybubble;

    // Assert
    CHECK(x < x1);
    REQUIRE(y > y1);
  }

  SECTION("Nakon 60 poziva funkcije prepreka ce promeniti smer kretanja") {
    // Arrange
    DirtyBubble* dirtybubble = new DirtyBubble(100);
    qreal x = dirtybubble->x();
    dirtybubble->move();
    qreal x1 = dirtybubble->x();
    qreal korak1 = x1 - x;


    // Act
    for (int i = 0; i < 60; i++)
      dirtybubble->move();

    x = dirtybubble->x();
    dirtybubble->move();
    x1 = dirtybubble->x();
    qreal korak2 = x1 - x;

    delete dirtybubble;


    // Assert
    REQUIRE(korak1 == -korak2);
  }

  SECTION("Ocekujemo da ce se nakon 5 iteracija x koordinata uvecati za 5, a y "
          "smanjii za 5") {
    // Arrange
    DirtyBubble* dirtybubble = new DirtyBubble(100);
    qreal x = dirtybubble->x();
    qreal y = dirtybubble->y();

    // Act
    for (int i = 0; i < 5; i++)
      dirtybubble->move();

    qreal x1 = dirtybubble->x();
    qreal y1 = dirtybubble->y();

    delete dirtybubble;

    // Assert
    CHECK(x + 5 == x1);
    REQUIRE(y - 5 == y1);
  }
}
