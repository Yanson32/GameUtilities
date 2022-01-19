#ifndef GU_LOG_FORMATTER_H
#define GU_LOG_FORMATTER_H

#include "log_export.h"
#include "GameUtilities/Core/String.h"
namespace GU
{
    namespace Log
    { 
	
		class LOG_EXPORT LogFormatter
		{
			public:
				LogFormatter();
				virtual ~LogFormatter();
			private:
				GU::Core::String format;
		};
	}
}

#endif