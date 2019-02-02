#include "GameUtilities/Event/MusicVolumeChanged.h"
#include "GameUtilities/Event/Id.h"

namespace GU
{
    namespace Evt
    {
		MusicVolumeChanged::MusicVolumeChanged(const int newLine, const char* newFile):
		Event(GU::Evt::Id::MUSIC_VOLUME_CHANGED, newLine, newFile)
		{
			//ctor
		}

		MusicVolumeChanged::~MusicVolumeChanged()
		{
			//dtor
		}
	}
}
