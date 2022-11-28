#ifndef GAMEUTILITIES_EVENTHANDLER_H
#define GAMEUTILITIES_EVENTHANDLER_H
/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
*	@date   12/21/2019
*   @file   EventHandler.h
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

#include "GameUtilities/Event/Event.h"
#include "GameUtilities/Engin/Engin.h"
#include "event_export.h"
#include <memory>

namespace GU
{

    namespace Evt
    {

        /*********************************************************************************//**
        *   @class EventHandler
        *	@brief This class should be inherited by any class that needs to handle events.
        *************************************************************************************/
        class EVENT_EXPORT EventHandler
        {
            public:
                /// A pointer to the game engin
                typedef GU::Engin::Engin * const EnginPtr;
                
    
                /**********************************************************************//**
                *	@brief	Constructor
                **************************************************************************/
                EventHandler();
                

                /**********************************************************************//**
                *	@brief  This method will be called when and event needs to be handled.
                *   @param  engin is a pointer to the game engin.
                *   @param  event is a pointer to the event to be handled.
                **************************************************************************/
                virtual void handleGUEvent(EnginPtr engin, GU::Evt::EventPtr event) = 0;
                

                /**********************************************************************//**
                *	@brief  Destructor.
                **************************************************************************/
                virtual ~EventHandler();
        };
    }
}

#endif // GU_EVENTHANDLER_H
