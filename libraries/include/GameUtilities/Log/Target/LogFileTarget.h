#ifndef GU_LOG_FILE_TARGET_H
#define GU_LOG_FILE_TARGET_H
/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
*	@date 	5/27/22
*   @class  LogFileTarget
*   @file   LogFileTarget.h
*	@brief  This class defines a log target that will write logs to a file 
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
#include "GameUtilities/Log/Target/LogTarget.h"
#include "GameUtilities/Core/String.h"

namespace GU
{
    namespace Log
    {
  		class LOG_EXPORT LogFileTarget: public LogTarget
  		{
  			public:
                /*********************************************************************************//**
                *	@brief  Constructor
                *   @param  path is the full path to the file where the log will be written.  
                *************************************************************************************/
  				LogFileTarget(const GU::Core::String path);
                

                /*********************************************************************************//**
                *	@brief  This method writes a log entry to a log file.
                *   @pre    The log entry must be converted to a string.
                *   @param  msg is a pre formatted log entry in string form. 
                *************************************************************************************/
                virtual void write(const GU::Core::String &msg) override;
                

                /*********************************************************************************//**
                *	@brief  Destructor 
                *************************************************************************************/
  				virtual ~LogFileTarget();
  			private:
  				const GU::Core::String m_path;
  		};
	}
}

#endif
