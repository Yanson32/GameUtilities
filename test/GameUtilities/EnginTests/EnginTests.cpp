#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <GameUtilities/Engin/Engin.h>

TEST_CASE( "Single argument constructor", "[Constructor]" ) {
    Engin engin;
    REQUIRE( engin.size() == 0 );
}
