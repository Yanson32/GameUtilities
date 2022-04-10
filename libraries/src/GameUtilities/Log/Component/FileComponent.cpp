#include "GameUtilities/Log/Component/FileComponent.h"

namespace GU
{
    namespace Log
    {
        /*****************************************************************
        * @brief: Constructor
        *****************************************************************/
        FileComponent::FileComponent():
        LogComponent(componentId::FILE)
        {

        }


        /*****************************************************************
        * @brief: Constructor
        * @param: file is the location where the log originated from
        *****************************************************************/
        FileComponent::FileComponent(const GU::Core::String &file):
        LogComponent(componentId::FILE),
        m_file(file)
        {

        }


        /*****************************************************************
        * @brief:  Assignment operator
        * @param:  comp will be used to initialize the current object.
        * @return: A reference to the current object after it has been
        *          updated.
        *****************************************************************/
        FileComponent& FileComponent::operator = (const FileComponent &comp)
        {
          m_file = comp.m_file;
          return *this;
        }


        /*****************************************************************
        * @brief:  This method formats the current objec into a string
        *          suitable for a log message.
        * @return: A formatted string for use in a log message.
        *****************************************************************/
        GU::Core::String FileComponent::format()
        {
          return m_file;
        }

    }
}
