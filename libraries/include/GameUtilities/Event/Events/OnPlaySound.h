#ifndef GAMEUTILITIES_ONPLAYSOUND_H
#define GAMEUTILITIES_ONPLAYSOUND_H
/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       05/08/22
*   Purpose:    This event is to indicate when a combo box has changed 
**************************************************************************/
#include "event_export.h"
#include "GameUtilities/Event/Event.h"

namespace GU
{
    namespace Evt
    {

		class EVENT_EXPORT OnPlaySound: public Event
		{
			public:
                /**************************************************************************
                *   @brief  Constructor
                *   @param  id is the unique identifier for the sound.
                *   @param  line is the line number where the event originated from
                *   @param  file is the file where the event originated from
                **************************************************************************/
				OnPlaySound(const int &id, const int line = 0, const char* file= "");
                
                
                /**************************************************************************
                *   @brief  Destructor 
                **************************************************************************/
				virtual ~OnPlaySound();
            public:
				int m_soundId;
		};
	}
}

#endif // PLAYSOUND_H
