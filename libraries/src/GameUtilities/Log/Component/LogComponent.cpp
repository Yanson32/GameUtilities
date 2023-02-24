/*********************************************************************************//**
*   @author	Wayne J Larson Jr.
*   @date   4/8/2022
*   @file   LogComponent.cpp
*************************************************************************************/

/*************************************************************************
*                           COPYRIGHT NOTICE
* GameUtilities is a toolkit for making 2d video games.
* Copyright (C) 2018 Wayne J Larson Jr. 
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 3 as 
* published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
***************************************************************************/
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
