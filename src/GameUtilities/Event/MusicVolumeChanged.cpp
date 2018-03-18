#include "GameUtilities/Event/MusicVolumeChanged.h"

namespace GU
{
    namespace Evt
    {
		MusicVolumeChanged::MusicVolumeChanged(const int newLine, const std::string newFile):
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
