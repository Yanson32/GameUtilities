#ifndef GAMEUTILITIES_EVENT_ONMESSAGE_H 
#define GAMEUTILITIES_EVENT_ONMESSAGE_H
/********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   5/20/22
*   @file   OnMessage.h
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
#include "GameUtilities/Core/String.h"

namespace GU
{

    namespace Evt
    {
        
        /********************************************************************//**
        *   @class  OnMessage 
        *   @brief  This event is generated when a message is created.
        *           A message being a string. 
        ************************************************************************/
        class EVENT_EXPORT OnMessage: public Event 
        {
            public:
                /**********************************************************************//**
                *   @brief  Constructor.
                *   @param  messageType indicates whate the message is for or -1 of no type.
                *   @param  line is the source code line number that generated the event.
                *   @param  file is the source code file that generated the event
                **************************************************************************/
                OnMessage(const GU::Core::String &msg, const int  &messageType  = -1, const int &line = -1, const char* file = "");


                /**********************************************************************//**
                *   @brief Method called when an event is sent
                *   @param event a pointer to an event this can be a nullptr.
                *          the pointer will be overwritten so the event should not
                *          still be useful
                **************************************************************************/
                virtual void OnEvent(EventPtr event) = 0;

                
                /**********************************************************************//**
                *   @brief  This method returns the type of the message.
                *   @return The message type. 
                **************************************************************************/
                int getMessageType() const;


                /**********************************************************************//**
                *   @brief  Destructor
                **************************************************************************/
                virtual ~OnMessage();

            private:
                const GU::Core::String m_msg;       /**< A string message */
                const int m_messageType = -1;       /**< The type of message */
        };

    }

}
#endif // LISTENER_H


