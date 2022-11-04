#ifndef GAMEUTILITIES_ON_CHECK_H 
#define GAMEUTILITIES_ON_CHECK_H 
/**************************************************************************
*   @Author:     Wayne J Larson Jr.
*   @Date:       5/16/22
*   @Purpose:    This event is generated when the user clicks on something. 
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
#include "GameUtilities/Event/Events/Widget/WidgetEvent.h"
#include <memory>

namespace GU
{
    namespace Evt
    {
        class EVENT_EXPORT OnCheck: public WidgetEvent
        {
            public:
                /**************************************************************************
                *   @breif  Constructor
                *   @param  checkBoxId is a unique identifier for the checkbox.
                *   @param  checked is true if the checkbox was checked and false otherwise.
                **************************************************************************/
                OnCheck(std::shared_ptr<void> parent, const int &widgetId, const bool &checked, const int &line = -1, const char* file = "");
                

                /**************************************************************************
                *   @breif  Destructor 
                **************************************************************************/
                virtual ~OnCheck();
            public: 
                const bool m_checked;

        };
    }
}
#endif 