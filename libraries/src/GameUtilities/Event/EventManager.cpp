/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
*	@date 	12/10/17
*   @file   EventManager.cpp
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
#include "GameUtilities/Event/EventManager.h"
#include <cassert>

namespace GU
{
    namespace Evt
    {

        /**********************************************************************//**
        *	@brief	Constructor
        **************************************************************************/
        EventManager::EventManager()
        {
            //ctor
        }


        /**********************************************************************//**
        *	@brief  This method returns a static instance of the EventManager class.	
        *   @return An instance of the EventManager class.
        **************************************************************************/
        EventManager& EventManager::inst()
        {
	        static EventManager eventManager;
	        return eventManager;
        }

    //    bool Manager::RegisterListener(Evt::Listener *listener)
    //    {
    //        assert(listener != nullptr);
    //        _listeners.push_back(listener);
    //        return true;
    //    }


    //    void Manager::ProcessEvent(const Evt::Event &event)
    //    {
    //        for(auto element: _listeners)
    //        {
    //            assert(element != nullptr);
    //            element->ProcessEvent(event);
    //        }
    //
    //    }
    //    void Manager::Post( std::unique_ptr<Evt::Event> event)
    //    {
    //        _eventQueue.push(std::move(event));
    //    }


        /**********************************************************************//**
        *	@brief	Destructor
        **************************************************************************/
        EventManager::~EventManager()
        {
            //dtor
        }

    }
}
