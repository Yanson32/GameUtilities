/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
*   @date   4/8/2022
*   @file   LineComponent.cpp
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
#include "GameUtilities/Log/Component/LineComponent.h"
#include "GameUtilities/Log/Component/ComponentId.h"
#include <sstream>
#include <iostream>

namespace GU
{
    namespace Log
    {

        /*************************************************************//**
        * @brief The constructor
        *****************************************************************/
        LineComponent::LineComponent():
        LogComponent(GU::Log::componentId::LINE)
        {

        }


        /*************************************************************//**
        * @brief The constructor
        * @param line the line number where the log message originated from
        *****************************************************************/
        LineComponent::LineComponent(const int &line):
        LogComponent(GU::Log::componentId::LINE),
        m_line(line)
        {

        }


        /*************************************************************//**
        * @brief  Assignment operator overload.
        * @param  comp contains the values to be assigned to the current
        *         object.
        * @return A reference to the updated current object.
        *****************************************************************/
        LineComponent& LineComponent::operator = (const LineComponent &comp)
        {
            m_line = comp.m_line;
            return *this;
        }


        /*************************************************************//**
        * @brief  This method creates a string from the current line number.
        * @return A string representing the current line number.
        *****************************************************************/
        GU::Core::String LineComponent::format()
        {
            std::stringstream ss;
            ss << m_line;
            return ss.str();
        }
    }
}
