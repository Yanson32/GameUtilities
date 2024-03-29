#ifndef GU_LOG_COMPONENT_H
#define GU_LOG_COMPONENT_H
/*********************************************************************************//**
*   @author	Wayne J Larson Jr.
*   @date   4/8/2022
*   @file   LogComponent.h
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
#include "log_export.h"
#include "GameUtilities/Core/String.h"
#include "GameUtilities/Log/Component/ComponentId.h"
namespace GU
{
    namespace Log
    {
        /*********************************************************************************//**
        *   @class  LogComponent
        *   @brief  This class is used as a base class for all log components.
        *************************************************************************************/
        struct LOG_EXPORT LogComponent
        {
            /*************************************************************//**
            * @brief Constructor
            * @param id is a unique identifyer for the current object type
            *****************************************************************/
            LogComponent(const componentId &id);


            /*************************************************************//**
            * @brief  Equality operator
            * @param  comp will be used to check for equality against the
            *         current LogComponent object.
            * @return True of the objects are equal and false otherwise
            *****************************************************************/
            bool operator == (const LogComponent &comp);


            /*************************************************************//**
            * @brief  Equality operator
            * @param  comp will be used to check for equality against the
            *         current componentId.
            * @return True of the objects are equal and false otherwise
            *****************************************************************/
            bool operator == (const componentId &comp);


            /*************************************************************//**
            * @brief  Not equal operator
            * @param  comp will be used to check for equality against the
            *         current LogComponent object.
            * @return True of the objects are not equal and false otherwise
            *****************************************************************/
            bool operator != (const LogComponent &comp);
            

            /*************************************************************//**
            * @brief  Not equal operator
            * @param  comp will be used to check for equality against the
            *         current componentId.
            * @return True of the objects are not equal and false otherwise
            *****************************************************************/
            bool operator != (const componentId &comp);
            

            /*************************************************************//**
            * @brief  This method formats the data in the current object
            *         and turns it into a string.
            * @return The formatted string.
            *****************************************************************/
            virtual GU::Core::String format() = 0;

            const componentId m_id;            /**< A unique identifyer for the component type */
        };

    }
}
#endif
