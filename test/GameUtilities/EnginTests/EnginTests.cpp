#include <catch2/catch_test_macros.hpp>
#include <GameUtilities/Engin/Engin.h>
#include <GameUtilities/Engin/GameState.h>
#include <GameUtilities/Core/Macros.h>
class TestState: public GU::Engin::GameState
{
    public:

        /*********************************************************************************//**
        *   \brief	Initialize the game state.
        *************************************************************************************/
        virtual void init() override;

        /*********************************************************************************//**
        *   \brief	Clean any resource the state uses
        *************************************************************************************/
        virtual void clean() override;

        /*********************************************************************************//**
        *   \brief	This method handles input such as user input and events
        *	\param	engin is a reference to the game's Engin object.
        *************************************************************************************/
        virtual void handleEvents(GU::Engin::GameState::EnginPtr engin, const float &deltaTime) override;


        /*********************************************************************************//**
        *   \brief	This method handles input such as user input and events
        *	\param	engin is a reference to the game's Engin object.
        *************************************************************************************/
        virtual void update(GU::Engin::GameState::EnginPtr engin, const float &deltaTime) override;


        /*********************************************************************************//**
        *   \brief	This method draws the current game state.
        *	\param	engin is a reference to the game's Engin object.
        *************************************************************************************/
        virtual void draw(GU::Engin::GameState::EnginPtr engin, const float &deltaTime) override;

        virtual ~TestState();
};

/*********************************************************************************//**
*   \brief	Initialize the game state.
*************************************************************************************/
void TestState::init()
{

}

/*********************************************************************************//**
*   \brief	Clean any resource the state uses
*************************************************************************************/
void TestState::clean()
{

}

/*********************************************************************************//**
*   \brief	This method handles input such as user input and events
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void TestState::handleEvents(GU::Engin::GameState::EnginPtr engin, const float &deltaTime)
{
    UNUSED(engin);
    UNUSED(deltaTime); 
}


/*********************************************************************************//**
*   \brief	This method handles input such as user input and events
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void TestState::update(GU::Engin::GameState::EnginPtr engin, const float &deltaTime)
{
    UNUSED(engin);
    UNUSED(deltaTime); 
}


/*********************************************************************************//**
*   \brief	This method draws the current game state.
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void TestState::draw(GU::Engin::GameState::EnginPtr engin, const float &deltaTime)
{
    UNUSED(engin);
    UNUSED(deltaTime); 
}

TestState::~TestState()
{

}


TEST_CASE( "Engin class Single argument constructor", "[Engin::Constructor]" ) {
    GU::Engin::Engin engin;
    REQUIRE( engin.size() == 0 );
}

TEST_CASE( "Engin class Push method", "[Engin::Push]" ) {
    GU::Engin::Engin engin;
    std::unique_ptr<TestState> state(new TestState);
    engin.push(std::move(state));
    REQUIRE( engin.size() == 1 );
    engin.push<TestState>();
    REQUIRE( engin.size() == 2 );
}
