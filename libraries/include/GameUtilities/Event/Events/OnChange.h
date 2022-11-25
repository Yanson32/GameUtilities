#ifndef GAMEUTILITIES_EVENT_ONCHANGE_H
#define GAMEUTILITIES_EVENT_ONCHANGE_H
/**************************************************************************
*   @author Wayne J Larson Jr.
*   @date   10/08/22
*   @file   OnChange.h
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

        /**************************************************************************
        *   @class  OnChange
        *   @brief  This event is generated when something is changed. 
        **************************************************************************/
        class EVENT_EXPORT OnChange: public Event
        {
            public:
                /******************************************************************//**
                *   @brief  Constructor
                *   @param  changeId a unique identifier of the entity to be changed.
                *   @param  line the line where the event originates from
                *   @param  file the file where the event originates from
                **********************************************************************/
                OnChange(const int &changeId, const int &line, const char* file = "");

                
                /**********************************************************************//**
                *   @brief  Destructor
                **************************************************************************/
                virtual ~OnChange(); 
            private:
                const int m_changeId = -1;      /**< A unique identifier for the entity to be changed.*/
        };

    }

}
#endif



