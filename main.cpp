#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "library.cpp"

TEST_CASE("7 choose 4 and 4 choose 3 is 140 bit") {
    REQUIRE(choice(7, 4) * choice(4, 3) == 140);
}
