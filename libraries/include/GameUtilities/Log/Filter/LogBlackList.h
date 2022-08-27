#ifndef LOG_BLACKLIST_H
#define LOG_BLACKLIST_H
#include "GameUtilities/Log/Filter/LogFilter.h"
#include "log_export.h"
namespace GU
{
    namespace Log
    {
      claSS LOG_EXPORT LogBlackList: public LogFilter
      {
      public:
        LogBlackList();
        virtual bool filter(std::shared_ptr<GU::Log::LogEntry> entry);
        virtual ~LogBlackList();

      };
    }
}
#endif
