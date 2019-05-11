#ifndef GAMEUTILITIES_SOUNDVOLUMECHANGED_H
#define GAMEUTILITIES_SOUNDVOLUMECHANGED_H
#include "event_export.h"
#include "GameUtilities/Event/Event.h"

namespace GU
{
    namespace Evt
    {

		class EVENT_EXPORT SoundVolumeChanged: public Event
		{
			public:
				SoundVolumeChanged(const int newLine = 0, const char* newFile = "");
				virtual ~SoundVolumeChanged();
			protected:
			private:
		};
	}
}

#endif // SOUNDVOLUMECHANGED_H
