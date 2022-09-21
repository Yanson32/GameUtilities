#ifndef GAMEUTILITIES_EVENTHANDLER_H
#define GAMEUTILITIES_EVENTHANDLER_H

#include "GameUtilities/Event/Event.h"
#include "GameUtilities/Engin/Engin.h"
#include "event_export.h"
#include <memory>

namespace GU
{

    namespace Evt
    {

        class EVENT_EXPORT EventHandler
        {
            public:
                typedef GU::Engin::Engin const * EnginPtr;
                EventHandler();
                virtual void handleGUEvent(EnginPtr engin, GU::Evt::EventPtr event) = 0;
                virtual ~EventHandler();
            protected:
            private:
        };
    }
}

#endif // GU_EVENTHANDLER_H
