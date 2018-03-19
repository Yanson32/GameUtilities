#ifndef GAMEUTILITIES_EVENTHANDLER_H
#define GAMEUTILITIES_EVENTHANDLER_H

#include "GameUtilities/Event/Event.h"
#include "gameutilities_export.h"
#include <memory>

namespace GU
{

    namespace Evt
    {

        class GAMEUTILITIES_EXPORT EventHandler
        {
            public:
                EventHandler();
                virtual void handleGUEvent(std::unique_ptr<Event> event) = 0;
                virtual ~EventHandler();
            protected:
            private:
        };
    }
}

#endif // GU_EVENTHANDLER_H
