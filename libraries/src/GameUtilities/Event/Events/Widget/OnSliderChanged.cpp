/**************************************************************************
*   @author Wayne J Larson Jr.
*   @date   05/10/22
*   @file   OnSliderChanged.cpp
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
#include "GameUtilities/Event/Events/Widget/OnSliderChanged.h"
#include "GameUtilities/Event/EventId.h"

namespace GU
{
    namespace Evt
    {
        /**************************************************************************
        *   @breif  Constructor
        *   @param  id of the slider.
        *   @param  value is the current value of the slider
        *   @param  line is where the event was generated in code.
        *   @param  file is the file where the event was generated.
        **************************************************************************/
		OnSliderChanged::OnSliderChanged(std::shared_ptr<void> parent, const int &widgetId, const int &value, const int &line, const char* file):
		WidgetEvent(parent, widgetId, static_cast<int>(GU::Evt::EventId::SLIDER_CHANGED), line, file),
        m_sliderPos(value)

		{
			//ctor
		}

        
        /**************************************************************************
        *   @breif  Deconstructor 
        **************************************************************************/
		OnSliderChanged::~OnSliderChanged()
		{
			//dtor
		}
	}
}
