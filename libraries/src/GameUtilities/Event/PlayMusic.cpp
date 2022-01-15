#include "GameUtilities/Event/PlayMusic.h"
#include "GameUtilities/Event/EventId.h"

namespace GU
{
    namespace Evt
    {
		PlayMusic::PlayMusic(const char* newMusicFile, const int newLine, const char* newFile):
		Event(static_cast<int>(GU::Evt::EventId::PLAY_MUSIC), newLine, newFile),
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
