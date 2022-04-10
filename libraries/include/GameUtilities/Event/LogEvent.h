#ifndef GAMEUTILITIES_EVENT_LOG_H
#define GAMEUTILITIES_EVENT_LOG_H
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

        class EVENT_EXPORT LogEvent : public Event
        {
            public:
                /**************************************************************************
                *   Constructor
                **************************************************************************/
                LogEvent(const GU::Core::String &msg, const int  &newSeverity, const int newLine, const GU::Core::String &newFile);


                int getSeverity() const;

                /**************************************************************************
                *   Destructor
                **************************************************************************/
                virtual ~LogEvent();
		GU::Core::String m_msg;
            private:
                const int m_severity;
        };

    }

}
#endif // LISTENER_H
