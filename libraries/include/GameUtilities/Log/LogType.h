#ifndef GAMEUTILITIES_LOG_TYPE
#define GAMEUTILITIES_LOG_TYPE
namespace GU
{
    namespace Log
    { 
        enum  class LogType
        {
            FATAL_ERROR, 
            ERROR,
            WARNING,
            MESSAGE, 
            VERBOSE, 
            STATUS, 
            SYSTEM_ERROR,
            DEBUG,
            TRACE
        };
    }
}

#endif
