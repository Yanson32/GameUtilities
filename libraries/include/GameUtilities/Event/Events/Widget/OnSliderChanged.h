#ifndef GAMEUTILITIES_ON_SLIDER_CHANGED_H
#define GAMEUTILITIES_ON_SLIDER_CHANGED_H
/**********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   05/10/22
*   @file   OnSliderChanged.h
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

        /**********************************************************************//**
        *   @class OnSliderChanged
        *   @brief This event is created when a slider changes it's value. 
        **************************************************************************/
		class EVENT_EXPORT OnSliderChanged: public WidgetEvent
		{
			public:
                /**********************************************************************//**
                *   @brief  Constructor
                *   @param  widgetId of the slider.
                *   @param  parent is a pointer to the widget where the event originated.
                *   @param  value is the current value of the slider
                *   @param  line is where the event was generated in code.
                *   @param  file is the file where the event was generated.
                **************************************************************************/
				OnSliderChanged(std::shared_ptr<void> parent, const int &widgetId, const int &sliderPos, const int &line = 0, const char* file = "");
				
                /**********************************************************************//**
                *   @brief  Deconstructor 
                **************************************************************************/
                virtual ~OnSliderChanged();
			public:
                int m_sliderPos = 0;    /**< The current position of the slider */
		};
	}
}

#endif 
