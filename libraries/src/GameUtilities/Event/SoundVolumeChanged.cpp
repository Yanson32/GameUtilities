#include "GameUtilities/Event/SoundVolumeChanged.h"
#include "GameUtilities/Event/EventId.h"

namespace GU
{
    namespace Evt
    {
		SoundVolumeChanged::SoundVolumeChanged(const int newLine, const char* newFile):
		Event(static_cast<int>(GU::Evt::EventId::SOUND_EFFECTS_VOLUME_CHANGED), newLine, newFile)
		{
			//ctor
		}

		SoundVolumeChanged::~SoundVolumeChanged()
		{
			//dtor
		}
	}
}
