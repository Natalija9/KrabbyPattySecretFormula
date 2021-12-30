#include "testing/catch.hpp"
#include "Headers/message.h"


TEST_CASE("getMessage", "[function]")
{
    SECTION("Za prosledjenu vrednost koje se nalazi u MessageText funkcija vraca validan string")
    {
        // Arrange
        Message *message = new Message();
        MessageText ulaz = MessageText::LostLife;
        QString ocekivani_izlaz = "Oops, you lost a life!";

        // Act
        QString dobijen_izlaz = message->getMessage(ulaz);

        delete message;

        // Assert
        REQUIRE(QString::compare(ocekivani_izlaz, dobijen_izlaz, Qt::CaseSensitive) == 0);
    }

    SECTION("Za prosledjeni int koji se nalazi u intervalu [0, 4] funkcija vraca validan string")
    {
        // Arrange
        Message *message = new Message();
        MessageText ulaz1 = MessageText(0);
        MessageText ulaz2 = MessageText(4);
        QString ocekivani_izlaz1 = "Oops, you lost a life!";
        QString ocekivani_izlaz2 = "Oops, you ran out of time!";

        // Act
        QString dobijen_izlaz1 = message->getMessage(ulaz1);
        QString dobijen_izlaz2 = message->getMessage(ulaz2);

        delete message;

        // Assert
        CHECK(QString::compare(ocekivani_izlaz1, dobijen_izlaz1, Qt::CaseSensitive) == 0);
        REQUIRE(QString::compare(ocekivani_izlaz2, dobijen_izlaz2, Qt::CaseSensitive) == 0);
    }

    SECTION("Za prosledjeni int koji je veci od 4 funkcija ispaljuje izuzetak")
    {
        // Arrange
        Message *message = new Message();
        MessageText ulaz2 = MessageText(6);

        // Act and Assert
        REQUIRE_THROWS(message->getMessage(ulaz2));
        delete message;
    }

    SECTION("Za prosledjeni int koji je manji od 0 funkcija ispaljuje izuzetak")
    {
        // Arrange
        Message *message = new Message();
        MessageText ulaz1 = MessageText(-2);

        // Act + Assert
        REQUIRE_THROWS(message->getMessage(ulaz1));
        delete message;
    }

}
