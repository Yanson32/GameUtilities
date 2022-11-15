/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
*   @date   4/8/2022
*   @class  MsgComponent
*   @file   MsgComponent.cpp
*   @brief  This class defines the human readable message of the log message.
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
#include "GameUtilities/Log/Component/MsgComponent.h"


namespace GU
{
    namespace Log
    {
        /*************************************************************//**
        * @brief The constructor
        *****************************************************************/
        MsgComponent::MsgComponent():
        LogComponent(componentId::MSG)
        {


        }


        /*************************************************************//**
        * @brief The constructor
        * @param msg is the human readable message to be displayed in the
        *        log message.
        *****************************************************************/
        MsgComponent::MsgComponent(const GU::Core::String &msg):
        LogComponent(componentId::MSG),
        m_msg(msg)
        {

        }


        /*************************************************************//**
        * @brief  Assignment operator for the MsgComponent.
        * @param  comp this object will be used to initialize the current
        *         object.
        * @return A reference to the updated current object.
        *****************************************************************/
        MsgComponent& MsgComponent::operator = (const MsgComponent &comp)
        {
          m_msg = comp.m_msg;
          return *this;
        }


        /*************************************************************//**
        * @brief  This method creates a string formatted appropriatly for
        *         a log message.
        * @return The formatted string.
        *****************************************************************/
        GU::Core::String MsgComponent::format()
        {
          return m_msg;
        }
    }
}
