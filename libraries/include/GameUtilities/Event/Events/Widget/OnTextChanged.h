#ifndef EVENT_ON_TEXT_CHANGED_H
#define EVENT_ON_TEXT_CHANGED_H
/**********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   08/31/22
*   @file   OnTextChanged.h
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
#include <memory>

namespace GU
{
    namespace Evt
    {

        /*********************************************************************//***
        *   @class  OnTextChanged
        *   @brief  This event is created when text changes. 
        **************************************************************************/
        class OnTextChanged: public GU::Evt::WidgetEvent
        {
            public:
                /**********************************************************************//**
                *   @brief Constructor. 
                *   @param parent is the widget where the event originated from.
                *   @param widgetId is the id of the widget where the event originated.
                *   @param text is the new text.
                *   @param line is the line in source code where the event originated.  
                *   @param file is the source code file where the event originated from.
                **************************************************************************/
                OnTextChanged(std::shared_ptr<void> parent, 
                const int &widgetId, 
                const GU::Core::String &text, 
                const int &line = -1, 
                const char* file = "");

                /**********************************************************************//**
                *   @brief Destructor.
                **************************************************************************/
                virtual ~OnTextChanged();
            public:
                const GU::Core::String m_text = "";     /**< The updated text */
        };
    }
}

#endif

