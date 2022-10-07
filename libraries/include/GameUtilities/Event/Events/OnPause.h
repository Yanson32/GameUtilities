#ifndef GAMEUTILITIES_EVENT_ONPAUSE_H
#define GAMEUTILITIES_EVENT_ONPAUSE_H
/**************************************************************************
*   @Author:        Wayne J Larson Jr.
*   @Date:          10/01/22
*   @description:   This event is generates when something is paused. 
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

        class EVENT_EXPORT OnPause : public Event
        {
            public:
                /**************************************************************************
                *   Constructor
                **************************************************************************/
                OnPause(const int &pauseId, const int &line, const char* file = "");

                
                /**************************************************************************
                *   Destructor
                **************************************************************************/
                virtual ~OnPause(); 
            private:
                const int m_pauseId = -1;
        };

    }

}
#endif



