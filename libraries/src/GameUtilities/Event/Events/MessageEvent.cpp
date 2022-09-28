#include "GameUtilities/Event/Events/MessageEvent.h"
#include "GameUtilities/Core/Macros.h"

namespace GU
{
    namespace Evt
    {
        MessageEvent::MessageEvent(const std::string &msg, const int messageType):
        m_messageType(messageType)
        {
            UNUSED(msg);
            //ctor
        }

        int MessageEvent::getMessageType() const
        {
            return m_messageType;
        }
        MessageEvent::~MessageEvent()
        {
            //dtor
        }
    }
}


