#ifndef GAMEUTILITIES_EVENT_ONPAUSE_H
#define GAMEUTILITIES_EVENT_ONPAUSE_H
/**********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   10/01/22
*   @file   OnPause.h
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
        *   @class  OnPause
        *   @brief  This event is generates when something is paused. 
        **************************************************************************/
        class EVENT_EXPORT OnPause : public Event
        {
            public:
                /**********************************************************************//**
                *   @brief  Constructor.
                *   @param  pauseId is a unique id for the entity to be paused. 
                *   @param  line is the line in code where the event was generated.
                *   @param  file is the file were the event was generated.
                **************************************************************************/
                OnPause(const int &pauseId, const int &line, const char* file = "");

                
                /**********************************************************************//**
                *   @brief  Destructor
                **************************************************************************/
                virtual ~OnPause(); 
            private:
                const int m_pauseId = -1;       /**< A unique identifier of the entity to be paused. */
        };

    }

}
#endif



