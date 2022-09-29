#include "GameUtilities/Event/Events/OnMessage.h"
#include "GameUtilities/Core/Macros.h"

namespace GU
{
    namespace Evt
    {
        OnMessage::OnMessage(const std::string &msg, const int messageType):
        m_messageType(messageType)
        {
            UNUSED(msg);
            //ctor
        }


        int OnMessage::getMessageType() const
        {
            return m_messageType;
        }


        OnMessage::~OnMessage()
        {
            //dtor
        }
    }
}


