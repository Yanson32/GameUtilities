#ifndef GAMEUTILITIES_EVENT_ONSTOP_H
#define GAMEUTILITIES_EVENT_ONSTOP_H
/**********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   10/01/22
*   @file   OnStop.h
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
#include "GameUtilities/Event/Event.h"

namespace GU
{

    namespace Evt
    {

        /**********************************************************************//**
        *   @class  OnStop
        *   @brief  This event is generates when something is stopped. 
        **************************************************************************/
        class EVENT_EXPORT OnStop : public Event
        {
            public:
                /**********************************************************************//**
                *   @brief  Constructor.
                *   @param  stopId is a unique id for the entity to be stopped. 
                *   @param  line is the source code line number that generated the event.
                *   @param  file is the source code file that generated the event
                **************************************************************************/
                OnStop(const int &stopId, const int &line, const char* file = "");

                
                /**********************************************************************//**
                *   Destructor
                **************************************************************************/
                virtual ~OnStop(); 
            private:
                const int m_stopId = -1;        /**< A unique id for the entity to be stopped */
        };

    }

}
#endif


