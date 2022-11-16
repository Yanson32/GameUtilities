#ifndef GU_LOG_MSGCOMPONENT_H
#define GU_LOG_MSGCOMPONENT_H
/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
*   @date   4/8/2022
*   @file   MsgComponent.h
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


namespace GU
{
    namespace Log
    {
        /*********************************************************************************//**
        *   @class  MsgComponent
        *   @brief  This class defines the human readable message of the log message.
        *************************************************************************************/
        struct LOG_EXPORT MsgComponent: public LogComponent
        {
            public:
                /*************************************************************//**
                * @brief The constructor
                *****************************************************************/
                MsgComponent();


                /*************************************************************//**
                * @brief The constructor
                * @param msg is the human readable message to be displayed in the
                *        log message.
                *****************************************************************/
                MsgComponent(const GU::Core::String &msg);


                /*************************************************************//**
                * @brief  Assignment operator for the MsgComponent.
                * @param  comp this object will be used to initialize the current
                *         object.
                * @return A reference to the updated current object.
                *****************************************************************/
                MsgComponent& operator = (const MsgComponent &comp);


                /*************************************************************//**
                * @brief  This method creates a string formatted appropriatly for
                *         a log message.
                * @return The formatted string.
                *****************************************************************/
                GU::Core::String format();
            public:
                GU::Core::String m_msg;              /**< The current log message */
        };
    }
}
#endif
