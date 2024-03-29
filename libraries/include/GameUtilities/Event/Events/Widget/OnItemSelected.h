#ifndef GAMEUTILITIES_ON_COMBO_CHANGED_H 
#define GAMEUTILITIES_ON_COMBO_CHANGED_H 
/**********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   05/07/22
*   @file   OnItemSelected.h
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
#include "event_export.h"
#include <memory>

namespace GU
{
    namespace Evt
    {

        /**********************************************************************//**
        *   @class  OnItemSelected
        *   @brief  This event is to indicate when a combo box has changed 
        **************************************************************************/
        class EVENT_EXPORT OnItemSelected: public WidgetEvent
        {
            public:
               
                /**********************************************************************//**
                *   @brief  Constructor   
                *   @param  parent is a pointer to the widget where the event originated.
                *   @param  widgetId is the id of the combo box
                *   @param  index is the index of the currently selected element. 
                *   @param  text is the currently selected text.
                *   @param  line is the line number in source code where the event originated.
                *   @param  file is the source code file where the event originated.
                **************************************************************************/
                OnItemSelected(std::shared_ptr<void> parent, 
                const int &widgetId, 
                const int &index = -1, 
                const GU::Core::String &text = "",
                const int &line = -1, 
                const char* file = "");
                

                /**********************************************************************//**
                *   @brief  Destructor
                **************************************************************************/
                virtual ~OnItemSelected();
                
            public:
                const int m_index;                            /**< Index of the data element */
                const GU::Core::String m_text;                /**< The new text for the combo box */ 
        };
    }
}
#endif 
