/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
*	@date 12/10/17
*   @file Engin.cpp
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
#include "GameUtilities/Engin/Engin.h"
#include <cassert>
#include <stack>

namespace GU
{

    namespace Engin
    {


        /*************************************************************************
        *   @author Wayne J Larson Jr.
        *   @brief  Implimentation of the Engin class.
        *   @date   3/20/18
        *************************************************************************/
		class Engin::Impl
		{
			public:
				typedef GU::Engin::Engin::StatePtr StatePtr; //pointer to gamestate

                
                /*********************************************************************************//**
                *   @brief	Default constructor
                *************************************************************************************/
                Impl();

                
                /*********************************************************************************//**
                *   @brief	Destructor:
                *************************************************************************************/
                virtual ~Impl();

            public:
				///stack of states the state on the top of the stack is the current state
				std::stack<StatePtr> m_states;

				///true while the game is running and false otherwise
				bool m_running = true;
		};


        /*********************************************************************************//**
        *   @brief	Default constructor
        *************************************************************************************/
        Engin::Impl::Impl()
        {

        }


        /*********************************************************************************//**
        *   @brief	Destructor:
        *************************************************************************************/
        Engin::Impl::~Impl()
        {

        }


        /*********************************************************************************//**
        *   @brief	Default constructor
        *************************************************************************************/
        Engin::Engin(): m_pimpl(new Engin::Impl())
        {
            //ctor

        }


        /*********************************************************************************//**
        *   @brief  Move constructor. 
        *   @param  param is the Engin object to be moved. 
        *************************************************************************************/
        Engin::Engin(Engin&& param)
        {
            if(m_pimpl)
                delete m_pimpl;

            m_pimpl = param.m_pimpl;
            param.m_pimpl = nullptr;
        }


        /*********************************************************************************//**
        *   @brief  Move assignment operator. 
        *   @param  param is the Engin object to be moved. 
        *   @return A reference to the current Engin object.
        *************************************************************************************/
        Engin& Engin::operator=(Engin&& param)
        {
            assert(m_pimpl != nullptr);
            assert(param.m_pimpl != nullptr);
            m_pimpl = param.m_pimpl;

			return *this;
        }


        /*********************************************************************************//**
        *	@brief	Push a new state onto the stack.
        *   @param	state a pointer to a GameState object.
        *************************************************************************************/
        void Engin::push(StatePtr state)
        {
            assert(m_pimpl != nullptr);
			if (!m_pimpl->m_states.empty())
			{
				m_pimpl->m_states.top()->pause();
				m_pimpl->m_states.top()->clean();
			}

			m_pimpl->m_states.push(std::move(state));
			m_pimpl->m_states.top()->init();
        }


        /*********************************************************************************//**
        *   @brief Remove a state from the stack
        *   @return boolean true when the state is successfully removed
        *           from the stack.
        *************************************************************************************/
        bool Engin::pop()
        {
            assert(m_pimpl != nullptr);
			
            if(m_pimpl->m_states.empty())
			{
				return false;
			}


			m_pimpl->m_states.top()->clean();
			m_pimpl->m_states.pop();

			if (!m_pimpl->m_states.empty())
			{
				m_pimpl->m_states.top()->init();
				m_pimpl->m_states.top()->pause(false);
			}

			return true;
        }


        /*********************************************************************************//**
        *   @brief 	Remove any existing GameState objects from the stack, and push
        *           A new GameState object onto the stack.
        *   @param	state a pointer to a GameState object.
        *************************************************************************************/
        void Engin::changeState(StatePtr state)
        {
			assert(state != nullptr);


			///Remove any existing states
			while (!m_pimpl->m_states.empty())
				this->pop();

			///Push the state onto the now empty stack
			this->push(std::move(state));
        }


        /*********************************************************************************//**
        *   @brief	This method is used to determine if the game is still running.
        *	@return boolean true when the game is running and false otherwise
        *************************************************************************************/
        bool Engin::isRunning() const
        {
            assert(m_pimpl != nullptr);
			return m_pimpl->m_running;
        }


        /*********************************************************************************//**
        *   @brief	This method is used to end the game.
        *	@post   After calling this method IsRunning() returns false.
        *************************************************************************************/
        void Engin::quit()
        {
            assert(m_pimpl != nullptr);
			m_pimpl->m_running = false;
        }

        
        /*********************************************************************************//**
        *   @brief  This method returns true when there are no states stored in the engin
        *	@return	True when there are no states stored in the engin and false otherwise.
        *************************************************************************************/
        bool Engin::empty() const
        {
            assert(m_pimpl != nullptr);
            return m_pimpl->m_states.empty();
        }


        /*********************************************************************************//**
        *   @brief	This method is used to call an equivalent method in a GameState
        *           class. Which will have code for handling all kinds of input
        *           include events and user input.
        *   @param  deltaTime is the time the previous frame took
        *************************************************************************************/
        void Engin::handleEvents(const float &deltaTime)
        {
            assert(m_pimpl != nullptr);
			assert(!m_pimpl->m_states.empty());

			///Call the current states HandleEvents method.
			m_pimpl->m_states.top()->handleEvents(this, deltaTime);
        }


        /*********************************************************************************//**
        *   @brief	 This method is used to call an equivalent method in a GameState
        *            class. Which will have code for handling game logic.
        *   @param  deltaTime is the time the previous frame took
        *************************************************************************************/
        void Engin::update(const float &deltaTime)
        {
            assert(m_pimpl != nullptr);
			assert(!m_pimpl->m_states.empty());

			///Call the current states Update method.
			m_pimpl->m_states.top()->update(this, deltaTime); }

        /*********************************************************************************//**
        *   @brief  This method draws a single frame of the game.	
        *   @param  deltaTime is the time the previous frame took
        *************************************************************************************/
        void Engin::draw(const float &deltaTime)
        {
            assert(m_pimpl != nullptr);
			assert(!m_pimpl->m_states.empty());

			///Call the current states Draw method.
			m_pimpl->m_states.top()->draw(this, deltaTime);
        }

        
        /*********************************************************************************//**
        *   @brief  This method returns the number of states currently stored in the engin.	
        *   @return The number of states currently stored in the engin. 
        *************************************************************************************/
        int Engin::size() const
        {
            assert(m_pimpl != nullptr);
            return m_pimpl->m_states.size();
        }


        /*********************************************************************************//**
        *   @brief	Destructor:
        *************************************************************************************/
        Engin::~Engin()
        {
            //dtor
            if(m_pimpl != nullptr)
            {
                delete m_pimpl;
                m_pimpl = nullptr;
            }
        }
    }

}
