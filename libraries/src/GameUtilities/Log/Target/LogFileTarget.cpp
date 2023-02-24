/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
*	@date 	5/27/22
*   @file   LogFileTarget.cpp
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
#include "GameUtilities/Log/Target/LogFileTarget.h"
#include <iostream>
#include <fstream>

namespace GU
{
    namespace Log
    {
        /*********************************************************************************//**
        *	@brief  Constructor
        *   @param  path is the full path to the file where the log will be written.  
        *************************************************************************************/
        LogFileTarget::LogFileTarget(const GU::Core::String path):
		m_path(path)
		{
		}


        /*********************************************************************************//**
        *	@brief  This method writes a log entry to a log file.
        *   @pre    The log entry must be converted to a string.
        *   @param  msg is a pre formatted log entry in string form. 
        *************************************************************************************/
		void LogFileTarget::write(const GU::Core::String &msg)
        {
            std::ofstream m_file;
            
            m_file.open(m_path, std::ios_base::app);
            if(!m_file.good())
            {
                std::cout << "Unable to open file " << m_path.toStdString() << std::endl;
            }
        
            m_file << msg.toStdString() << std::endl;
            m_file.close();
		}


        /*********************************************************************************//**
        *	@brief  Destructor 
        *************************************************************************************/
		LogFileTarget::~LogFileTarget()
		{
		}
	}
}
