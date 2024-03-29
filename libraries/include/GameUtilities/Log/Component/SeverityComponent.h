#ifndef GU_LOG_SECURITYCOMPONENT_H
#define GU_LOG_SECURITYCOMPONENT_H
/*********************************************************************************//**
*   @author	Wayne J Larson Jr.
*   @date   4/8/2022
*   @file   SeverityComponent.h
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
#include "GameUtilities/Log/Component/LogComponent.h"
#include "GameUtilities/Log/Component/ComponentId.h"
#include "GameUtilities/Log/LogType.h"

namespace GU
{
    namespace Log
    {
        /*********************************************************************************//**
        *   @class  SeverityComponent
        *   @brief  This class defines the severity of a log message.
        *************************************************************************************/
        struct LOG_EXPORT SeverityComponent: public LogComponent
        {
            /*************************************************************//**
            * @brief The constructor
            *****************************************************************/
            SeverityComponent();


            /*************************************************************//**
            * @brief The constructor
            * @param severity indicates how important the log is.
            *****************************************************************/
            SeverityComponent(const LogType &severity);


            /*************************************************************//**
            * @brief  Assignment operator overload.
            * @param  comp contains the values to be assigned to the current
            *         object.
            * @return A reference to the updated current object.
            *****************************************************************/
            SeverityComponent& operator = (const SeverityComponent &comp);


            /*************************************************************//**
            * @brief  This method creates a string from the current severity.
            * @return A string representing the current severity object.
            *****************************************************************/
            GU::Core::String format();

            LogType m_severity = LogType::GU_MESSAGE;           /**< The logs severity */
        };
    }
}
#endif
