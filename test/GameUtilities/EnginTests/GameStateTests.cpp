#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <GameUtilities/Engin/Engin.h>
#include <GameUtilities/Engin/GameState.h>
#include <boost/test/unit_test.hpp>
#include <memory>

class TestState: public GU::Engin::GameState
{
	public:
		TestState(){}
		        /*********************************************************************************//**
                *   \brief	Initialize the game state.
                *************************************************************************************/
                virtual void Init() {};

                /*********************************************************************************//**
                *   \brief	Clean any resource the state uses
                *************************************************************************************/
                virtual void Clean(){};

                /*********************************************************************************//**
                *   \brief	This method handles input such as user input and events
                *	\param	engin is a reference to the game's Engin object.
                *************************************************************************************/
                virtual void HandleEvents(GU::Engin::Engin& engin, const int &deltaTime) {};


                /*********************************************************************************//**
                *   \brief	This method handles input such as user input and events
                *	\param	engin is a reference to the game's Engin object.
                *************************************************************************************/
                virtual void Update(GU::Engin::Engin& engin, const int &deltaTime) {};


                /*********************************************************************************//**
                *   \brief	This method draws the current game state.
                *	\param	engin is a reference to the game's Engin object.
                *************************************************************************************/
                virtual void Draw(GU::Engin::Engin& engin, const int &deltaTime) {};
};

BOOST_AUTO_TEST_CASE( GameState_Constructors )
{
	GU::Engin::Engin engin;

	//There should not be any states on the stack when 
	BOOST_CHECK(engin.Size() == 0);
}


BOOST_AUTO_TEST_CASE( GameState_HandleEvents )
{

}


BOOST_AUTO_TEST_CASE( GameState_Update )
{

}


BOOST_AUTO_TEST_CASE( GameState_Draw )
{

}



