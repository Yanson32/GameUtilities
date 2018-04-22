#include "TestState.h"
#include <GameUtilities/Engin/Engin.h>
#include <SFML/Graphics/Color.hpp>
#include <iostream>

TestState::TestState(GU::Engin::Engin& engin):
m_Engin(engin),
m_Window(sf::VideoMode({800, 600}), "Engin Example")
{
    if(!font.loadFromFile("Resources/Fonts/CaviarDreams.ttf"))
    {
        std::cerr << "Could not load font CaviarDreams.ttf" << std::endl;
    }

    text.setFont(font);
    text.setCharacterSize(50);
    text.setString("Engin Test");
    text.setColor(sf::Color::Red);
}


/*********************************************************************************//**           		*   \brief	Initialize the game state.
*************************************************************************************/
void TestState::Init()
{

}

/*********************************************************************************//**
*   \brief	Clean any resource the state uses
*************************************************************************************/
void TestState::Clean()
{

}

/*********************************************************************************//**
*   \brief	This method handles input such as user input and events
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void TestState::HandleEvents(GU::Engin::Engin& engin, const int &deltaTime)
{
    if(m_Window.isOpen())
    {
        sf::Event event;

        while (m_Window.pollEvent(event))
        {
            handleSFEvent(engin, event);
        }

    }
}


/*********************************************************************************//**
*   \brief	This method handles input such as user input and events
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void TestState::Update(GU::Engin::Engin& engin, const int &deltaTime)
{
    if(!IsPaused())
    {
        //Do game logic
    }
}


/*********************************************************************************//**
*   \brief	This method draws the current game state.
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void TestState::Draw(GU::Engin::Engin& engin, const int &deltaTime)
{
    m_Window.clear();
    m_Window.draw(text);
    m_Window.display();
}

void TestState::handleSFEvent(GU::Engin::Engin& engin, sf::Event event)
{
    switch (event.type)
    {

        case sf::Event::Closed:
            engin.Quit();
            break;
    }
}
