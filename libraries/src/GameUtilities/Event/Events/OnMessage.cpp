/********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   5/20/22
*   @file   OnMessage.cpp
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
#include "GameUtilities/Event/Events/OnMessage.h"
#include "GameUtilities/Event/EventId.h"

namespace GU
{
    namespace Evt
    {
        
        /**********************************************************************//**
        *   @brief  Constructor.
        *   @param  messageType indicates whate the message is for or -1 of no type.
        *   @param  line is the source code line number that generated the event.
        *   @param  file is the source code file that generated the event
        **************************************************************************/
        OnMessage::OnMessage(const GU::Core::String &msg, const int &messageType, const int &line, const char* file):
        Event(static_cast<int>(GU::Evt::EventId::ON_MESSAGE), line, file),
        m_msg(msg),
        m_messageType(messageType)
        {
            //ctor
        }


        /**********************************************************************//**
        *   @brief  This method returns the type of the message.
        *   @return The message type. 
        **************************************************************************/
         int OnMessage::getMessageType() const
        {
            return m_messageType;
        }


        /**********************************************************************//**
        *   @brief  Destructor
        **************************************************************************/
        OnMessage::~OnMessage()
        {
            //dtor
        }
    }
}


