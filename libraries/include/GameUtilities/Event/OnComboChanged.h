#ifndef GAMEUTILITIES_ON_COMBO_CHANGED_H 
#define GAMEUTILITIES_ON_COMBO_CHANGED_H 
#include "GameUtilities/Event/Event.h"
#include "event_export.h"

namespace GU
{
    namespace Evt
    {

        class EVENT_EXPORT OnComboChanged: public Event
        {
            public:
                OnComboChanged(const int newComboId, const int newIndex);
                const int comboId = -1;
                const int index;
                virtual ~OnComboChanged();
            protected:
            private:

        };
    }
}
#endif 
