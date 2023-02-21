#include <catch2/catch_test_macros.hpp>
#include <GameUtilities/Engin/GameState.h>

class TestState: public GU::Engin::GameState
{
    public:

        /*********************************************************************************//**
        *   \brief	Initialize the game state.
        *************************************************************************************/
        virtual void init(std::shared_ptr<GU::Engin::Frame> frame) {};

        /*********************************************************************************//**
        *   \brief	Clean any resource the state uses
        *************************************************************************************/
        virtual void clean(std::shared_ptr<GU::Engin::Frame> frame) {};

        /*********************************************************************************//**
        *   \brief	This method handles input such as user input and events
        *	\param	engin is a reference to the game's Engin object.
        *************************************************************************************/
        virtual void handleEvents(GU::Engin::Engin& engin, const float &deltaTime, std::shared_ptr<GU::Engin::Frame> frame) {};


        /*********************************************************************************//**
        *   \brief	This method handles input such as user input and events
        *	\param	engin is a reference to the game's Engin object.
        *************************************************************************************/
        virtual void update(GU::Engin::Engin& engin, const float &deltaTime, std::shared_ptr<GU::Engin::Frame> frame) {};


        /*********************************************************************************//**
        *   \brief	This method draws the current game state.
        *	\param	engin is a reference to the game's Engin object.
        *************************************************************************************/
        virtual void draw(GU::Engin::Engin& engin, const float &deltaTime, std::shared_ptr<GU::Engin::Frame> frame) {};

        virtual ~TestState(){}
};

TEST_CASE( "GameState class default constructor", "[Default Constructor]" ) {
    TestState state;
    REQUIRE( state.isPaused() == false);
}

TEST_CASE( "GameState class copy constructor", "[Copy Constructor]" ) {
    TestState state;
    state.pause(true);
    TestState state2(state);
    REQUIRE( state2.isPaused() == true);
}

TEST_CASE( "GameState class assignment operator", "[Assignment]" ) {
    TestState state;
    state.pause(true);
    TestState state2;
    state2 = state;
    REQUIRE( state2.isPaused() == true);
}

TEST_CASE( "GameState class IsPaused", "[IsPaused]" ) {
    TestState state;
    REQUIRE( state.isPaused() == false);
}

TEST_CASE( "GameState class Pause", "[Pause]" ) {
    TestState state;
    state.pause(true);
    REQUIRE( state.isPaused() == true);
}
