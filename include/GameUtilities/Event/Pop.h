#ifndef POP_H
#define POP_H
#include "gameutilities_export.h"
#include "GameUtilities/Event/Event.h"

namespace GU
{
    namespace Evt
    {

		class GAMEUTILITIES_EXPORT Pop: public Event
		{
			public:
				Pop(const int newLine = 0, const std::string newFile = "");
				virtual ~Pop();
			protected:
			private:
		};
	}
}

#endif // POP_H
