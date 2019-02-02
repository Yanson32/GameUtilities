#include "GameUtilities/Event/SoundVolumeChanged.h"
#include "GameUtilities/Event/Id.h"

namespace GU
{
    namespace Evt
    {
		SoundVolumeChanged::SoundVolumeChanged(const int newLine, const char* newFile):
		Event(GU::Evt::Id::SOUND_EFFECTS_VOLUME_CHANGED, newLine, newFile)
		{
			//ctor
		}

		SoundVolumeChanged::~SoundVolumeChanged()
		{
			//dtor
		}
	}
}
