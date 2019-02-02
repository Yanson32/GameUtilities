#ifndef GAMEUTILITIES_EVENTHANDLER_H
#define GAMEUTILITIES_EVENTHANDLER_H

#include "GameUtilities/Event/Event.h"
#include "GameUtilities/Engin/Engin.h"
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
                virtual void handleGUEvent(GU::Engin::Engin& engin, GU::Evt::EventPtr event) = 0;
                virtual ~EventHandler();
            protected:
            private:
        };
    }
}

#endif // GU_EVENTHANDLER_H
