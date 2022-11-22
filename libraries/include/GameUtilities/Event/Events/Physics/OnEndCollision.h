#ifndef GAMEUTILITIES_EVENT_ONENDCOLLISION_H
#define GAMEUTILITIES_EVENT_ONENDCOLLISION_H
/**********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   10/01/22
*   @file   OnEndCollision.h
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
#include "GameUtilities/Event/Event.h"

namespace GU
{

    namespace Evt
    {

        /**********************************************************************//**
        *   @class  OnEndCollision
        *   @brief  This event is generated when collision has ended.
        **************************************************************************/
        class EVENT_EXPORT OnEndCollision : public Event
        {
            public:
                /**********************************************************************//**
                *   @brief  Constructor.
                *   @param  obj1 is a pointer to a physics object involved in collision.
                *   @param  obj2 is a pointer to a physics object involved in collision.
                *   @param  line is the source code line number that generated the event.
                *   @param  file is the source code file that generated the event
                **************************************************************************/
                OnEndCollision(void *obj1, void *obj2, const int &line, const char* file = "");

                
                /**********************************************************************//**
                *   Destructor
                **************************************************************************/
                virtual ~OnEndCollision(); 
            private:
                void* m_obj1 = nullptr;     /**< A pointer to a physics object */
                void* m_obj2 = nullptr;     /**< A pointer to a physics object */
        };

    }

}
#endif





