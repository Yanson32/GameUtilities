#ifndef GAMEUTILITIES_ON_SLIDER_CHANGED_H
#define GAMEUTILITIES_ON_SLIDER_CHANGED_H
/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       05/10/22
*   Purpose:    This event is created when a slider changes it's value. 
**************************************************************************/
#include "event_export.h"
#include "GameUtilities/Event/Events/Widget/WidgetEvent.h"

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
				OnSliderChanged(void *parent, const int &widgetId, const int &sliderPos, const int &line = 0, const char* file = "");
				
                /**************************************************************************
                *   @breif  Deconstructor 
                **************************************************************************/
                virtual ~OnSliderChanged();
			public:
                int m_sliderPos = 0;
		};
	}
}

#endif // MUSICVOLUMECHANGED_H
