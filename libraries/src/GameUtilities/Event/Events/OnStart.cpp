/**********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   10/01/22
*   @file   OnStart.h
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
#include "GameUtilities/Event/Events/OnStart.h"
#include "event_export.h"
#include "GameUtilities/Event/EventId.h"

namespace GU
{

    namespace Evt
    {

        /**********************************************************************//**
        *   @brief  Constructor.
        *   @param  startId is a unique id for the entity to be started. 
        *   @param  line is the source code line number that generated the event.
        *   @param  file is the source code file that generated the event
        **************************************************************************/
        OnStart::OnStart(const int &startId, const int &line, const char* file):
        Event(static_cast<int>(GU::Evt::EventId::ON_START), line, file),
        m_startId(startId)
        {

        }

        
        /**********************************************************************//**
        *   @brief  Destructor
        **************************************************************************/
        OnStart::~OnStart()
        {

        }

    }

}


