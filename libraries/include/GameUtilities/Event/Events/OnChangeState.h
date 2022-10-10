/*******************************************************//**
*   @author Wayne J Larson Jr.
*   @date   5/20/19
*   @brief  The changestate class is a subclass of the
*           Event class and is used to signal a change
*           in the games state.
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
#ifndef GAMEUTILITIES_ONCHANGESTATE_H
#define GAMEUTILITIES_ONCHANGESTATE_H
#include "event_export.h"
#include "GameUtilities/Event/Event.h"

namespace GU
{
    namespace Evt
    {
		class EVENT_EXPORT OnChangeState: public Event
		{
			public:
                /*******************************************************//**
                *   @brief  Constructor
                *   @param  newStateId a unique identifier of the new state
                *   @param  newLine the line where the event originates from
                *   @param  newFile the file where the event originates from
                ***********************************************************/
				OnChangeState(const int &stateId, const int &line = 0, const char* file = "");


                /*******************************************************//**
                *   @brief  Destructor
                ***********************************************************/
				virtual ~OnChangeState();
            public:
                const int m_stateId;
		};
	}
}
#endif // CHANGESTATE_H
