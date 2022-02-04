#ifndef GU_LOG_TARGET_H
#define GU_LOG_TARGET_H

#include "log_export.h"

namespace GU
{
    namespace Log
    { 
		class LOG_EXPORT LogTarget
		{
			public:
				LogTarget();
				virtual bool write() const = 0;
				bool operator == (const LogTarget &logTarget) const;
				virtual ~LogTarget();
			
		};
	}
}

#endif