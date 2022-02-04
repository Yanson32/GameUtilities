#ifndef GAMEUTILITIES_EVENT_LOG_H
#define GAMEUTILITIES_EVENT_LOG_H
#include "event_export.h"
#include <memory>
#include "GameUtilities/Event/Event.h"
#include "GameUtilities/Log/LogType.h"
#include <string>

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

        class EVENT_EXPORT LogEvent : public Event
        {
            public:
                /**************************************************************************
                *   Constructor
                **************************************************************************/
                LogEvent(const std::string &msg, const LogType  newSeverity = LogType::MESSAGE);
                
                LogType getSeverity() const;

                /**************************************************************************
                *   Destructor
                **************************************************************************/
                virtual ~LogEvent();

            private:
                const LogType m_severity;
        };

    }

}
#endif // LISTENER_H

