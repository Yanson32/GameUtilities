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

            private:
<<<<<<< HEAD
                const int m_severity;
=======
                const int m_severity = -1;
                GU::Core::String m_msg;
>>>>>>> 437bc380e25ab9e529e4e16c58790e6130ff9bc3
        };

    }

}
#endif // LISTENER_H
