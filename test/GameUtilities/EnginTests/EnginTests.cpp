#include <catch2/catch_test_macros.hpp>
#include <GameUtilities/Engin/Engin.h>
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

TEST_CASE( "Engin class Single argument constructor", "[Engin::Constructor]" ) {
    GU::Engin::Engin engin;
    REQUIRE( engin.Size() == 0 );
}

TEST_CASE( "Engin class Push method", "[Engin::Push]" ) {
    GU::Engin::Engin engin;
    std::unique_ptr<TestState> state(new TestState);
    engin.Push(std::move(state));
    REQUIRE( engin.Size() == 1 );
    engin.Push<TestState>();
    REQUIRE( engin.Size() == 2 );
}
