/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
*	@date   12/10/17
*   @file   GameState.h
*************************************************************************************/

/*************************************************************************
*                           COPYRIGHT NOTICE
* GameUtilities is a toolkit for making 2d video games.
* Copyright (C) 2018 Wayne J Larson Jr. 
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 3 as 
* published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
***************************************************************************/
#ifndef GAMEUTILITIES_ENGIN_GAMESTATE_H
#define GAMEUTILITIES_ENGIN_GAMESTATE_H
#include "engin_export.h"
#include <memory>

namespace GU
{

    namespace Engin
    {
        class Engin;

        /*********************************************************************************//**
        *	@brief	This is the base class used by all game states.
        *	@class GameState
        *************************************************************************************/
        class ENGIN_EXPORT GameState
        {
            public:
                /// Engin pointer typedef
                typedef GU::Engin::Engin * const EnginPtr;


                /*********************************************************************************//**
                *   @brief	Default constructor
                *************************************************************************************/
                GameState();


                /*********************************************************************************//**
                *   @brief	Initialize the game state.
                *************************************************************************************/
                virtual void init() = 0;

                /*********************************************************************************//**
                *   @brief	Clean any resource the state uses
                *************************************************************************************/
                virtual void clean() = 0;

                /*********************************************************************************//**
                *   @brief	This method handles input such as user input and events
                *	@param	engin is a reference to the game's Engin object.
                *	@param	deltaTime is the length of time a single frame takes 
                *************************************************************************************/
                virtual void handleEvents(EnginPtr engin, const float &deltaTime) = 0;


                /*********************************************************************************//**
                *   @brief	This method handles input such as user input and events
                *	@param	engin is a reference to the game's Engin object.
                *	@param	deltaTime is the length of time a single frame takes 
                *************************************************************************************/
                virtual void update(EnginPtr engin, const float &deltaTime) = 0;


                /*********************************************************************************//**
                *   @brief	This method draws the current game state.
                *	@param	engin is a reference to the game's Engin object.
                *	@param	deltaTime is the length of time a single frame takes 
                *************************************************************************************/
                virtual void draw(EnginPtr engin, const float &deltaTime) = 0;


                /*********************************************************************************//**
                *   @brief	This method draws the current game state.
                *	@param	pause when true the game will stop. When false the game will continue
                *************************************************************************************/
                void pause(const bool pause = true);


                /*********************************************************************************//**
                *   @brief	This method returns a boolean true when the game is paused and false
                *			otherwise
                *	@return	boolean true when the game is paused and false otherwise
                *************************************************************************************/
                bool isPaused()const;

                /*********************************************************************************//**
                *   @brief	Destructor
                *************************************************************************************/
                virtual ~GameState();
            private:
                ///true when the game is paused and false otherwise  
                bool m_paused = false;      
        };
    }
}
#endif // GAMESTATE_H
