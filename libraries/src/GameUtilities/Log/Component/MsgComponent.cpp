#include "GameUtilities/Log/Component/MsgComponent.h"


namespace GU
{
    namespace Log
    {
        /*****************************************************************
        * @brief: The constructor
        *****************************************************************/
        MsgComponent::MsgComponent():
        LogComponent(componentId::MSG)
        {


        }


        /*****************************************************************
        * @brief: The constructor
        * @param: msg is the human readable message to be displayed in the
        *         log message.
        *****************************************************************/
        MsgComponent::MsgComponent(const GU::Core::String &msg):
        LogComponent(componentId::MSG),
        m_msg(msg)
        {

        }


        /*****************************************************************
        * @brief:  Assignment operator for the MsgComponent.
        * @param:  comp this object will be used to initialize the current
        *          object.
        * @return: A reference to the updated current object.
        *****************************************************************/
        MsgComponent& MsgComponent::operator = (const MsgComponent &comp)
        {
          m_msg = comp.m_msg;
          return *this;
        }


        /*****************************************************************
        * @brief:  This method creates a string formatted appropriatly for
        *          a log message.
        * @return: The formatted string.
        *****************************************************************/
        GU::Core::String MsgComponent::format()
        {
          return m_msg;
        }
    }
}
