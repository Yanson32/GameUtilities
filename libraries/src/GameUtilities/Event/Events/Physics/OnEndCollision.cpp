/**********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   10/01/22
*   @file   OnEndCollision.cpp
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
#include "GameUtilities/Event/EventId.h"
#include "GameUtilities/Event/Events/Physics/OnEndCollision.h"

namespace GU
{

    namespace Evt
    {

        /**********************************************************************//**
        *   @brief  Constructor.
        *   @param  obj1 is a pointer to a physics object involved in collision.
        *   @param  obj2 is a pointer to a physics object involved in collision.
        *   @param  line is the source code line number that generated the event.
        *   @param  file is the source code file that generated the event
        **************************************************************************/
        OnEndCollision::OnEndCollision(void *obj1, void *obj2, const int &line, const char* file):
        Event(static_cast<int>(GU::Evt::EventId::ON_END_COLLISION), line, file),
        m_obj1(obj1),
        m_obj2(obj2)
        {

        }

        
        /**********************************************************************//**
        *   Destructor
        **************************************************************************/
        OnEndCollision::~OnEndCollision()
        {

        }

    }

}
