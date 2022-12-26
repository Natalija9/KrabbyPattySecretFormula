#include "Headers/evilspongebob.h"
#include "testing/catch.hpp"

TEST_CASE("EvilSpongeBob()", "[function]") {
  SECTION("Kada se kreira nova instanca sirina slike se postavlja na sirinu "
          "igraca") {

    //        arrange
    qreal ulaz = 100;
    qreal ocekivani_izlaz = 100;

    //        act
    EvilSpongeBob* evilSpongeBob = new EvilSpongeBob(ulaz);
    qreal dobijena_sirina = evilSpongeBob->getWidth();

    //        assert
    REQUIRE(dobijena_sirina == ocekivani_izlaz);

    delete evilSpongeBob;
  }

  SECTION("Kada se kreira nova instanca visina slike se postavlja na sirinu "
          "igraca") {

    //        arrange
    qreal ulaz = 50;
    qreal ocekivani_izlaz = 50;

    //        act
    EvilSpongeBob* evilSpongeBob = new EvilSpongeBob(ulaz);
    qreal dobijena_visina = evilSpongeBob->getHeight();

    //        assert
    REQUIRE(dobijena_visina == ocekivani_izlaz);

    delete evilSpongeBob;
  }
}


TEST_CASE("EvilSpongeBob::move()", "[function]") {
  SECTION("Za prvih 24 poziva funkcije pozicija se pomera gore i levo") {
    //        arrange
    EvilSpongeBob* evilSpongeBob = new EvilSpongeBob(100);

    evilSpongeBob->setPos(100, 100);
    int br_ponavljanja = 10;
    qreal ocekivano_x = 80;
    qreal ocekivano_y = 80;

    //        act
    for (int i = 0; i < br_ponavljanja; i++) {
      evilSpongeBob->move();
    }

    qreal dobijeno_x = evilSpongeBob->x();
    qreal dobijeno_y = evilSpongeBob->y();


    //        assert)
    REQUIRE(dobijeno_x == ocekivano_x);
    REQUIRE(dobijeno_y == ocekivano_y);
  }

  SECTION("Za 25 do 49 ponavljanja pozicija se pomera dole i levo") {
    //        arrange
    EvilSpongeBob* evilSpongeBob = new EvilSpongeBob(100);

    evilSpongeBob->setPos(100, 100);
    int br_ponavljanja = 30;
    qreal ocekivano_x = 40;
    qreal ocekivano_y = 60;

    //        act
    for (int i = 0; i < br_ponavljanja; i++) {
      evilSpongeBob->move();
    }

    qreal dobijeno_x = evilSpongeBob->x();
    qreal dobijeno_y = evilSpongeBob->y();


    //        assert
    REQUIRE(dobijeno_x == ocekivano_x);
    REQUIRE(dobijeno_y == ocekivano_y);
  }

  SECTION("Za 100 ponavljanja pozicija pocinje da se pomera na desno") {

    //        arrange
    EvilSpongeBob* evilSpongeBob = new EvilSpongeBob(100);

    evilSpongeBob->setPos(100, 100);
    int br_ponavljanja = 100;
    qreal ocekivana_razlika = 2;

    for (int i = 0; i < br_ponavljanja; i++) {
      evilSpongeBob->move();
    }

    //        act
    qreal x1 = evilSpongeBob->x();
    evilSpongeBob->move();
    qreal x2 = evilSpongeBob->x();

    qreal dobijena_razlika = x2 - x1;

    //        assert
    REQUIRE(dobijena_razlika == ocekivana_razlika);
  }

  SECTION("Za 75 ponavljanja pozicija pocinje da se pomera na gore") {

    //        arrange
    EvilSpongeBob* evilSpongeBob = new EvilSpongeBob(100);

    evilSpongeBob->setPos(100, 100);
    int br_ponavljanja = 75;
    qreal ocekivana_razlika = 2;

    for (int i = 0; i < br_ponavljanja; i++) {
      evilSpongeBob->move();
    }

    //        act
    qreal y1 = evilSpongeBob->y();
    evilSpongeBob->move();
    qreal y2 = evilSpongeBob->y();

    qreal dobijena_razlika = y2 - y1;

    //        assert
    REQUIRE(dobijena_razlika == ocekivana_razlika);
  }

  SECTION("Na svakih 200 ponavljanja pozicija se vraca na pocetnu") {
    //        arrange
    EvilSpongeBob* evilSpongeBob = new EvilSpongeBob(100);

    evilSpongeBob->setPos(100, 100);
    int br_ponavljanja = 200;
    qreal ocekivano_x = 100;
    qreal ocekivano_y = 100;

    //        act
    for (int i = 0; i < br_ponavljanja; i++) {
      evilSpongeBob->move();
    }

    qreal dobijeno_x = evilSpongeBob->x();
    qreal dobijeno_y = evilSpongeBob->y();


    //        assert
    REQUIRE(dobijeno_x == ocekivano_x);
    REQUIRE(dobijeno_y == ocekivano_y);
  }
}
