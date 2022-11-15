#ifndef GU_LOG_LINECOMPONENT_H
#define GU_LOG_LINECOMPONENT_H
/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
*   @date   4/8/2022
*   @class  LineComponent
*   @file   LineComponent.h
*   @brief  This class defines a LogComponent that represents the line number
*           where the log message originated from.
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
      struct LOG_EXPORT LineComponent: public LogComponent
      {
        /*************************************************************//**
        * @brief The constructor
        *****************************************************************/
        LineComponent();


        /*************************************************************//**
        * @brief The constructor
        * @param line the line number where the log message originated from
        *****************************************************************/
        LineComponent(const int &line);


        /*************************************************************//**
        * @brief  Assignment operator overload.
        * @param  comp contains the values to be assigned to the current
        *         object.
        * @return A reference to the updated current object.
        *****************************************************************/
        LineComponent& operator = (const LineComponent &comp);


        /*************************************************************//**
        * @brief  This method creates a string from the current line number.
        * @return A string representing the current line number.
        *****************************************************************/
        virtual GU::Core::String format() override;
    public:
        int m_line = -1;    /**< The line in source code where the log message originated */
      };
    }
}
#endif
