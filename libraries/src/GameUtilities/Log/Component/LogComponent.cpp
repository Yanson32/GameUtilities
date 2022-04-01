#include "GameUtilities/Log/Component/LogComponent.h"

namespace GU
{
    namespace Log
    {

        LogComponent::LogComponent(const componentId &id):
        m_id(id)
        {

        }


        bool LogComponent::operator == (const LogComponent &comp)
        {
          return this->m_id == comp.m_id;
        }


        bool LogComponent::operator == (const componentId &comp)
        {
          return this->m_id == comp;
        }

    }
}
