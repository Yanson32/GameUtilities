#ifndef GAMEUTILITIES_EVENTHANDLER_FRAME_H
#define GAMEUTILITIES_EVENTHANDLER_FRAME_H

#include "GameUtilities/Event/Event.h"
#include "GameUtilities/Engin/Frame/EnginFrame.h"
#include "GameUtilities/Engin/Frame/Frame.h"

#include "event_export.h"
#include <memory>

namespace GU
{

    namespace Evt
    {

        class EVENT_EXPORT EventHandlerFrame
        {
            public:
                virtual void handleGUEvent(GU::Engin::EnginFrame& engin, GU::Evt::EventPtr event, std::shared_ptr<GU::Engin::Frame> frame) = 0;
        };
    }
}

#endif // GU_EVENTHANDLER_H
