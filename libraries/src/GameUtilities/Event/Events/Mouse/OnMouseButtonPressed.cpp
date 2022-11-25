/**********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   09/30/22
*   @file   OnMousButtonPressed.cpp
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
#include "GameUtilities/Event/EventId.h"
#include "GameUtilities/Event/Events/Mouse/OnMouseButtonPressed.h"

namespace GU
{
    namespace Evt
    {
        /******************************************************************//**
        *   @brief Constructor
        *   @param pos is the location of the mouse when the button pressed 
        *          event was triggered. 
        *   @param line the line where the event originates from
        *   @param file the file where the event originates from
        **********************************************************************/
        OnMouseButtonPressed::OnMouseButtonPressed(const Math::Vector2<float> &pos, const int &line, const char* file):
        Event(static_cast<int>(GU::Evt::EventId::ON_MOUSE_BUTTON_PRESSED), line, file),
        m_pos(pos) 
        {

        }


        /******************************************************************//**
        *   @brief  Destructor 
        **********************************************************************/
        OnMouseButtonPressed::~OnMouseButtonPressed()
        {

        }
    }
}
