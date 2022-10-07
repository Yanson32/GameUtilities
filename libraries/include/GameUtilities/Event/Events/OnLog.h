#ifndef GAMEUTILITIES_EVENT_ONLOG_H
#define GAMEUTILITIES_EVENT_ONLOG_H
/********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   5/20/22
*   @description    This event is generated when a log event is created 
************************************************************************/

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
#include <memory>
#include "GameUtilities/Event/Event.h"
#include "GameUtilities/Log/LogType.h"
#include "GameUtilities/Core/String.h"

namespace GU
{

    namespace Evt
    {
        /**************************************************************************
        *   Author:     Wayne J Larson Jr.
        *   Date:       11/14/20
        *   Purpose:    This is an abstract base class used to define a listener
        *               object. Which can then be registered to receive events.
        **************************************************************************/

        class EVENT_EXPORT OnLog : public Event
        {
            public:
                /**************************************************************************
                *   Constructor
                **************************************************************************/
                OnLog(const GU::Core::String &msg, const int  &severity, const int &line, const char* file = "");

                GU::Core::String getMessage() const;
                int getSeverity() const;

                /**************************************************************************
                *   Destructor
                **************************************************************************/
                virtual ~OnLog();

            private:
                const int m_severity = -1;
                GU::Core::String m_msg;
        };

    }

}
#endif // LISTENER_H
