#include "GameUtilities/Event/PlaySound.h"
#include "GameUtilities/Event/EventId.h"

namespace GU
{
    namespace Evt
    {
        /**************************************************************************
        *   @brief  Constructor
        *   @param  id is the unique identifier for the sound.
        *   @param  line is the line number where the event originated from
        *   @param  file is the file where the event originated from
        **************************************************************************/
		PlaySound::PlaySound(const int &id, const int line, const char* file):
		Event(static_cast<int>(GU::Evt::EventId::PLAY_SOUND), line, file), m_soundId(id)
		{
			//ctor
		}

        
        /**************************************************************************
        *   @brief  Destructor 
        **************************************************************************/
		PlaySound::~PlaySound()
		{
			//dtor
		}
	}
}
