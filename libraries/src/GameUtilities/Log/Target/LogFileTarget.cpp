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
