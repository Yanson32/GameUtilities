#ifndef GAMEUTILITIES_PLAYSOUND_H
#define GAMEUTILITIES_PLAYSOUND_H
#include "gameutilities_export.h"
#include "GameUtilities/Event/Event.h"

namespace GU
{
    namespace Evt
    {

		class GAMEUTILITIES_EXPORT PlaySound: public Event
		{
			public:
				PlaySound(const int &newId, const int newLine = 0, const char* newFile = "");
				int soundId;
				virtual ~PlaySound();
			protected:
			private:

		};
	}
}

#endif // PLAYSOUND_H
