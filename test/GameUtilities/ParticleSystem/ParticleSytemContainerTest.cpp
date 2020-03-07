#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <GameUtilities/ParticleSystem/Container.h>

TEST_CASE("ParticleSystem::Container Single argument constructor", "[Constructor]" ) {
    GU::PS::Container<float> cont(10);
    REQUIRE( cont.size() == 0 );
}

TEST_CASE("ParticleSystem::Container Bracket operator", "[Bracket]")
{
    GU::PS::Container<int> cont(10);
    cont.emplace_back(5);
    REQUIRE(cont[0] == 5);
}

TEST_CASE("ParticleSystem::Container emplace_back method", "[EmplaceBack]")
{
    GU::PS::Container<int> cont(10);
    cont.emplace_back<int>(6);

    REQUIRE(cont.size() == 1);
}

TEST_CASE("ParticleSystem::Container size method", "[Size]")
{
    GU::PS::Container<int> cont(10);

    REQUIRE(cont.size() == 0);
}

TEST_CASE("ParticleSystem::Container remove method", "[Remove]")
{
    GU::PS::Container<int> cont(10);
    cont.emplace_back<int>(0);
    cont.emplace_back<int>(1);
    cont.emplace_back<int>(2);
    cont.remove(1);
    REQUIRE(cont.size() == 2);
    REQUIRE(cont.capacity() == 10);
    REQUIRE(cont[0] == 0);
    REQUIRE(cont[1] == 2);
    
}

TEST_CASE("ParticleSystem::Container capacity method", "[Capacity]")
{
    GU::PS::Container<int> cont(10);
    REQUIRE(cont.capacity() == 10);
}
