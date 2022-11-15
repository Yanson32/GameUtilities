/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
*   @date   4/8/2022
*   @class  DateComponent
*   @file   DateComponent.h
*   @brief  This class defines a log component for dates. 
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
#include "GameUtilities/Log/Component/DateComponent.h"
#include "GameUtilities/Core/Macros.h"
#include <string>
#include <sstream>

namespace GU
{
    namespace Log
    {

        /*********************************************************************************//**
        *	@brief  Constructor 
        *************************************************************************************/
        DateComponent::DateComponent():
        LogComponent(componentId::DATE)
        {


        }


        /*********************************************************************************//**
        *	@brief  Constructor 
        *   @param  month is the month component of the current date.
        *   @param  day is the day component of the current date.
        *   @param  year is the year component of the current date.
        *************************************************************************************/
        DateComponent::DateComponent(const unsigned &month, const unsigned &day, const unsigned &year):
        LogComponent(componentId::DATE),
        m_month(month),
        m_day(day),
        m_year(year)
        {
             
        }

        
        /*********************************************************************************//**
        *	@brief  This method will copy the data members of the given component into the 
        *           current component.
        *   @param  comp is the log component to be copied. 
        *   @return A reference to the current date object.
        *************************************************************************************/
        DateComponent& DateComponent::operator = (const DateComponent &comp) 
        {
          UNUSED(comp);
          return *this;
        }


        /*********************************************************************************//**
        *	@brief  This method converts the data stored in the current component into a string. 
        *   @return A string equal to the current data in the log component. 
        *************************************************************************************/
        GU::Core::String DateComponent::format()
        {
          std::stringstream ss;
          ss << std::to_string(m_month);
          ss << " ";
          ss << std::to_string(m_day);
          ss << " ";
          ss << std::to_string(m_year);
          return ss.str(); 
        }

    }
}
