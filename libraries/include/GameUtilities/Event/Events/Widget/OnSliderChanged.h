#ifndef GAMEUTILITIES_SLIDER_CHANGED_H
#define GAMEUTILITIES_SLIDER_CHANGED_H
/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       05/10/22
*   Purpose:    This event is created when a slider changes it's value. 
**************************************************************************/
#include "event_export.h"
#include "GameUtilities/Event/Event.h"

namespace GU
{
    namespace Evt
    {

		class EVENT_EXPORT OnSliderChanged: public Event
		{
			public:
                /**************************************************************************
                *   @breif  Constructor
                *   @param  id of the slider.
                *   @param  value is the current value of the slider
                *   @param  line is where the event was generated in code.
                *   @param  file is the file where the event was generated.
                **************************************************************************/
				OnSliderChanged(const int &newId, const int &newValue, const int newLine = 0, const char* newFile = "");
				
                /**************************************************************************
                *   @breif  Deconstructor 
                **************************************************************************/
                virtual ~OnSliderChanged();
			public:
			    const int m_sliderId = -1;
                int m_value = 0;
		};
	}
}

#endif // MUSICVOLUMECHANGED_H
