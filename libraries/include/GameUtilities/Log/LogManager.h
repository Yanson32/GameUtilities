#ifndef GAMEUTILITIES_LOG_LOGMANAGER_H
#define GAMEUTILITIES_LOG_LOGMANAGER_H

#include "GameUtilities/Log/LogTarget.h"
#include "log_export.h"

namespace GU
{
    namespace Log
    { 
		class LOG_EXPORT LogManager
		{
			public:
				static LogManager& inst();
				void add(LogTarget &logTarget);
				LogTarget& getTarget();
				virtual ~LogManager();
			private:
				LogManager();
				LogManager operator = (const LogManager logManager) = delete;
				LogManager(const LogManager &logManager) = delete;
		};
	}
}
#endif