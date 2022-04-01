#ifndef LOG_WHITELIST_H
#define LOG_WHITELIST_H
#include "log_export.h"
#include "GameUtilities/Log/Filter/LogFilter.h"
namespace GU
{
    namespace Log
    {
      claSS LOG_EXPORT LogWhiteList: public LogFilter
      {
      public:
        LogWhiteList();
        virtual GU::Core::String filter(std::shared_ptr<GU::Log::LogEntry> entry);
        virtual ~LogWhiteList();

      };
    }
}
#endif
