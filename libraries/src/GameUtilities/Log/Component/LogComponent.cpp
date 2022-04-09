#include "GameUtilities/Log/Component/LogComponent.h"

namespace GU
{
    namespace Log
    {
      /*****************************************************************
      * @brief: Constructor
      * @param: id is a unique identifyer for the current object type
      *****************************************************************/
        LogComponent::LogComponent(const componentId &id):
        m_id(id)
        {

        }

        /*****************************************************************
        * @brief:  Equality operator
        * @param:  comp will be used to check for equality against the
        *          current LogComponent object.
        * @return: True of the objects are equal and false otherwise
        *****************************************************************/
        bool LogComponent::operator == (const LogComponent &comp)
        {
          return this->m_id == comp.m_id;
        }


        /*****************************************************************
        * @brief:  Equality operator
        * @param:  comp will be used to check for equality against the
        *          current componentId object.
        * @return: True of the objects are equal and false otherwise
        *****************************************************************/
        bool LogComponent::operator == (const componentId &comp)
        {
          return this->m_id == comp;
        }

    }
}
