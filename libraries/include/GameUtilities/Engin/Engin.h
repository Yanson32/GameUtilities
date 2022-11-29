#ifndef GAMEUTILITIES_ENGIN_ENGIN_H
#define GAMEUTILITIES_ENGIN_ENGIN_H
/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
*	@date 12/10/17
*   @file Engin.h
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
#include <memory>
#include "GameUtilities/Engin/GameState.h"
#include "engin_export.h"
namespace GU
{
    namespace Engin
    {

        /*********************************************************************************//**
        *	@class Engin
        *	@brief	This is the main game engin class
        *************************************************************************************/
        class ENGIN_EXPORT Engin
        {
            public:
                /// Pointer type for a state
				typedef std::unique_ptr<GameState> StatePtr;    


                /*********************************************************************************//**
                *   @brief	Default constructor
                *************************************************************************************/
                Engin();

                
                /*********************************************************************************//**
                *   @brief  Deleted copy constructor
                *   @param  other is the Engin object to be copied
                *************************************************************************************/
                Engin(const Engin& other) = delete;
                

                /*********************************************************************************//**
                *   @brief  Move constructor. 
                *   @param  param is the Engin object to be moved. 
                *************************************************************************************/
                Engin(Engin&& param);


                /*********************************************************************************//**
                *   @brief  Deleted assignment operator.
                *   @param  param is the Engin object to be assigned. 
                *   @return A reference to the current Engin object.
                *************************************************************************************/
                Engin& operator=(const Engin& param) = delete;
                

                /*********************************************************************************//**
                *   @brief  Move assignment operator. 
                *   @param  param is the Engin object to be moved. 
                *   @return A reference to the current Engin object.
                *************************************************************************************/
                Engin& operator=(Engin&& param);


                /*********************************************************************************//**
                *	@brief	Push a new state onto the stack
                *   @param	state a pointer to a GameState object.
                *************************************************************************************/
                void push(StatePtr state);


                /**************************************************************************//**
                *   @brief	Push a new state onto the stack. The state will be created
                *           Internally. The user specifies the type of state and passes
                *           any arguments needed by the states constructor.
                *   @tparam  Type the type of gamestate to be created
                *	@param	args these arguments will be passed to the GameState subclass to
                *			construct a GameState object.
                ******************************************************************************/
                template<typename Type, typename... Args>
                void push(Args&&... args);


                /*********************************************************************************//**
                *   @brief Remove a state from the stack
                *   @return boolean true when the state is successfully removed
                *           from the stack.
                *************************************************************************************/
                bool pop();


                /*********************************************************************************//**
                *   @brief 	Remove any existing GameState objects from the stack, and push
                *           A new GameState object onto the stack.
                *   @param	state a pointer to a GameState object.
                *************************************************************************************/
                void changeState(StatePtr param);


                /**************************************************************************//**
                *   @brief	Remove any existing GameState objects from the stack, and push
                *           A new GameState object onto the stack. The new state will be
                *           created internally the user specifies the type of state, and
                *           passes any arguments needed by the states constructor.
                *	@param	args these arguments will be passed to the GameState subclass to
                *			construct a GameState object.
                *   @tparam Type this is the type of GameState.
                ******************************************************************************/
                template<typename Type, typename... Args>
                void changeState(Args&&... args);


                /*********************************************************************************//**
                *   @brief	This method is used to determine if the game is still running.
                *	@return boolean true when the game is running and false otherwise
                *************************************************************************************/
                bool isRunning() const;


                /*********************************************************************************//**
                *   @brief	This method is used to end the game.
                *	@post   After calling this method IsRunning() returns false.
                *************************************************************************************/
                void quit();


                /*********************************************************************************//**
                *   @brief  This method returns true when there are no states stored in the engin
                *	@return	True when there are no states stored in the engin and false otherwise.
                *************************************************************************************/
                bool empty() const;
                

                /*********************************************************************************//**
                *   @brief	This method is used to call an equivalent method in a GameState
                *           class. Which will have code for handling all kinds of input
                *           include events and user input.
                *   @param  deltaTime is the time the previous frame took
                *************************************************************************************/
                void handleEvents(const float &deltaTime);


                /*********************************************************************************//**
                *   @brief	 This method is used to call an equivalent method in a GameState
                *            class. Which will have code for handling game logic.
                *   @param  deltaTime is the time the previous frame took
                *************************************************************************************/
                void update(const float &deltaTime);


                /*********************************************************************************//**
                *   @brief  This method draws a single frame of the game.	
                *   @param  deltaTime is the time the previous frame took
                *************************************************************************************/
                void draw(const float &deltaTime);


                /*********************************************************************************//**
                *   @brief  This method returns the number of states currently stored in the engin.	
                *   @return The number of states currently stored in the engin. 
                *************************************************************************************/
                int size() const;
                

                /*********************************************************************************//**
                *   @brief	Destructor:
                *************************************************************************************/
                virtual ~Engin();
            private:
				class Impl;
				Impl* m_pimpl = nullptr;        /**< A pointer to the class implimentation */
        };


        /**************************************************************************//**
        *   @brief	Push a new state onto the stack. The state will be created
        *           Internally. The user specifies the type of state and passes
        *           any arguments needed by the states constructor.
        *   @tparam  Type the type of gamestate to be created
        *	@param	args these arguments will be passed to the GameState subclass to
        *			construct a GameState object.
        ******************************************************************************/
        template<typename Type, typename... Args>
        void Engin::push(Args&&... args)
        {
            this->push(StatePtr(new Type(std::forward<Args>(args)...)));
        }


        /**************************************************************************//**
        *   @brief	Remove any existing GameState objects from the stack, and push
        *           A new GameState object onto the stack. The new state will be
        *           created internally the user specifies the type of state, and
        *           passes any arguments needed by the states constructor.
        *	@param	args these arguments will be passed to the GameState subclass to
        *			construct a GameState object.
        *   @tparam  Type this is the type of GameState.
        ******************************************************************************/
        template<typename Type, typename... Args>
        void Engin::changeState(Args&&... args)
        {
            this->changeState(StatePtr(new Type(std::forward<Args>(args)...)));
        }
    }
}
#endif // ENGIN_H
