#include "GameUtilities/Log/Component/MsgComponent.h"


namespace GU
{
    namespace Log
    {
        MsgComponent::MsgComponent():
        LogComponent(componentId::MSG)
        {


        }


        MsgComponent::MsgComponent(const GU::Core::String &msg):
        LogComponent(componentId::MSG),
        m_msg(msg)
        {

        }


        MsgComponent& MsgComponent::operator = (const MsgComponent &comp)
        {
          m_msg = comp.m_msg;
          return *this;
        }


        GU::Core::String MsgComponent::format()
        {
          return m_msg;
        }
    }
}
