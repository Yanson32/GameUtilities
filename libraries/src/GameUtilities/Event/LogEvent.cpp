#include "GameUtilities/Event/LogEvent.h"
#include "GameUtilities/Core/Macros.h"
namespace GU
{
    namespace Evt
    {
        LogEvent::LogEvent(const std::string &msg, const LogType newSeverity):
        m_severity(newSeverity)
        {
            UNUSED(msg);
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

