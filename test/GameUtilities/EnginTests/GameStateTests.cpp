#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <GameUtilities/Engin/GameState.h>

class TestState: public GU::Engin::GameState
{
    public:

        /*********************************************************************************//**
        *   \brief	Initialize the game state.
        *************************************************************************************/
        virtual void Init() {};

        /*********************************************************************************//**
        *   \brief	Clean any resource the state uses
        *************************************************************************************/
        virtual void Clean() {};

        /*********************************************************************************//**
        *   \brief	This method handles input such as user input and events
        *	\param	engin is a reference to the game's Engin object.
        *************************************************************************************/
        virtual void HandleEvents(GU::Engin::Engin& engin, const float &deltaTime) {};


        /*********************************************************************************//**
        *   \brief	This method handles input such as user input and events
        *	\param	engin is a reference to the game's Engin object.
        *************************************************************************************/
        virtual void Update(GU::Engin::Engin& engin, const float &deltaTime) {};


        /*********************************************************************************//**
        *   \brief	This method draws the current game state.
        *	\param	engin is a reference to the game's Engin object.
        *************************************************************************************/
        virtual void Draw(GU::Engin::Engin& engin, const float &deltaTime) {};

        virtual ~TestState(){}
};

TEST_CASE( "GameState class default constructor", "[Default Constructor]" ) {
    TestState state;
    REQUIRE( state.IsPaused() == false);
}

TEST_CASE( "GameState class copy constructor", "[Copy Constructor]" ) {
    TestState state;
    state.Pause(true);
    TestState state2(state);
    REQUIRE( state2.IsPaused() == true);
}

TEST_CASE( "GameState class assignment operator", "[Assignment]" ) {
    TestState state;
    state.Pause(true);
    TestState state2;
    state2 = state;
    REQUIRE( state2.IsPaused() == true);
}

TEST_CASE( "GameState class IsPaused", "[IsPaused]" ) {
    TestState state;
    REQUIRE( state.IsPaused() == false);
}

TEST_CASE( "GameState class Pause", "[Pause]" ) {
    TestState state;
    state.Pause(true);
    REQUIRE( state.IsPaused() == true);
}
