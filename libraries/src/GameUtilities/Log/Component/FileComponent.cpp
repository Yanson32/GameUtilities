/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
*   @date   4/8/2022
*   @class  LogComponent
*   @file   LogComponent.cpp
*   @brief  This class is used to define a file where the log originated
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
#include "GameUtilities/Log/Component/FileComponent.h"

namespace GU
{
    namespace Log
    {
        /*************************************************************//**
        * @brief Constructor
        *****************************************************************/
        FileComponent::FileComponent():
        LogComponent(componentId::FILE)
        {

        }


        /*************************************************************//**
        * @brief Constructor
        * @param file is the location where the log originated from
        *****************************************************************/
        FileComponent::FileComponent(const GU::Core::String &file):
        LogComponent(componentId::FILE),
        m_file(file)
        {

        }


        /*************************************************************//**
        * @brief  Assignment operator
        * @param  comp will be used to initialize the current object.
        * @return A reference to the current object after it has been
        *         updated.
        *****************************************************************/
        FileComponent& FileComponent::operator = (const FileComponent &comp)
        {
          m_file = comp.m_file;
          return *this;
        }


        /*************************************************************//**
        * @brief  This method formats the current objec into a string
        *         suitable for a log message.
        * @return A formatted string for use in a log message.
        *****************************************************************/
        GU::Core::String FileComponent::format()
        {
          return m_file;
        }

    }
}
