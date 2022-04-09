#include "GameUtilities/Core/Paths.h"
#ifdef _WIN32
#include <windows.h>
#endif

#ifdef linux
#include <cstdlib>
#endif


GU::Core::String getConfigDir(const GU::Core::String &appName)
{
    #ifdef _WIN32
    return SHGetKnownFolderPath(CSIDL_APPDATA) + "/" + appName.toStdString();
    #endif 
    
    #ifdef linux
    GU::Core::String temp;
    temp = getenv("HOME");
    temp += "/";
    temp += "/.config"; 
    temp += "/";
    temp += appName;
    return temp; 
    #endif	
    
    return ""; 
}

