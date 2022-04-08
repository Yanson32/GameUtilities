#include "GameUtilities/Event/LogEvent.h"
#include "GameUtilities/Core/Macros.h"
#include "GameUtilities/Event/EventId.h"
namespace GU
{
    namespace Evt
    {
        LogEvent::LogEvent(const std::string &msg, const int &newSeverity):
	Event(static_cast<int>(GU::Evt::EventId::LOG)),
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

