#ifndef ENGIN_TEST_STATE_H
#define ENGIN_TEST_STATE_H
#include <GameUtilities/Engin/GameState.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <Box2D/Box2D.h>
#include "DebugDraw.h"
#include "MouseJoint.h"
#include "ObjectBase.h"
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
    b2World m_World;
    DebugDraw m_DebugDraw;
    MouseJoint *m_MouseJoint = nullptr;
    int32 m_VelocityIterations = 4;
    int32 m_PositionIterations = 10;
    GU::Engin::Engin &m_Engin;
    sf::RenderWindow m_Window;
    std::vector<ObjectBase> m_Objects;
    b2Body* dynamicBody = nullptr;

};
#endif
