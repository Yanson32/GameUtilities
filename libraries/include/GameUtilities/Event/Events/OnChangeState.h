/*******************************************************//**
*   @author Wayne J Larson Jr.
*   @date   5/20/19
*   @brief  The changestate class is a subclass of the
*           Event class and is used to signal a change
*           in the games state.
***********************************************************/
#ifndef GAMEUTILITIES_ONCHANGESTATE_H
#define GAMEUTILITIES_ONCHANGESTATE_H
#include "event_export.h"
#include "GameUtilities/Event/Event.h"

namespace GU
{
    namespace Evt
    {
		class EVENT_EXPORT OnChangeState: public Event
		{
			public:
                /*******************************************************//**
                *   @brief  Constructor
                *   @param  newStateId a unique identifier of the new state
                *   @param  newLine the line where the event originates from
                *   @param  newFile the file where the event originates from
                ***********************************************************/
				OnChangeState(const int &stateId, const int &line = 0, const char* file = "");


                /*******************************************************//**
                *   @brief  Destructor
                ***********************************************************/
				virtual ~OnChangeState();
            public:
                const int m_stateId;
		};
	}
}
#endif // CHANGESTATE_H
