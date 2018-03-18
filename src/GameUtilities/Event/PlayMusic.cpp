#include "GameUtilities/Event/PlayMusic.h"

namespace GU
{
    namespace Evt
    {
		PlayMusic::PlayMusic(const std::string &musicFile, const int newLine, const std::string newFile):
		Event(6, newLine, newFile),
		file(musicFile)
		{
			//ctor
		}

		PlayMusic::~PlayMusic()
		{
			//dtor
		}
	}
}
