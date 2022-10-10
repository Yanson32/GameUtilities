#ifndef EVENT_ON_TEXT_CHANGED_H
#define EVENT_ON_TEXT_CHANGED_H
/**************************************************************************
*   @Author:     Wayne J Larson Jr.
*   @Date:       08/31/22
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
#include "GameUtilities/Event/Events/Widget/WidgetEvent.h"
#include "GameUtilities/Core/String.h"

namespace GU
{
    namespace Evt
    {

        class OnTextChanged: public GU::Evt::WidgetEvent
        {
            public:
                OnTextChanged(void *parent, const int &widgetId, const GU::Core::String &text, const int &line = -1, const char* file);
                virtual ~OnTextChanged();
                const GU::Core::String m_text = "";
        };
    }
}

#endif

