#ifndef GU_LOG_FILE_TARGET_H
#define GU_LOG_FILE_TARGET_H

#include "log_export.h"
#include "GameUtilities/Log/Target/LogTarget.h"
#include "GameUtilities/Core/String.h"
#include <fstream>

namespace GU
{
    namespace Log
    {
  		class LOG_EXPORT LogFileTarget: public LogTarget
  		{
  			public:
  				LogFileTarget(const GU::Core::String path);
          virtual void write(const GU::Core::String &msg) override;
  				virtual ~LogFileTarget();
  			private:
  				const GU::Core::String m_path;
          std::ofstream m_file;
  		};
	}
}

#endif
