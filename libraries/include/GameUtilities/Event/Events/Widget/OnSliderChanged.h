#ifndef GAMEUTILITIES_ON_SLIDER_CHANGED_H
#define GAMEUTILITIES_ON_SLIDER_CHANGED_H
/**************************************************************************
*   @Author:     Wayne J Larson Jr.
*   @Date:       05/10/22
*   @Purpose:    This event is created when a slider changes it's value. 
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

		class EVENT_EXPORT OnSliderChanged: public WidgetEvent
		{
			public:
                /**************************************************************************
                *   @breif  Constructor
                *   @param  id of the slider.
                *   @param  value is the current value of the slider
                *   @param  line is where the event was generated in code.
                *   @param  file is the file where the event was generated.
                **************************************************************************/
				OnSliderChanged(std::shared_ptr<void> parent, const int &widgetId, const int &sliderPos, const int &line = 0, const char* file = "");
				
                /**************************************************************************
                *   @breif  Deconstructor 
                **************************************************************************/
                virtual ~OnSliderChanged();
			public:
                int m_sliderPos = 0;
		};
	}
}

#endif 
