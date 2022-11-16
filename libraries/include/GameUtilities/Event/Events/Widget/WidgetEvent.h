#ifndef GAMEUTILITIES_EVENT_WIDGET_H
#define GAMEUTILITIES_EVENT_WIDGET_H
/**************************************************************************
*   @Author Wayne J Larson Jr.
*   @Date   10/01/22
*   @file   WidgetEvent.h
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
#include <memory>

namespace GU
{
    namespace Evt
    {
        
        /******************************************************************//**
        *   @class  WidgetEvent
        *   @brief  This class is the base class for all widget events.
        **********************************************************************/
        class EVENT_EXPORT WidgetEvent: public GU::Evt::Event
        {
            public:
                /******************************************************************//**
                *   @brief Constructor
                *   @param parent is the widget where the event originated.
                *   @param widgetId Is a unique identifier for the widget that created the event.
                *   @param eventId  Is a unique identifier for the event. 
                *   @param line is the line in source code where the event originated.
                *   @param file is the source code file where the event originated.
                **********************************************************************/
                WidgetEvent(std::shared_ptr<void> parent, 
                const int &widgetId, 
                const int &eventId, 
                const int &line = 0, 
                const char* file = nullptr);
                
                
                /******************************************************************//**
                *   @brief  Destructor. 
                **********************************************************************/
                virtual ~WidgetEvent();
            public:
                std::shared_ptr<void> m_parent = nullptr; /**< Pointer to the widget where the event originated*/
                const int m_widgetId = -1;                /**< Unique identifier for the widgit that generated the event */
        };
    }

}
#endif

