#include "Headers/karen.h"
#include "Headers/deadlybarrier.h"
#include "testing/catch.hpp"


TEST_CASE("konstruktor", "[function]") {
  SECTION("Za prosledjenu sirinu igraca, konstruise se Karen prepreka "
          "skalirane visine") {
    // Arrange
    qreal ocekivana_visina = 75 * 1.3;

    // Act
    Karen* karen = new Karen(100);
    qreal dobijena_visina = karen->getHeight();

    // Assert
    delete karen;
    REQUIRE(ocekivana_visina == dobijena_visina);
  }

  SECTION("Za prosledjenu sirinu igraca, konstruise se Karen prepreka "
          "skalirane sirine") {
    // Arrange
    int ocekivana_sirina = 75;

    // Act
    Karen* karen = new Karen(100);
    qreal dobijena_sirina = karen->getWidth();

    // Assert
    delete karen;
    REQUIRE(ocekivana_sirina == dobijena_sirina);
  }
}

TEST_CASE("Funkcija move()", "[function]") {
  SECTION("Funkcija pomera prepreku ulevo") {
    // Arrange
    Karen* karen = new Karen(10);
    qreal ulazno_x = karen->x();
    qreal ocekivano_x = ulazno_x - 2;

    // Act
    karen->move();
    qreal izlazno_x = karen->x();

    // Assert
    delete karen;
    REQUIRE(ocekivano_x == izlazno_x);
  }

  SECTION("Nakon 10 koraka(iteracija), prepreka umanjuje svoju x koordinatu za "
          "20, a y ostaje nepromenjena") {
    // Arrange
    Karen* karen = new Karen(10);
    qreal trenutno_x = karen->x();
    qreal trenutno_y = karen->y();

    qreal ocekivano_x = trenutno_x - 20;
    qreal ocekivano_y = trenutno_y;

    // Act
    for (int i = 0; i < 10; i++) {
      karen->move();
    }

    qreal novo_x = karen->x();
    qreal novo_y = karen->y();

    // Assert
    delete karen;
    REQUIRE(novo_x == ocekivano_x);
    REQUIRE(novo_y == ocekivano_y);
  }

  SECTION("Nakon 100 poziva funkcije, prepreka menja smer kretanja udesno") {
    // Arrange
    Karen* karen = new Karen(10);
    qreal trenutno_x = karen->x();

    karen->move();
    qreal novo_x = karen->x();
    int trenutni_korak = novo_x - trenutno_x;

    // Act
    for (int i = 0; i < 100; i++) {
      karen->move();
    }

    trenutno_x = karen->x();
    karen->move();
    novo_x = karen->x();
    int naredni_korak = novo_x - trenutno_x;

    // Assert
    delete karen;
    REQUIRE(trenutni_korak == -naredni_korak);
  }
}
