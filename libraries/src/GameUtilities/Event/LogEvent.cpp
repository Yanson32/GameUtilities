#include "GameUtilities/Event/LogEvent.h"
#include "GameUtilities/Core/Macros.h"
namespace GU
{
    namespace Evt
    {
        LogEvent::LogEvent(const std::string &msg, const GU::Log::LogType newSeverity):
        m_severity(newSeverity)
        {
            UNUSED(msg);
        } 

	GU::Log::LogType LogEvent::getSeverity() const
        {
            return m_severity;
        }
        LogEvent::~LogEvent()
        {
            //dtor
        }
    }
}

