#ifndef GAMEUTILITIES_EVNT_MOUSE_ON_MOUSEBUTTONWHEEL_H
#define GAMEUTILITIES_EVNT_MOUSE_ON_MOUSEBUTTONWHEEL_H
/**********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   09/30/22
*   @file   OnMouseWheel.h
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
        *   @class  OnMouseWheel
        *   @brief  This event is generated when the user moves the mouse wheel 
        **************************************************************************/
        class EVENT_EXPORT OnMouseWheel: public GU::Evt::Event
        {
            public:
                /******************************************************************//**
                *   @brief  Constructor
                *   @param  pos is the location of the mouse when the wheel event 
                *           was triggered. 
                *   @param  line the line where the event originates from
                *   @param  file the file where the event originates from
                **********************************************************************/
                OnMouseWheel(const int &pos, const int &line, const char* file = "");
                

                /******************************************************************//**
                *   @brief  Destructor 
                **********************************************************************/
                virtual ~OnMouseWheel();
            public:
                const int m_pos;        /**< The location of the mouse when the wheel event was triggered. */
        };
    }
}
#endif





