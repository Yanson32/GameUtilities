#ifndef GAMEUTILITIES_PATH_H
#define	GAMEUTILITIES_PATH_H
/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
* @date 4/8/2022
* @description The file defines functions to get common paths in a cross platform manner. 
*************************************************************************************/
#include "core_export.h"
#include "GameUtilities/Core/String.h"

namespace GU
{
    namespace Core
    {

        /**************************************************************************
        * @brief:    This function returns a os specific path to the appropriate 1
        *            directory for a config file.
        * @param     appName is the name of the application. The name will be
        *            added to the end of the path. The final path may not exist
        *            and so it may need to be created by the caller.
        **************************************************************************/
        GU::Core::String CORE_EXPORT getConfigDir(const GU::Core::String &appName);
    }
}

#endif
