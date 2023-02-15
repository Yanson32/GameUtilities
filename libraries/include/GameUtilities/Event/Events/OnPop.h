#ifndef GAMEUTILITIES_ONPOP_H
#define GAMEUTILITIES_ONPOP_H
/**********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   05/12/22
*   @file   OnPop.h
**************************************************************************/

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
#include "GameUtilities/Event/Events/Event.h"

namespace GU
{
    namespace Evt
    {

        /**********************************************************************//**
        *   @class  OnPop
        *   @brief  This class is a subclass of the Event class. This event
        *           is generated when something should be poped of a stack.  
        **************************************************************************/
		class EVENT_EXPORT OnPop: public Event
		{
			public:
                /**********************************************************************//**
                *   @brief  Constructor
                *   @param  popId is the unique identifier for the pop event.
                *   @param  line is the line number where the event originated from
                *   @param  file is the file where the event originated from
                **************************************************************************/
				OnPop(const int &popId = -1, const int &line = 0, const char* file = "");
                

                /**********************************************************************//**
                *   @brief  Deconstructor 
                **************************************************************************/
				virtual ~OnPop();
	        public:
                const int m_popId;      /**< A unique identifier for the entity to be poped. */

        };
	}
}

#endif // POP_H
