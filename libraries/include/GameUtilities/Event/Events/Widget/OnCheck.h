#ifndef GAMEUTILITIES_ON_CHECK_H 
#define GAMEUTILITIES_ON_CHECK_H 
/**************************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   5/16/22
*   @file   OnCheck.h
******************************************************************************/

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
#include "GameUtilities/Event/Events/Widget/WidgetEvent.h"
#include <memory>

namespace GU
{
    namespace Evt
    {
        /**************************************************************************//**
        *   @class OnCheck 
        *   @brief This event is generated when a checkbox is checked or unchecked
        ******************************************************************************/
        class EVENT_EXPORT OnCheck: public WidgetEvent
        {
            public:
                /**********************************************************************//**
                *   @brief  Constructor
                *   @param  parent is the widget where the event originated from.
                *   @param  widgetId is the id of the widget that generated the event.
                *   @param  checked is true if the checkbox is checked and false otherwise
                *   @param  line is the line of source code that generated the event.
                *   @param  file is the source code file that generated the event.
                **************************************************************************/
                OnCheck(std::shared_ptr<void> parent, const int &widgetId, const bool &checked, const int &line = -1, const char* file = "");
                

                /**********************************************************************//**
                *   @brief  Destructor 
                **************************************************************************/
                virtual ~OnCheck();
            public: 
                ///This varialbe is true when the checkbox is checked and false otherwise
                const bool m_checked;

        };
    }
}
#endif 
