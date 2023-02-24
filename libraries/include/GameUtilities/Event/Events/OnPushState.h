#ifndef GAMEUTILITIES_EVENT_ONPUSHSTATE_H
#define GAMEUTILITIES_EVENT_ONPUSHSTATE_H
/*******************************************************//**
*   @author Wayne J Larson Jr.
*   @date   5/17/22
*   @file   OnPushState.h
***********************************************************/

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
        /*******************************************************//**
        *   @class  OnPushState
        *   @brief  The PushState event will be generated when a new
        *           state should be added to the stack. 
        ***********************************************************/
		class EVENT_EXPORT OnPushState: public Event
		{
			public:
                /*******************************************************//**
                *   @brief  Constructor
                *   @param  stateId is the unique identifier for the state.
                *   @param  line is the line in source code where the 
                *           event was generated.
                *   @param  file is the source file where the event was
                *           generated.
                ***********************************************************/
				OnPushState(const int &stateId, const int &line = 0, const char* file = "");
                

                /*******************************************************//**
                *   @brief  Destructor 
                ***********************************************************/
				virtual ~OnPushState();
			public:	
                const int m_stateId;        /**< A unique identifier for the state */
		};
	}
}



#endif // PUSHSTATE_H
