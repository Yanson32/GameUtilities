#include "GameUtilities/Event/PlaySound.h"

namespace GU
{
    namespace Evt
    {
		PlaySound::PlaySound(const int &newId, const int newLine, const char* newFile):
		Event(3, newLine, newFile), soundId(newId)
		{
			//ctor
		}

		PlaySound::~PlaySound()
		{
			//dtor
		}
	}
}
