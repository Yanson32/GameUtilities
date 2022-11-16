/*********************************************************************************//**
*   @author	Wayne J Larson Jr.
*   @date   4/8/2022
*   @file   SeverityComponent.cpp
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
#include "GameUtilities/Log/Component/SeverityComponent.h"

namespace GU
{
    namespace Log
    {
        /*************************************************************//**
        * @brief The constructor
        *****************************************************************/
        SeverityComponent::SeverityComponent():
        LogComponent(componentId::SEVERITY)
        {

        }


        /*************************************************************//**
        * @brief The constructor
        * @param severity indicates how important the log is.
        *****************************************************************/
        SeverityComponent::SeverityComponent(const LogType &severity):
        LogComponent(componentId::SEVERITY),
        m_severity(severity)
        {

        }


        /*************************************************************//**
        * @brief  Assignment operator overload.
        * @param  comp contains the values to be assigned to the current
        *         object.
        * @return A reference to the updated current object.
        *****************************************************************/
        SeverityComponent& SeverityComponent::operator = (const SeverityComponent &comp)
        {
            m_severity = comp.m_severity;
            return *this;
        }


        /*************************************************************//**
        * @brief  This method creates a string from the current severity.
        * @return A string representing the current severity object.
        *****************************************************************/
        GU::Core::String SeverityComponent::format()
        {

            switch(m_severity)
            {
                case GU::Log::LogType::GU_FATAL_ERROR:
                    return "Fatal Error";
                case GU::Log::LogType::GU_ERROR:
                    return "Error";
                case GU::Log::LogType::GU_WARNING:
                    return "Warning";
                case GU::Log::LogType::GU_MESSAGE:
                    return "Message";
                case GU::Log::LogType::GU_VERBOSE:
                    return "Verbose";
                case GU::Log::LogType::GU_STATUS:
                    return "Status";
                case GU::Log::LogType::GU_SYSTEM_ERROR:
                    return "System Error";
                case GU::Log::LogType::GU_DEBUG:
                    return "Debug";
                case GU::Log::LogType::GU_TRACE:
                    return "Trace";
                default:
                    return "";

            }
        }
    }
}
