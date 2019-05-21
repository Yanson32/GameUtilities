/*******************************************************//**
*   @author Wayne J Larson Jr.
*   @date   5/20/19
*   @brief  The changestate class is a subclass of the
*           Event class and is used to signal a change
*           in the games state.
***********************************************************/
#ifndef GAMEUTILITIES_CHANGESTATE_H
#define GAMEUTILITIES_CHANGESTATE_H
#include "event_export.h"
#include "GameUtilities/Event/Event.h"

namespace GU
{
    namespace Evt
    {
		class EVENT_EXPORT ChangeState: public Event
		{
			public:
                /*******************************************************//**
                *   @brief  Constructor
                *   @param  newStateId a unique identifier of the new state
                *   @param  newLine the line where the event originates from
                *   @param  newFile the file where the event originates from
                ***********************************************************/
				ChangeState(const int newStateId, const int newLine = 0, const char* newFile = "");


				const int stateId;  //The unique identifier of the state


                /*******************************************************//**
                *   @brief  Destructor
                ***********************************************************/
				virtual ~ChangeState();
		};
	}
}
#endif // CHANGESTATE_H
