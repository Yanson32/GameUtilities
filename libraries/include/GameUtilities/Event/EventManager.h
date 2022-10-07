#ifndef GAMEUTILITIES_EVENT_MANAGER_H
#define GAMEUTILITIES_EVENT_MANAGER_H
/*********************************************************************************//**
*	@author	        Wayne J Larson Jr.
*	@date 	        12/10/17
*	@description    This class is usded as the central location where the games events
*			        are managed.
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
#include "event_export.h"
#include "GameUtilities/Event/EventQueue.h"
#include "GameUtilities/Event/Dispatcher.h"

namespace GU
{
    namespace Evt
    {

        class EVENT_EXPORT EventManager: public Evt::EventQueue, public Evt::Dispatcher
        {
            public:
                /**************************************************************************
                *	@brief	Constructor
                **************************************************************************/
                EventManager();


                /**************************************************************************
                *	@brief  This method returns a static instance of the EventManager class.	
                **************************************************************************/
                static EventManager& inst();
                

                /**************************************************************************
                *	@brief	Destructor
                **************************************************************************/
                virtual ~EventManager();

            private:
                /**************************************************************************
                *	@brief  deleted assignment operator.
                *   @param  An instance of the EventManger class to be copied.
                **************************************************************************/
                EventManager operator = (const EventManager eventManager) = delete;
                

                /**************************************************************************
                *	@brief  deleted copy constructor.
                *   @param  An instance of the EventManger class to be copied.
                **************************************************************************/
                EventManager(const EventManager &EventManager) = delete;
        };

    }
}
#endif // Event_MANAGER_H
