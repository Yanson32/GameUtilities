/********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   5/20/22
*   @file   OnLog.cpp
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
#include "GameUtilities/Event/Events/OnLog.h"
#include "GameUtilities/Core/Macros.h"
#include "GameUtilities/Event/EventId.h"
namespace GU
{
    namespace Evt
    {
        
        /**********************************************************************//**
        *   @brief  Constructor.
        *   @param  msg is the string to be written to the log file.
        *   @param  severity indicated the log messages importance. 
        *   @param  line is the source code line number that generated the event.
        *   @param  file is the source code file that generated the event
        **************************************************************************/
        OnLog::OnLog(const GU::Core::String &msg, const int &severity, const int &line, const char* file):
	    Event(static_cast<int>(GU::Evt::EventId::LOG), line, file),
        m_severity(severity),
	    m_msg(msg)
        {
        
        }


        /**********************************************************************//**
        *   @brief  This method returns the message to be logged. 
        *   @return The log message 
        **************************************************************************/
        GU::Core::String OnLog::getMessage() const
        {
          return m_msg;
        }


        /**********************************************************************//**
        *   @brief  This method return the severity (importance) of the log message. 
        *   @return The log message 
        **************************************************************************/
	    int OnLog::getSeverity() const
        {
            return m_severity;
        }
        

        /**********************************************************************//**
        *   @brief  Destructor
        **************************************************************************/
        OnLog::~OnLog()
        {
            //dtor
        }
    }
}
