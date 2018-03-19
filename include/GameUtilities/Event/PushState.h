#ifndef GAMEUTILITIES_PUSHSTATE_H
#define GAMEUTILITIES_PUSHSTATE_H
#include "gameutilities_export.h"
#include "GameUtilities/Event/Event.h"

namespace GU
{
    namespace Evt
    {
		class GAMEUTILITIES_EXPORT PushState: public Event
		{
			public:
				PushState(const int newStateId, const int newLine = 0, const char* newFile = "");
				const int id;
				virtual ~PushState();
			protected:
			private:
		};
	}
}



#endif // PUSHSTATE_H
