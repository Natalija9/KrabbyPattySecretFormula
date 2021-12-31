#include "testing/catch.hpp"
#include "Headers/ranglist.h"

bool EqualLists(QList<std::pair<QString, int>> &a, QList<std::pair<QString, int>> &b){

    bool equal = std::equal( a.begin(), a.end(),
                                b.begin(),
                                []( const std::pair<QString, int> &a, const std::pair<QString, int> &b) {
                                   return a.first == b.first  && a.second == b.second;
                                } );
    return equal;
}


TEST_CASE("sortPlayersByScore", "[function]")
{
    SECTION("Sortiranje igraca u nerastucem poretku")
    {
        // Arrange
        RangList *rang_list = new RangList();

        QList<std::pair<QString, int>> ulaz = {};
        ulaz.append(std::make_pair("Marko",15));
        ulaz.append(std::make_pair("Ana",13));
        ulaz.append(std::make_pair("Milos", 16));

        rang_list->playerList = ulaz;

        QList<std::pair<QString, int>> ocekivani_izlaz = {};
        ocekivani_izlaz.append(std::make_pair("Milos", 16));
        ocekivani_izlaz.append(std::make_pair("Marko",15));
        ocekivani_izlaz.append(std::make_pair("Ana",13));

        // Act
        rang_list->sortPlayersByScore();
        auto dobijen_izlaz = rang_list->playerList;

        // Assert
        REQUIRE(EqualLists(dobijen_izlaz, ocekivani_izlaz));

        delete rang_list;
    }
}

TEST_CASE("readFromFileAndInsertIntoList", "[function]")
{

    SECTION("Provera postojanja fajla iz kojeg se citaju igraci")
    {

        QString path = "../krabbyPatty/files/players.txt";
        QFile txt_file(path);

        REQUIRE(txt_file.exists());

    }

    SECTION("Citanje igraca iz fajla i upis u listu")
    {
        //Arrange
        RangList *rang_list = new RangList();

        QList<std::pair<QString, int>> ocekivani_izlaz = {};
        ocekivani_izlaz.append(std::make_pair("Nikolina", 2555));
        ocekivani_izlaz.append(std::make_pair("anja", 1737));
        ocekivani_izlaz.append(std::make_pair("lucija", 1412));
        ocekivani_izlaz.append(std::make_pair("Marija", 886));
        ocekivani_izlaz.append(std::make_pair("Igor", 350));
        ocekivani_izlaz.append(std::make_pair("Emilija", 350));
        ocekivani_izlaz.append(std::make_pair("konacno", 347));
        ocekivani_izlaz.append(std::make_pair("Ivana", 347));
        ocekivani_izlaz.append(std::make_pair("nikola", 96));
        ocekivani_izlaz.append(std::make_pair("svasta11", 87));

        //Act
        rang_list->readFromFileAndInsertIntoList();
        auto dobijen_izlaz = rang_list->playerList;

        //Assert
        REQUIRE(EqualLists(dobijen_izlaz, ocekivani_izlaz));

        delete rang_list;
    }
}

TEST_CASE("insertPlayerIntoList", "[function]")
{

    SECTION("Ubacivanje igraca u listu na poziciju unutar postojece rang liste tako da lista ostane sortirana nerastuce")
    {
        //Arrange
        RangList *rang_list = new RangList();
        rang_list->readFromFileAndInsertIntoList();

        std::pair<QString, int> novi_igrac = std::make_pair("Helena", 987);

        QList<std::pair<QString, int>> ocekivani_izlaz = {};
        ocekivani_izlaz.append(std::make_pair("Nikolina", 2555));
        ocekivani_izlaz.append(std::make_pair("anja", 1737));
        ocekivani_izlaz.append(std::make_pair("lucija", 1412));
        ocekivani_izlaz.append(std::make_pair("Helena", 987));
        ocekivani_izlaz.append(std::make_pair("Marija", 886));
        ocekivani_izlaz.append(std::make_pair("Igor", 350));
        ocekivani_izlaz.append(std::make_pair("Emilija", 350));
        ocekivani_izlaz.append(std::make_pair("konacno", 347));
        ocekivani_izlaz.append(std::make_pair("Ivana", 347));
        ocekivani_izlaz.append(std::make_pair("nikola", 96));


        //Act
        rang_list->insertPlayerIntoList(novi_igrac.first, novi_igrac.second);
        auto dobijen_izlaz = rang_list->playerList;

        //Assert
        REQUIRE(EqualLists(dobijen_izlaz, ocekivani_izlaz));

        delete rang_list;
    }

    SECTION("Ubacivanje igraca sa ostvarenim brojem poena manjim od najmanjeg broja poena u postojecoj listi tako da lista ostane nepromenjena")
    {
        //Arrange
        RangList *rang_list = new RangList();
        rang_list->readFromFileAndInsertIntoList();
        auto postojeca_lista = rang_list->playerList;

        std::pair<QString, int> novi_igrac = std::make_pair("Helena", 10);

        //Act
        rang_list->insertPlayerIntoList(novi_igrac.first, novi_igrac.second);
        auto dobijen_izlaz = rang_list->playerList;

        //Assert
        REQUIRE(EqualLists(dobijen_izlaz, postojeca_lista));

        delete rang_list;
    }
}

TEST_CASE("printPlayersIntoFile", "[function]")
{
    SECTION("Provera postojanja fajla u koji se upisuju igraci")
    {

        QString path = "../krabbyPatty/files/players.txt";
        QFile txt_file(path);

        REQUIRE(txt_file.exists());

    }

    SECTION("Ispisivanje liste igraca u fajl")
    {
        //Arrange
        RangList *rang_list1 = new RangList();
        RangList *rang_list2 = new RangList();


        QList<std::pair<QString, int>> postojeca_lista = {};
        postojeca_lista.append(std::make_pair("Nikolina", 2555));
        postojeca_lista.append(std::make_pair("anja", 1737));
        postojeca_lista.append(std::make_pair("lucija", 1412));
        postojeca_lista.append(std::make_pair("Marija", 886));
        postojeca_lista.append(std::make_pair("Igor", 350));
        postojeca_lista.append(std::make_pair("Emilija", 350));
        postojeca_lista.append(std::make_pair("konacno", 347));
        postojeca_lista.append(std::make_pair("Ivana", 347));
        postojeca_lista.append(std::make_pair("nikola", 96));
        postojeca_lista.append(std::make_pair("svasta11", 87));


        rang_list1->playerList = postojeca_lista;
        //Act

        rang_list1->printPlayersIntoFile();
        rang_list2->readFromFileAndInsertIntoList();

        auto dobijen_izlaz = rang_list2->playerList;

        //Assert
        REQUIRE(EqualLists(dobijen_izlaz, postojeca_lista));

        delete rang_list1;
        delete rang_list2;
    }
}




