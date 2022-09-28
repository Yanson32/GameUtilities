#ifndef GAMEUTILITIES_POP_H
#define GAMEUTILITIES_POP_H
/**************************************************************************
*   Author:     Wayne J Larson Jr.
*   Date:       05/12/22
*   Purpose:    This class is a subclass of the Event class. This event
*               is generated when something should be poped of a stack.  
**************************************************************************/
#include "event_export.h"
#include "GameUtilities/Event/Event.h"

namespace GU
{
    namespace Evt
    {

		class EVENT_EXPORT Pop: public Event
		{
			public:
                /**************************************************************************
                *   @brief  Constructor
                *   @param  id is the unique identifier for the pop event.
                *   @param  line is the line number where the event originated from
                *   @param  file is the file where the event originated from
                **************************************************************************/
				Pop(const int id = -1, const int line = 0, const char* file = "");
                

                /**************************************************************************
                *   @brief  Deconstructor 
                **************************************************************************/
				virtual ~Pop();
	        public:
                const int m_id;

        };
	}
}

#endif // POP_H
