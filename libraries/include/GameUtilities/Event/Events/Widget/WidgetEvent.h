#ifndef GAMEUTILITIES_EVENT_WIDGET_H
#define GAMEUTILITIES_EVENT_WIDGET_H
/**************************************************************************
*   @Author:     Wayne J Larson Jr.
*   @Date:       10/01/22
*   @Purpose:    This event is created when text changes. 
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
        class EVENT_EXPORT WidgetEvent: public GU::Evt::Event
        {
            public:
                WidgetEvent(std::shared_ptr<void> parent, const int &widgetId, const int &eventId, const int &line = 0, const char* file = nullptr);
                virtual ~WidgetEvent();
            public:
                std::shared_ptr<void> m_parent = nullptr;
                const int m_widgetId = -1;
        };
    }

}
#endif

