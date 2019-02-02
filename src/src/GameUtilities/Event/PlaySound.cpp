#include "GameUtilities/Event/PlaySound.h"
#include "GameUtilities/Event/Id.h"

namespace GU
{
    namespace Evt
    {
		PlaySound::PlaySound(const int &newId, const int newLine, const char* newFile):
		Event(GU::Evt::Id::PLAY_SOUND, newLine, newFile), soundId(newId)
		{
			//ctor
		}

		PlaySound::~PlaySound()
		{
			//dtor
		}
	}
}
