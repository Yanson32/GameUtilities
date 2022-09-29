#ifndef GAMEUTILITIES_EVENT_ONLOG_H
#define GAMEUTILITIES_EVENT_ONLOG_H
#include "event_export.h"
#include <memory>
#include "GameUtilities/Event/Event.h"
#include "GameUtilities/Log/LogType.h"
#include "GameUtilities/Core/String.h"

namespace GU
{

    namespace Evt
    {
        /**************************************************************************
        *   Author:     Wayne J Larson Jr.
        *   Date:       11/14/20
        *   Purpose:    This is an abstract base class used to define a listener
        *               object. Which can then be registered to receive events.
        **************************************************************************/

        class EVENT_EXPORT OnLog : public Event
        {
            public:
                /**************************************************************************
                *   Constructor
                **************************************************************************/
                OnLog(const GU::Core::String &msg, const int  &severity, const int &line, const char* file = "");

                GU::Core::String getMessage() const;
                int getSeverity() const;

                /**************************************************************************
                *   Destructor
                **************************************************************************/
                virtual ~OnLog();

            private:
                const int m_severity = -1;
                GU::Core::String m_msg;
        };

    }

}
#endif // LISTENER_H
