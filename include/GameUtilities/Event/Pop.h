#ifndef GAMEUTILITIES_POP_H
#define GAMEUTILITIES_POP_H
#include "gameutilities_export.h"
#include "GameUtilities/Event/Event.h"

namespace GU
{
    namespace Evt
    {

		class GAMEUTILITIES_EXPORT Pop: public Event
		{
			public:
				Pop(const int newLine = 0, const char* newFile = "");
				virtual ~Pop();
			protected:
			private:
		};
	}
}

#endif // POP_H
