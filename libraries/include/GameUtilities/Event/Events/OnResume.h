#ifndef GAMEUTILITIES_EVENT_ONRESUME_H
#define GAMEUTILITIES_EVENT_ONRESUME_H
/**********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   10/01/22
*   @file   OnResume.h
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
        *   @class  OnResume
        *   @brief  This event is generated when something resumes. 
        **************************************************************************/
        class EVENT_EXPORT OnResume : public Event
        {
            public:
                /**********************************************************************//**
                *   @brief  Constructor.
                *   @param  resumeId is a unique identifier for the entity to be resumed. 
                *   @param  line is the source code line number that generated the event.
                *   @param  file is the source code file that generated the event
                **************************************************************************/
                OnResume(const int &resumeId, const int &line, const char* file = "");

                
                /**********************************************************************//**
                *   @brief  Destructor
                **************************************************************************/
                virtual ~OnResume(); 
            private:
                const int m_resumeId = -1;      /**< A unique id for the entity to be resumed */
        };

    }

}
#endif





