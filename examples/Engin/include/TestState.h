#ifndef ENGIN_TEST_STATE_H
#define ENGIN_TEST_STATE_H
#include <GameUtilities/Engin/GameState.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

class TestState: public GU::Engin::GameState
{
	public:
		TestState(GU::Engin::Engin& engin);
    	/*********************************************************************************//**           			*   \brief	Initialize the game state.
        *************************************************************************************/
        virtual void Init();

        /*********************************************************************************//**
        *   \brief	Clean any resource the state uses
        *************************************************************************************/
        virtual void Clean();

        /*********************************************************************************//**
        *   \brief	This method handles input such as user input and events
        *	\param	engin is a reference to the game's Engin object.
        *************************************************************************************/
        virtual void HandleEvents(GU::Engin::Engin& engin, const int &deltaTime);


        /*********************************************************************************//**
        *   \brief	This method handles input such as user input and events
        *	\param	engin is a reference to the game's Engin object.
        *************************************************************************************/
        virtual void Update(GU::Engin::Engin& engin, const int &deltaTime);


        /*********************************************************************************//**
        *   \brief	This method draws the current game state.
        *	\param	engin is a reference to the game's Engin object.
        *************************************************************************************/
        virtual void Draw(GU::Engin::Engin& engin, const int &deltaTime);

        void handleSFEvent(GU::Engin::Engin& engin, sf::Event event);
    private:
    GU::Engin::Engin &m_Engin;
    sf::RenderWindow m_Window;
    sf::Text text;
    sf::Font font;
};
#endif
