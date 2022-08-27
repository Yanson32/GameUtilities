#ifndef GU_LOG_FILE_TARGET_H
#define GU_LOG_FILE_TARGET_H
/*********************************************************************************//**
*	@author	        Wayne J Larson Jr.
*	@date 	        5/27/22
*	@description    This class defines a log target that will write logs to a file 
*************************************************************************************/

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
