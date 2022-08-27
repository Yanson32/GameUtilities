#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include "GameUtilities/Algorithm/SAT/SatObject.h"
#include <Math/Line.h>

TEST_CASE( "SatObject::Constructor" ) 
{
    GU::Al::SatObject sat(Math::Vector2<float>(100, 100), 3 );
    REQUIRE(sat.getVertexCount() == 3);
    REQUIRE(sat.getEdgeCount() == 3);

    REQUIRE(Catch::Approx(sat.getPosition().x) == 100);
    REQUIRE(Catch::Approx(sat.getPosition().y) == 100);
    
    Math::Line<float> edge1 = sat.getEdge(0);
    REQUIRE(Catch::Approx(edge1.m_Start.x) == 100);
    REQUIRE(Catch::Approx(edge1.m_Start.y) == 100);
    REQUIRE(Catch::Approx(edge1.m_End.x) == 100);
    REQUIRE(Catch::Approx(edge1.m_End.y) == 100);
    
    Math::Line<float> edge2 = sat.getEdge(1);
    REQUIRE(Catch::Approx(edge2.m_Start.x) == 100);
    REQUIRE(Catch::Approx(edge2.m_Start.y) == 100);
    REQUIRE(Catch::Approx(edge2.m_End.x) == 100);
    REQUIRE(Catch::Approx(edge2.m_End.y) == 100);
    
    Math::Line<float> edge3 = sat.getEdge(2);
    REQUIRE(Catch::Approx(edge3.m_Start.x) == 100);
    REQUIRE(Catch::Approx(edge3.m_Start.y) == 100);
    REQUIRE(Catch::Approx(edge3.m_End.x) == 100);
    REQUIRE(Catch::Approx(edge3.m_End.y) == 100);
    
}


TEST_CASE( "SatObject::setPosition" ) 
{
    GU::Al::SatObject sat(Math::Vector2<float>(100, 100), 3 );
    sat.setPosition({400, 50}); 
    
    REQUIRE(Catch::Approx(sat.getPosition().x) == 400);
    REQUIRE(Catch::Approx(sat.getPosition().y) == 50);
}


TEST_CASE( "SatObject::getPosition" ) 
{
    GU::Al::SatObject sat(Math::Vector2<float>(250, 375), 3 );
    
    REQUIRE(Catch::Approx(sat.getPosition().x) == 250);
    REQUIRE(Catch::Approx(sat.getPosition().y) == 375);
}


TEST_CASE( "SatObject::getEdge" ) 
{
    const int SIZE = 3;
    GU::Al::SatObject sat(Math::Vector2<float>(100, 100), SIZE );

    Math::Line<float> edge1 = sat.getEdge(0);
    REQUIRE(Catch::Approx(edge1.m_Start.x) == 100);
    REQUIRE(Catch::Approx(edge1.m_Start.y) == 100);
    REQUIRE(Catch::Approx(edge1.m_End.x) == 100);
    REQUIRE(Catch::Approx(edge1.m_End.y) == 100);

    Math::Line<float> edge2 = sat.getEdge(1);
    REQUIRE(Catch::Approx(edge2.m_Start.x) == 100);
    REQUIRE(Catch::Approx(edge2.m_Start.y) == 100);
    REQUIRE(Catch::Approx(edge2.m_End.x) == 100);
    REQUIRE(Catch::Approx(edge2.m_End.y) == 100);

    Math::Line<float> edge3 = sat.getEdge(2);
    REQUIRE(Catch::Approx(edge3.m_Start.x) == 100);
    REQUIRE(Catch::Approx(edge3.m_Start.y) == 100);
    REQUIRE(Catch::Approx(edge3.m_End.x) == 100);
    REQUIRE(Catch::Approx(edge3.m_End.y) == 100);

    REQUIRE_THROWS(sat.getEdge(SIZE));
}


TEST_CASE( "SatObject::getGlobalCoordiante" ) 
{
    GU::Al::SatObject sat(Math::Vector2<float>(250, 375), 3 );
    sat.setLocalCoordinate(Math::Vector2<float>(100, 100), 0);
    sat.setLocalCoordinate(Math::Vector2<float>(150, 150), 1);
    sat.setLocalCoordinate(Math::Vector2<float>(0, 150), 2);
    
    REQUIRE(Catch::Approx(sat.getGlobalCoordinate(0).x) == 350);
    REQUIRE(Catch::Approx(sat.getGlobalCoordinate(0).y) == 475);
    REQUIRE(Catch::Approx(sat.getGlobalCoordinate(1).x) == 400);
    REQUIRE(Catch::Approx(sat.getGlobalCoordinate(1).y) == 525);
    REQUIRE(Catch::Approx(sat.getGlobalCoordinate(2).x) == 250);
    REQUIRE(Catch::Approx(sat.getGlobalCoordinate(2).y) == 525);
    REQUIRE_THROWS(sat.getGlobalCoordinate(3)); 

}


TEST_CASE( "SatObject::getLocalCoordiante" ) 
{
    GU::Al::SatObject sat(Math::Vector2<float>(250, 375), 3 );
    sat.setLocalCoordinate(Math::Vector2<float>(100, 100), 0);
    sat.setLocalCoordinate(Math::Vector2<float>(150, 150), 1);
    sat.setLocalCoordinate(Math::Vector2<float>(0, 150), 2);
    
    REQUIRE(Catch::Approx(sat.getLocalCoordinate(0).x) == 100);
    REQUIRE(Catch::Approx(sat.getLocalCoordinate(0).y) == 100);
    REQUIRE(Catch::Approx(sat.getLocalCoordinate(1).x) == 150);
    REQUIRE(Catch::Approx(sat.getLocalCoordinate(1).y) == 150);
    REQUIRE(Catch::Approx(sat.getLocalCoordinate(2).x) == 0);
    REQUIRE(Catch::Approx(sat.getLocalCoordinate(2).y) == 150);
    REQUIRE_THROWS(sat.getGlobalCoordinate(10)); 
}


