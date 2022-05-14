#include <catch2/catch_test_macros.hpp>
#include "GameUtilities/Algorithm/SAT/SatObject.h"


TEST_CASE( "SatObject::Constructor" ) 
{
    GU::Al::SatObject sat(Math::Vector2<float>(100, 100), 3 );
    REQUIRE(sat.getVertexCount() == 3);
    REQUIRE(sat.getEdgeCount() == 3);
}

TEST_CASE( "ddddd" ) 
{

}
