#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <GameUtilities/Engin/Engin.h>

TEST_CASE( "Single argument constructor", "[Constructor]" ) {
    GU::Engin::Engin engin;
    REQUIRE( engin.Size() == 0 );
}
