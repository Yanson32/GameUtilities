#ifndef GU_LOG_FILE_TARGET_H
#define GU_LOG_FILE_TARGET_H

#include "log_export.h"
#include "GameUtilities/Log/LogTarget.h"
#include "GameUtilities/Core/String.h"


namespace GU
{
    namespace Log
    { 
	
		class LOG_EXPORT LogFileTarget: public LogTarget
		{
			public:
				LogFileTarget(const GU::Core::String path);
				virtual bool write() const override;
				virtual ~LogFileTarget();
			private:
				const GU::Core::String m_path;
		};
	}
	
}

#endif