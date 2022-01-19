#ifndef GU_LOG_FILE_TARGET_H
#define GU_LOG_FILE_TARGET_H

#include "log_export.h"
#include "GameUtilities/Log/LogTarget.h"

namespace GU
{
    namespace Log
    { 
	
		class LOG_EXPORT LogFileTarget: public LogTarget
		{
			public:
				LogFileTarget();
				virtual ~LogFileTarget();
		};
	}
	
}

#endif