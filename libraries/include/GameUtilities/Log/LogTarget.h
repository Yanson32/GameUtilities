#include "log_export.h"

namespace GU
{
    namespace Log
    { 
		class LOG_EXPORT LogTarget
		{
			public:
				LogTarget();
				bool operator == (const LogTarget &logTarget) const;
				virtual ~LogTarget();
			
		};
	}
}