#ifndef GAMEUTILITIES_EVNT_MOUSE_ON_CONTEXTMENU_H
#define GAMEUTILITIES_EVNT_MOUSE_ON_CONTEXTMENU_H
/**********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   09/30/22
*   @file   OnContextMenu.h
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
#include "GameUtilities/Event/Events/Event.h"
namespace GU
{
    namespace Evt
    {
        /**********************************************************************//**
        *   @class  OnContextMenu
        *   @brief  This event should be generated when the user clicks the
        *           right mouse button. 
        **************************************************************************/
        class EVENT_EXPORT OnContextMenu: public GU::Evt::Event
        {
            public:
                /******************************************************************//**
                *   @brief  Constructor
                *   @param  menuId is a unique identifier for the menu to be created. 
                *   @param  line the line where the event originates from
                *   @param  file the file where the event originates from
                **********************************************************************/
                OnContextMenu(const int &menuId, const int &line, const char* file = "");
                

                /******************************************************************//**
                *   @brief  Destructor 
                **********************************************************************/
                virtual ~OnContextMenu();
            public:
                const int m_menuId = -1;        /**< Unique identifier for the menu to be created. */
        };
    }
}
#endif
