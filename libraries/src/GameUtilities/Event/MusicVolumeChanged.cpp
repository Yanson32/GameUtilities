#include "GameUtilities/Event/MusicVolumeChanged.h"
#include "GameUtilities/Event/EventId.h"

namespace GU
{
    namespace Evt
    {
		MusicVolumeChanged::MusicVolumeChanged(const int newLine, const char* newFile):
		Event(static_cast<int>(GU::Evt::EventId::MUSIC_VOLUME_CHANGED), newLine, newFile)
		{
			//ctor
		}

		MusicVolumeChanged::~MusicVolumeChanged()
		{
			//dtor
		}
	}
}
