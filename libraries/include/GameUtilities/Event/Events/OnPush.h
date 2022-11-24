#ifndef GAMEUTILITIES_EVENT_ONPUSH_H
#define GAMEUTILITIES_EVENT_ONPUSH_H
/**********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   10/10/22
*   @file   OnPush.h
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
        *   @class  OnPush
        *   @brief  This event is generated when something is pushed. 
        **************************************************************************/
        class EVENT_EXPORT OnPush : public Event
        {
            public:
                /**********************************************************************//**
                *   @brief  Constructor.
                *   @param  pushId is a unique identifier for the entity to be pushed. 
                *   @param  line is the source code line number that generated the event.
                *   @param  file is the source code file that generated the event
                **************************************************************************/
                OnPush(const int &pushId, const int &line, const char* file = "");

                
                /*********************************************************************//***
                *   @brief  Destructor
                **************************************************************************/
                virtual ~OnPush(); 
            private:
                const int m_pushId = -1;        /**< A unique identifier for the entity to be pushed. */
        };

    }

}
#endif



