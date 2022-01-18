#ifndef GAMEUTILITIES_LOG_LOGMANAGER_H
#define GAMEUTILITIES_LOG_LOGMANAGER_H

#include "GameUtilities/Log/LogTarget.h"
#include "GameUtilities/Log/LogFormatter.h"
#include "log_export.h"
#include <cstddef>

namespace GU
{
    namespace Log
    { 
		class LOG_EXPORT LogManager
		{
			public:
				LogManager();
				void add(LogTarget &logTarget);
				LogTarget& getTarget(const std::size_t &index);
				bool remove(const LogTarget &logTarget);
				std::size_t getTargetCount() const;
				void add(LogFormatter &logFormatter);
				LogFormatter& getFormatter();
				virtual ~LogManager();
			private:
				class Impl;
				Impl* pimpl = nullptr;
		};
	}
}
#endif