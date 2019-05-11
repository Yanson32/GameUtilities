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
				ChangeState(const int newStateId, const int newLine = 0, const char* newFile = "");
				const int stateId;
				virtual ~ChangeState();
		};
	}
}
#endif // CHANGESTATE_H
