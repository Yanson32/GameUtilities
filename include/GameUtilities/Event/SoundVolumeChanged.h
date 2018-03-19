#ifndef GAMEUTILITIES_SOUNDVOLUMECHANGED_H
#define GAMEUTILITIES_SOUNDVOLUMECHANGED_H
#include "gameutilities_export.h"
#include "GameUtilities/Event/Event.h"

namespace GU
{
    namespace Evt
    {

		class GAMEUTILITIES_EXPORT SoundVolumeChanged: public Event
		{
			public:
				SoundVolumeChanged(const int newLine = 0, const std::string newFile = "");
				virtual ~SoundVolumeChanged();
			protected:
			private:
		};
	}
}

#endif // SOUNDVOLUMECHANGED_H
