#ifndef GAMEUTILITIES_PATH_H
#define	GAMEUTILITIES_PATH_H

#include "core_export.h"
#include "GameUtilities/Core/String.h"


/**************************************************************************
* @brief:    This function returns a os specific path to the appropriate 1
*            directory for a config file.
* @param     appName is the name of the application. The name will be 
*            added to the end of the path. The final path may not exist 
*            and so it may need to be created by the caller.
**************************************************************************/
GU::Core::String CORE_EXPORT getConfigDir(const GU::Core::String &appName);

#endif
