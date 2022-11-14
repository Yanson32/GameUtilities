/*********************************************************************************//**
*   @author	Wayne J Larson Jr.
*   @date   4/8/2022
*   @class  LogComponent
*   @file   LogComponent.cpp
*   @brief  This class is used as a base class for all log components.
*************************************************************************************/
#include "GameUtilities/Log/Component/LogComponent.h"

namespace GU
{
    namespace Log
    {
        /*************************************************************//**
        * @brief Constructor
        * @param id is a unique identifyer for the current object type
        *****************************************************************/
        LogComponent::LogComponent(const componentId &id):
        m_id(id)
        {

        }

        /*************************************************************//**
        * @brief  Equality operator
        * @param  comp will be used to check for equality against the
        *         current LogComponent object.
        * @return True of the objects are equal and false otherwise
        *****************************************************************/
        bool LogComponent::operator == (const LogComponent &comp)
        {
            return this->m_id == comp.m_id;
        }


        /*************************************************************//**
        * @brief  Equality operator
        * @param  comp will be used to check for equality against the
        *         current componentId.
        * @return True of the objects are equal and false otherwise
        *****************************************************************/
        bool LogComponent::operator == (const componentId &comp)
        {
            return this->m_id == comp;
        }

        
        /*************************************************************//**
        * @brief  Not equal operator
        * @param  comp will be used to check for equality against the
        *         current LogComponent object.
        * @return True of the objects are not equal and false otherwise
        *****************************************************************/
        bool LogComponent::operator != (const LogComponent &comp)
        {
            return this->m_id != comp.m_id;
        }


        /*************************************************************//**
        * @brief  Not equal operator
        * @param  comp will be used to check for equality against the
        *         current componentId.
        * @return True of the objects are not equal and false otherwise
        *****************************************************************/
        bool LogComponent::operator != (const componentId &comp)
        {
            return this->m_id != comp;
        }
    }
}
