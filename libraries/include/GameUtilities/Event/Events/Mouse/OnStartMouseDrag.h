#ifndef GAMEUTILITIES_START_MOUSE_DRAG_H
#define GAMEUTILITIES_START_MOUSE_DRAG_H
/**********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   09/30/22
*   @file   OnStartMouseDrag.h
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
#include <Math/Vector2.h>

namespace GU
{
    namespace Evt
    {
        /**********************************************************************//**
        *   @class  OnStartMouseDrag
        *   @brief  This event is generated when the user initiates a drag 
        *           operation with the mouse 
        **************************************************************************/
        class EVENT_EXPORT OnStartMouseDrag: public Event
        {
            public: 
                /******************************************************************//**
                *   @brief  Constructor
                *   @param  position is the location of the mouse when the drag event 
                *           started. 
                *   @param  line the line where the event originates from
                *   @param  file the file where the event originates from
                **********************************************************************/
                OnStartMouseDrag(Math::Vector2<float> &position, const int &line, const char* file = "");
                

                /******************************************************************//**
                *   @brief  Destructor 
                **********************************************************************/
                virtual ~OnStartMouseDrag(); 
            public:
                Math::Vector2<float> m_pos;     /**< The position of the mouse when the drage event started. */
        };
    }
}
#endif
