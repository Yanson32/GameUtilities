/******************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   5/20/19
*   @file   OnChangeState.cpp
**********************************************************************/

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
#include "GameUtilities/Event/Events/OnChangeState.h"
#include "GameUtilities/Event/EventId.h"
namespace GU
{
    namespace Evt
    {

        /*******************************************************//**
        *   @brief  Constructor
        *   @param  stateId a unique identifier of the new state
        *   @param  line the line where the event originates from
        *   @param  file the file where the event originates from
        ***********************************************************/
		OnChangeState::OnChangeState(const int &stateId, const int &line, const char* file):
		Event(static_cast<int>(GU::Evt::EventId::CHANGE_STATE), line, file),
		m_stateId(stateId)
		{
			//ctor
		}


        /*******************************************************//**
        *   @brief  Destructor
        ***********************************************************/
		OnChangeState::~OnChangeState()
		{
			//dtor
		}
	}
}
