#include "GameUtilities/Core/Paths.h"
#ifdef _WIN32
#include <windows.h>
#endif

#ifdef linux
#include <cstdlib>
#endif


/**************************************************************************
* @brief:    This function returns a os specific path to the appropriate 1
*            directory for a config file.
* @param     appName is the name of the application. The name will be 
*            added to the end of the path. The final path may not exist 
*            and so it may need to be created by the caller.
**************************************************************************/
GU::Core::String getConfigDir(const GU::Core::String &appName)
{
    #ifdef _WIN32
    return SHGetKnownFolderPath(CSIDL_APPDATA) + "/" + appName.toStdString();
    #endif 
    
    #ifdef linux
    GU::Core::String temp;
    temp = getenv("HOME");
    temp += "/";
    temp += ".config"; 
    temp += "/";
    temp += appName;
    return temp; 
    #endif	
    
    return ""; 
}

