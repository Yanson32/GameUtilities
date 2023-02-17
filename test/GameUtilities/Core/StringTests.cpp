#include <catch2/catch_test_macros.hpp>
#include <GameUtilities/Core/String.h>
#include <iostream>

TEST_CASE( "String class default constructor", "[String::DefaultConstructor]" ) 
{
    GU::Core::String test1;
    REQUIRE(test1 == GU::Core::String(""));
}

TEST_CASE( "String class single argument constructor", "[String::SingleConstructor]" ) 
{
    GU::Core::String test1("Hello");
    REQUIRE( test1  == GU::Core::String("Hello"));
}

TEST_CASE( "String class copy constructor", "[String::Copy]" ) 
{
    GU::Core::String test1("Hello");
    GU::Core::String test2 = test1;
    REQUIRE( test1  == GU::Core::String("Hello"));
}

TEST_CASE( "String class equality operator", "[String::Equality]" ) 
{
    GU::Core::String test1("Hello");
    GU::Core::String test2("Hello");
    REQUIRE( test1  == GU::Core::String("Hello"));
    REQUIRE( test1  == test2);

    const char* const test3 = "Hello";
    REQUIRE( test1  == test3);
}

TEST_CASE( "String class not equal operator", "[String::Unequal]" ) 
{
    GU::Core::String test1("Hello");
    GU::Core::String test2("World");
    
    REQUIRE( test1  != GU::Core::String("World"));
    REQUIRE( test1  != test2);

    const char* const test3 = "World";
    REQUIRE( test1  != test3);
}

TEST_CASE( "String class foreach loop", "[String::Foreach]" ) 
{
    GU::Core::String test("123456");

    int count = 1;

    for(auto &element: test)
    {
        REQUIRE(element == static_cast<char>(count + '0'));

        count += 1;
    }
}

