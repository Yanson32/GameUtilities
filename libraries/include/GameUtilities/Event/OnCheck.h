#ifndef GAMEUTILITIES_ON_CHECK_H 
#define GAMEUTILITIES_ON_CHECK_H 
#include "event_export.h"
#include "GameUtilities/Event/Event.h"

namespace GU
{
    namespace Evt
    {
        class EVENT_EXPORT OnCheck: public Event
        {
            public:
                OnCheck(const int newCheckBoxId, const bool newChecked);
                const int checkboxId = -1;
                const bool checked;
                virtual ~OnCheck();
            protected:
            private:

        };
    }
}
#endif 
