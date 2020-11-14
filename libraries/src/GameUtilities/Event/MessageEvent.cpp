#include "GameUtilities/Event/MessageEvent.h"

namespace GU
{
    namespace Evt
    {
        MessageEvent::MessageEvent(const std::string &msg, const int messageType):
        m_messageType(messageType)
        {
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


