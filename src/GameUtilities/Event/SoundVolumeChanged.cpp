#include "GameUtilities/Event/SoundVolumeChanged.h"

namespace GU
{
    namespace Evt
    {
		SoundVolumeChanged::SoundVolumeChanged(const int newLine, const std::string newFile):
		Event(4, newLine, newFile)
		{
			//ctor
		}

		SoundVolumeChanged::~SoundVolumeChanged()
		{
			//dtor
		}
	}
}
