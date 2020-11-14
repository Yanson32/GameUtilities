#include "GameUtilities/Event/LogEvent.h"

namespace GU
{
    namespace Evt
    {
        LogEvent::LogEvent(const std::string &msg, const int newSeverity):
        m_severity(newSeverity)
        {
            //ctor
        }

        int LogEvent::getSeverity() const
        {
            return m_severity;
        }
        LogEvent::~LogEvent()
        {
            //dtor
        }
    }
}

