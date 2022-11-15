/*********************************************************************************//**
*   @author	Wayne J Larson Jr.
*   @date   5/24/2022
*   @class  TimeComponent
*   @file   TimeComponent.cpp
*   @brief  This class represents the time component for the log system 
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
#include "GameUtilities/Log/Component/TimeComponent.h"
#include "GameUtilities/Core/Macros.h"
#include <sstream>

namespace GU
{
    namespace Log
    {

        /*********************************************************************************//**
        *	@brief  Constructor
        *************************************************************************************/
        TimeComponent::TimeComponent():
        LogComponent(componentId::TIME)
        {

        }


        /*********************************************************************************//**
        *	@brief  Constructor
        *   @param  hours is the hour component of the current time
        *   @param  minutes is the minutes component of the current time.
        *   @param  seconds is the seconds component of the current time
        *************************************************************************************/
        TimeComponent::TimeComponent(const int &hours, const int &minutes, const int &seconds):
        LogComponent(componentId::TIME),
        m_hours(hours),
        m_minutes(minutes),
        m_seconds(seconds)
        {

        }
        
        
        /*********************************************************************************//**
        *	@brief  This method copies the given object into the current object with deep copy.
        *   @param  comp is the object to be copied. 
        *   @return Is a reference to the current updated object
        *************************************************************************************/
        TimeComponent& TimeComponent::operator = (const TimeComponent &comp)
        {
            UNUSED(comp);
            m_hours = comp.m_hours;
            m_minutes = comp.m_minutes;
            m_seconds = comp.m_seconds;
            return *this;
        }


        /*********************************************************************************//**
        *	@brief  This method returns a string which is formatted correctoy for a log file. 
        *           The string will represent the time the log was created.
        *   @return A string representing the time the log was created. 
        *************************************************************************************/
        GU::Core::String TimeComponent::format()
        {
          
            std::stringstream ss;
            ss << "[";
            ss << m_hours;
            ss << ":";
            ss << m_minutes;
            ss << ":";
            ss << m_seconds;
            ss << "]";
            return ss.str();
        }
    }
}
