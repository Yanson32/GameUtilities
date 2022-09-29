#include "GameUtilities/Event/Events/OnMessage.h"
#include "GameUtilities/Event/EventId.h"

namespace GU
{
    namespace Evt
    {
        OnMessage::OnMessage(const GU::Core::String &msg, const int &messageType, const int &line, const char* file):
        Event(static_cast<int>(GU::Evt::EventId::ON_MESSAGE), line, file),
        m_msg(msg),
        m_messageType(messageType)
        {
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


