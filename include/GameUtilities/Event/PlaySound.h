#ifndef GU_PLAYSOUND_H
#define GU_PLAYSOUND_H
#include <string>
#include "gameutilities_export.h"
#include "GameUtilities/Event/Event.h"

namespace GU
{
    namespace Evt
    {

		class GAMEUTILITIES_EXPORT PlaySound: public Event
		{
			public:
				PlaySound(const std::string &newId, const int newLine = 0, const std::string newFile = "");
				std::string soundId;
				virtual ~PlaySound();
			protected:
			private:

		};
	}
}

#endif // PLAYSOUND_H
