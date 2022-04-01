#ifndef GU_LOG_TARGET_H
#define GU_LOG_TARGET_H

#include "log_export.h"
#include "GameUtilities/Core/String.h"
#include <iostream>
namespace GU
{
    namespace Log
    {
  		class LOG_EXPORT LogTarget
  		{
  			public:
  				LogTarget();
  				virtual void write(const GU::Core::String &msg) = 0;
  				bool operator == (const LogTarget &logTarget) const;
  				virtual ~LogTarget();

  		};
	}
}

#endif
