#include "GameUtilities/Event/LogEvent.h"
#include "GameUtilities/Core/Macros.h"
#include "GameUtilities/Event/EventId.h"
namespace GU
{
    namespace Evt
    {
        LogEvent::LogEvent(const GU::Core::String &msg, const int &newSeverity):
	Event(static_cast<int>(GU::Evt::EventId::LOG)),
        m_severity(newSeverity),
	m_msg(msg)
        {
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

