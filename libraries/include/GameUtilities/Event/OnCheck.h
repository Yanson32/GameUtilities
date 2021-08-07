#ifndef GAMEUTILITIES_ON_CHECK_H 
#define GAMEUTILITIES_ON_CHECK_H 
#include "GameUtilities/Event/Event.h"

namespace GU
{
    namespace Evt
    {

        class OnCheck: public Event
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
