/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
*	@date 	12/10/17
*   @file   Event.cpp
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
#include "GameUtilities/Event/Events/Event.h"

namespace GU
{
    namespace Evt
    {

        /**********************************************************************//**
        *	@brief	Event class constructor is not public to prevent it from
        *         	being instantiated accidentally.
        *   @param 	id the id of the event.
        *   @param  line is the line in source code where the event originated from.
        *   @param  file is the source file where the event originated from
        **************************************************************************/
        Event::Event(const int eventId, const int line, const GU::Core::String &file):
		m_eventId(eventId),
		m_line(line),
		m_file(file)
        {

        }

        
        /**********************************************************************//**
        *   @brief	This method returns the id of the event.
        *   @return A unique identifier for the event.  
        **************************************************************************/
        int Event::getId() const
        {
          return m_eventId;
        }


        /**********************************************************************//**
        *   @brief  This method returns the line in source code where the event
        *           originated from.	
        *   @return The line where the event originated from 
        **************************************************************************/
        int Event::getLine() const
        {
          return m_line;
        }


        /**********************************************************************//**
        *   @brief  This method returns the source file where the event originated from.
        *   @return The source file where the event originated from.
        **************************************************************************/
        GU::Core::String Event::getFile() const
        {
          return m_file;
        }


        /**********************************************************************//**
        *   \brief	Destructor
        **************************************************************************/
        Event::~Event()
        {

        }
    }
}
