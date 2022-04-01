#include "GameUtilities/Log/Component/FileComponent.h"

namespace GU
{
    namespace Log
    {

        FileComponent::FileComponent():
        LogComponent(componentId::FILE)
        {

        }


        FileComponent::FileComponent(GU::Core::String &file):
        LogComponent(componentId::FILE),
        m_file(file)
        {

        }


        FileComponent& FileComponent::operator = (const FileComponent &comp)
        {
          m_file = comp.m_file;
          return *this;
        }


        GU::Core::String FileComponent::format()
        {
          return m_file;
        }

    }
}
