#include "testing/catch.hpp"
#include "Headers/settings.h"

TEST_CASE("Kada se kreira novi settings muzika je ukljucena", "[fancy]")
{
    Settings *settings = new Settings();
    REQUIRE(settings->getSound() == true);
}
