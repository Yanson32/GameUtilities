#ifndef GAMEUTILITIES_PLAYMUSIC_H
#define GAMEUTILITIES_PLAYMUSIC_H
#include "gameutilities_export.h"
#include "GameUtilities/Event/Event.h"
#include <string>

namespace GU
{
    namespace Evt
    {

		class GAMEUTILITIES_EXPORT PlayMusic: public Event
		{
			public:
				PlayMusic(const std::string &musicFile, const int newLine = 0, const std::string newFile = "");
				std::string file;
				virtual ~PlayMusic();
		};
	}
}

#endif // PLAYMUSIC_H
