#include "GameUtilities/Event/PlaySound.h"
#include "GameUtilities/Event/EventId.h"

namespace GU
{
    namespace Evt
    {
		PlaySound::PlaySound(const int &newId, const int newLine, const char* newFile):
		Event(static_cast<int>(GU::Evt::EventId::PLAY_SOUND), newLine, newFile), soundId(newId)
		{
			//ctor
		}

		PlaySound::~PlaySound()
		{
			//dtor
		}
	}
}
