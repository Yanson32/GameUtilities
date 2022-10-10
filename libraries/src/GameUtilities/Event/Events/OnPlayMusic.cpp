#include "GameUtilities/Event/Events/OnPlayMusic.h"
#include "GameUtilities/Event/EventId.h"

namespace GU
{
    namespace Evt
    {
        /**************************************************************************
        *   @brief  Constructor.
        *   @param  musicFile is the music to be played.   
        *   @param  line is the line in code where the event was generated.
        *   @param  file is the file were the event was generated.
        **************************************************************************/
		OnPlayMusic::OnPlayMusic(const char* musicFile, const int &line, const char* file):
		Event(static_cast<int>(GU::Evt::EventId::PLAY_MUSIC), line, file),
		m_musicFile(musicFile)
		{
			//ctor
		}

        

        /**************************************************************************
        *   @brief  Destructor.
        **************************************************************************/
		OnPlayMusic::~OnPlayMusic()
		{
			//dtor
		}
	}
}
