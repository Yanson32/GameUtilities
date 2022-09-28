#ifndef GAMEUTILITIES_PLAYMUSIC_H
#define GAMEUTILITIES_PLAYMUSIC_H
/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       5/11/22
*   Purpose:    This class is a subclass of the event class. This event
*               is generated to indicate that the music should start playing. 
**************************************************************************/
#include "event_export.h"
#include "GameUtilities/Event/Event.h"

namespace GU
{
    namespace Evt
    {

		class EVENT_EXPORT PlayMusic: public Event
		{
			public:
                /**************************************************************************
                *   @brief  Constructor.
                *   @param  musicFile is the music to be played.   
                *   @param  line is the line in code where the event was generated.
                *   @param  file is the file were the event was generated.
                **************************************************************************/
				PlayMusic(const char* musicFile, const int line = 0, const char* f1ile = "");
                

                /**************************************************************************
                *   @brief  Destructor.
                **************************************************************************/
				virtual ~PlayMusic();
            public:
				const char* m_musicFile;
		};
	}
}

#endif // PLAYMUSIC_H
