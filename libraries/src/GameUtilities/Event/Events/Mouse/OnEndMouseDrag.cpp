/**********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   09/30/22
*   @file   OnEndMouseDrag.cpp
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
#include "GameUtilities/Event/Events/Mouse/OnEndMouseDrag.h"
#include "GameUtilities/Event/EventId.h"

namespace GU
{
    namespace Evt
    {  
        
        /******************************************************************//**
        *   @brief Constructor
        *   @param position is the location of the mouse when the mouse drag 
        *          endid.
        *   @param line the line where the event originates from
        *   @param file the file where the event originates from
        **********************************************************************/
        OnEndMouseDrag::OnEndMouseDrag(Math::Vector2<float> &position, const int &line, const char* file):
        Event(static_cast<int>(GU::Evt::EventId::ON_END_DRAG), line, file),
        m_position(position) 
        {

        }
        

        /******************************************************************//**
        *   @brief  Destructor.
        **********************************************************************/
        OnEndMouseDrag::~OnEndMouseDrag()
        {

        } 
    }
}

