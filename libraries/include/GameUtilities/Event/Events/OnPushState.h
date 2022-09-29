#ifndef GAMEUTILITIES_EVENT_ONPUSHSTATE_H
#define GAMEUTILITIES_EVENT_ONPUSHSTATE_H
/*******************************************************//**
*   @author Wayne J Larson Jr.
*   @date   5/17/22
*   @brief  The PushState event will be generated when a new
*           state should be added to the stack. 
***********************************************************/
#include "event_export.h"
#include "GameUtilities/Event/Event.h"

namespace GU
{
    namespace Evt
    {
		class EVENT_EXPORT OnPushState: public Event
		{
			public:
                /*******************************************************//**
                *   @brief  Constructor
                *   @param  stateId is the unique identifier for the state.
                *   @param  line is the line in source code where the 
                *           event was generated.
                *   @param  file is the source file where the event was
                *           generated.
                ***********************************************************/
				OnPushState(const int stateId, const int line = 0, const char* file = "");
                

                /*******************************************************//**
                *   @brief  Destructor 
                ***********************************************************/
				virtual ~OnPushState();
			public:	
                const int m_id;
		};
	}
}



#endif // PUSHSTATE_H
