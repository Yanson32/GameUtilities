#ifndef MUSICVOLUMECHANGED_H
#define MUSICVOLUMECHANGED_H
#include "gameutilities_export.h"
#include "GameUtilities/Event/Event.h"

namespace GU
{
    namespace Evt
    {

		class GAMEUTILITIES_EXPORT MusicVolumeChanged: public Event
		{
			public:
				MusicVolumeChanged(const int newLine, const std::string newFile);
				int volume = 255;
				virtual ~MusicVolumeChanged();
			protected:
			private:
		};
	}
}

#endif // MUSICVOLUMECHANGED_H
