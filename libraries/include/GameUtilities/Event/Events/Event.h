#ifndef GAMEUTILITIES_EVENT_EVENT_H
#define GAMEUTILITIES_EVENT_EVENT_H
/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
*	@date 	12/10/17
*   @file   Event.h
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
#include <memory>
#include "GameUtilities/Core/String.h"

namespace GU
{
    namespace Evt
    {
        const int ALL = -1;
        /*********************************************************************************//**
        *	@class  Event 
        *	@brief  This class is the base class for all events and should not be instantiated.
        *************************************************************************************/
        class EVENT_EXPORT Event
        {
            public:
                /**********************************************************************//**
                *   @brief	This method returns the id of the event.
                *   @return A unique identifier for the event.  
                **************************************************************************/
                int getId() const;
                

                /**********************************************************************//**
                *   @brief  This method returns the line in source code where the event
                *           originated from.	
                *   @return The line where the event originated from 
                **************************************************************************/
                int getLine() const;
                

                /**********************************************************************//**
                *   @brief  This method returns the source file where the event originated from.
                *   @return The source file where the event originated from.
                **************************************************************************/
                GU::Core::String getFile() const;
                

                /**********************************************************************//**
                *   @brief	Destructor
                **************************************************************************/
                virtual ~Event();
            protected:
                /**********************************************************************//**
                *	@brief	Event class constructor is not public to prevent it from
                *         	being instantiated accidentally.
                *   @param 	id the id of the event.
                *   @param  line is the line in source code where the event originated from.
                *   @param  file is the source file where the event originated from
                **************************************************************************/
                Event(const int eventId = ALL, const int line = 0, const GU::Core::String &file = "");
                

                /**********************************************************************//**
                *	@brief  The copy constructor is deleted.	
                *   @param  An object of the Event class to be copied. 
                **************************************************************************/
                Event(const Event&) = delete;
                

                /**********************************************************************//**
                *	@brief  The assignment operator which has been deleted.
                *   @brief  An object of the Event class to be copied. 
                **************************************************************************/
                Event& operator = (const Event& ) = delete;
            protected:
                const int m_eventId = 0;        /*!< A unique identifier for the event type */
                int m_line = 0;                 /*!< The line in the source code where the event originated */
                const GU::Core::String m_file;  /*!< The file where the event originated */

        };

        typedef std::shared_ptr<Event> EventPtr;
    }
}
#endif // EVENT_H
