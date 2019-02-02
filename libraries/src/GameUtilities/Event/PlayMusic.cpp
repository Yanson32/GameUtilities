#include "GameUtilities/Event/PlayMusic.h"
#include "GameUtilities/Event/Id.h"

namespace GU
{
    namespace Evt
    {
		PlayMusic::PlayMusic(const char* newMusicFile, const int newLine, const char* newFile):
		Event(GU::Evt::Id::PLAY_MUSIC, newLine, newFile),
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
