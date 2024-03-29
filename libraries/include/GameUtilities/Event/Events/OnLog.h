#ifndef GAMEUTILITIES_EVENT_ONLOG_H
#define GAMEUTILITIES_EVENT_ONLOG_H
/********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   5/20/22
*   @file   OnLog.h
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
#include "GameUtilities/Event/Events/Event.h"
#include "GameUtilities/Log/LogType.h"
#include "GameUtilities/Core/String.h"

namespace GU
{

    namespace Evt
    {

        /********************************************************************//**
        *   @class  OnLog 
        *   @brief  This event is generated when a log event is created 
        ************************************************************************/
        class EVENT_EXPORT OnLog : public Event
        {
            public:
                /**********************************************************************//**
                *   @brief  Constructor.
                *   @param  msg is the string to be written to the log file.
                *   @param  severity indicated the log messages importance. 
                *   @param  line is the source code line number that generated the event.
                *   @param  file is the source code file that generated the event
                **************************************************************************/
                OnLog(const GU::Core::String &msg, const int  &severity, const int &line, const char* file = "");

                
                /**********************************************************************//**
                *   @brief  This method returns the message to be logged. 
                *   @return The log message 
                **************************************************************************/
                GU::Core::String getMessage() const;

                
                /**********************************************************************//**
                *   @brief  This method return the severity (importance) of the log message. 
                *   @return The log message 
                **************************************************************************/
                int getSeverity() const;


                /**********************************************************************//**
                *   @brief  Destructor
                **************************************************************************/
                virtual ~OnLog();

            private:
                const int m_severity = -1;      /**< The importance of the log message */
                GU::Core::String m_msg;         /**< The message to be logged */
        };

    }

}
#endif // LISTENER_H
