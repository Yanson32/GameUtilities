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
#include "GameUtilities/Event/Events/Widget/OnCheck.h"
#include "GameUtilities/Event/EventId.h"
namespace GU
{
    namespace Evt
    {
        /**********************************************************************//**
        *   @brief  Constructor
        *   @param  parent is the widget where the event originated from.
        *   @param  widgetId is the id of the widget that generated the event.
        *   @param  checked is true if the checkbox is checked and false otherwise
        *   @param  line is the line of source code that generated the event.
        *   @param  file is the source code file that generated the event.
        **************************************************************************/
        OnCheck::OnCheck(std::shared_ptr<void> parent, const int &widgetId, const bool &checked, const int &line, const char* file):
        WidgetEvent(parent, widgetId, static_cast<int>(GU::Evt::EventId::ON_CHECK), line, file),
        m_checked(checked)
        {
            //ctor
        }

        
        /**********************************************************************//**
        *   @brief  Destructor 
        **************************************************************************/
        OnCheck::~OnCheck()
        {
            //dtor
        }
    }
}
