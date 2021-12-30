#include "testing/catch.hpp"
#include "Headers/evilspongebob.h"

TEST_CASE("EvilSpongeBob()", "[function]")
{
    SECTION("Kada se kreira nova instanca dimenzije slike se postavljaju na sirinu igraca")
    {

//        arrange
        qreal ulaz = 100;
        qreal ocekivani_izlaz = 100;

//        act
        EvilSpongeBob *evilSpongeBob = new EvilSpongeBob(ulaz);
        qreal dobijena_visina = evilSpongeBob->getHeight();
        qreal dobijena_sirina = evilSpongeBob->getWidth();

//        assert
        REQUIRE(dobijena_sirina == ocekivani_izlaz);
        REQUIRE(dobijena_visina == ocekivani_izlaz);


    }
}
