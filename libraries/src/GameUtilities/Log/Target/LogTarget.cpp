/*********************************************************************************//**
*	@author	 Wayne J Larson Jr.
*	@date 	 5/30/22
*   @class   LogTarget
*   @file    LogTarget.cpp
*	@brief   This is the base class for all Log Targets. 
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
#include "GameUtilities/Log/Target/LogTarget.h"
#include <iostream>
#include "GameUtilities/Core/Macros.h"
namespace GU
{
    namespace Log
    {
        /*********************************************************************************//**
        *	@brief  Constructor 
        *************************************************************************************/
  		LogTarget::LogTarget()
  		{

  		}

        
        /*********************************************************************************//**
        *	@brief  This method retruns true if the current log target and the passed log
        *           target are equal.
        *   @param  logTarget is the log target the current log target will be checked against
        *           for equality.
        *   @return True if the current log target and passed log target are equal and false
        *           otherwise. 
        *************************************************************************************/
  		bool LogTarget::operator == (const LogTarget &logTarget) const
  		{
  			return (*this)==logTarget;
  		}


        /*********************************************************************************//**
        *	@brief  Destructor 
        *************************************************************************************/
  		LogTarget::~LogTarget()
  		{

        }
    }
}
