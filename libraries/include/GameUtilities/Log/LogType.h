#ifndef GAMEUTILITIES_LOG_TYPE
#define GAMEUTILITIES_LOG_TYPE
namespace GU
{
    namespace Log
    { 
        enum  class LogType
        {
            GU_FATAL_ERROR, 
            GU_ERROR,
            GU_WARNING,
            GU_MESSAGE, 
            GU_VERBOSE, 
            GU_STATUS, 
            GU_SYSTEM_ERROR,
            GU_DEBUG,
            GU_TRACE
        };
    }
}

#endif

