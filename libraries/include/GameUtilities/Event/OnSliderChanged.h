#ifndef GAMEUTILITIES_SLIDER_CHANGED_H
#define GAMEUTILITIES_SLIDER_CHANGED_H
#include "event_export.h"
#include "GameUtilities/Event/Event.h"

namespace GU
{
    namespace Evt
    {

		class EVENT_EXPORT OnSliderChanged: public Event
		{
			public:
				OnSliderChanged(const int &newId, const int &newValue, const int newLine = 0, const char* newFile = "");
			    const int sliderId = -1;
                int value = 0;
				
                virtual ~OnSliderChanged();
			protected:
			private:
		};
	}
}

#endif // MUSICVOLUMECHANGED_H
