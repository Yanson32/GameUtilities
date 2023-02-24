/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
*	@date   12/10/17
*   @file   GameState.cpp
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
#include "GameUtilities/Engin/GameState.h"

namespace GU
{

    namespace Engin
    {


        /*********************************************************************************//**
        *   @brief	Default constructor
        *************************************************************************************/
        GameState::GameState()
        {
            //ctor
        }


        /*********************************************************************************//**
        *   @brief This method draws the current game state.
        *	@param pause when true the game will stop. When false the game will continue
        *************************************************************************************/
        void GameState::pause(const bool pause)
        {
            m_paused = pause;
        }


        /*********************************************************************************//**
        *   @brief	This method returns a boolean true when the game is paused and false
        *			otherwise
        *	@return	boolean true when the game is paused and false otherwise
        *************************************************************************************/
        bool GameState::isPaused()const
        {
            return m_paused;
        }


        /*********************************************************************************//**
        *   @brief	Destructor
        *************************************************************************************/
        GameState::~GameState()
        {
            //dtor
        }
    }

}
