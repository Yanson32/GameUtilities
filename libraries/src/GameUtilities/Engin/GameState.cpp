#include "GameUtilities/Engin/GameState.h"

namespace GU
{

    namespace Engin
    {


        /*********************************************************************************//**
        *   \brief	Default constructor
        *************************************************************************************/
        GameState::GameState()
        {
            //ctor
        }


        /*********************************************************************************//**
        *   \brief	This method draws the current game state.
        *	\param [in]	pause when true the game will stop. When false the game will continue
        *************************************************************************************/
        void GameState::Pause(const bool pause)
        {
            paused = pause;
        }


        /*********************************************************************************//**
        *   \brief	This method returns a boolean true when the game is paused and false
        *			otherwise
        *	\return	boolean true when the game is paused and false otherwise
        *************************************************************************************/
        bool GameState::IsPaused()const
        {
            return paused;
        }


        /*********************************************************************************//**
        *   \brief	Destructor
        *************************************************************************************/
        GameState::~GameState()
        {
            //dtor
        }
    }

}
