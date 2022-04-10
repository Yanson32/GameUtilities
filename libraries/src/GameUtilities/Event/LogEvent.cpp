#include "GameUtilities/Event/LogEvent.h"
#include "GameUtilities/Core/Macros.h"
#include "GameUtilities/Event/EventId.h"
namespace GU
{
    namespace Evt
    {
        LogEvent::LogEvent(const GU::Core::String &msg, const int &newSeverity, const int newLine, const GU::Core::String &newFile):
	      Event(static_cast<int>(GU::Evt::EventId::LOG), newLine, newFile),
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
