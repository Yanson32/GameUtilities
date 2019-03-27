#ifndef GAMEUTILITIES_PLAYMUSIC_H
#define GAMEUTILITIES_PLAYMUSIC_H
#include "event_export.h"
#include "GameUtilities/Event/Event.h"

namespace GU
{
    namespace Evt
    {

		class EVENT_EXPORT PlayMusic: public Event
		{
			public:
				PlayMusic(const char* newMusicFile, const int newLine = 0, const char* newFile = "");
				const char* musicFile;
				virtual ~PlayMusic();
		};
	}
}

#endif // PLAYMUSIC_H
