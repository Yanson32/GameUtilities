#include "GameUtilities/Event/PlayMusic.h"

namespace GU
{
    namespace Evt
    {
		PlayMusic::PlayMusic(const char* newMusicFile, const int newLine, const char* newFile):
		Event(6, newLine, newFile),
		musicFile(newMusicFile)
		{
			//ctor
		}

		PlayMusic::~PlayMusic()
		{
			//dtor
		}
	}
}
