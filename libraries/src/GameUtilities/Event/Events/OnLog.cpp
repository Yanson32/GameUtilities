#include "GameUtilities/Event/Events/OnLog.h"
#include "GameUtilities/Core/Macros.h"
#include "GameUtilities/Event/EventId.h"
namespace GU
{
    namespace Evt
    {
        OnLog::OnLog(const GU::Core::String &msg, const int &newSeverity, const int &line, const char* file):
	    Event(static_cast<int>(GU::Evt::EventId::LOG), line, file),
        m_severity(newSeverity),
	    m_msg(msg)
        {
        
        }


        GU::Core::String OnLog::getMessage() const
        {
          return m_msg;
        }


	      int OnLog::getSeverity() const
        {
            return m_severity;
        }
        

        OnLog::~OnLog()
        {
            //dtor
        }
    }
}
