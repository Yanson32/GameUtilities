#ifndef GAMEUTILITIES_CHANGESTATE_H
#define GAMEUTILITIES_CHANGESTATE_H
#include "gameutilities_export.h"
#include "GameUtilities/Event/Event.h"

namespace GU
{
    namespace Evt
    {

		class GAMEUTILITIES_EXPORT ChangeState: public Event
		{
			public:
				ChangeState(const int newStateId, const int newLine = 0, const std::string newFile = "");
				const int stateId;
				virtual ~ChangeState();
		};
	}
}
#endif // CHANGESTATE_H
