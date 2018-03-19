#include "GameUtilities/Event/MusicVolumeChanged.h"

namespace GU
{
    namespace Evt
    {
		MusicVolumeChanged::MusicVolumeChanged(const int newLine, const char* newFile):
		Event(5, newLine, newFile)
		{
			//ctor
		}

		MusicVolumeChanged::~MusicVolumeChanged()
		{
			//dtor
		}
	}
}
