#ifndef GU_LOG_FILECOMPONENT_H
#define GU_LOGFILECOMPONENT_H
/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
* @date 4/8/2022
* @description This class is used to define a file where the log originated
*************************************************************************************/
#include "log_export.h"
#include "GameUtilities/Core/String.h"
#include "GameUtilities/Log/Component/LogComponent.h"
#include "GameUtilities/Log/Component/ComponentId.h"

namespace GU
{
    namespace Log
    {
      struct LOG_EXPORT FileComponent: public LogComponent
      {

        /*****************************************************************
        * @brief: Constructor
        *****************************************************************/
        FileComponent();


        /*****************************************************************
        * @brief: Constructor
        * @param: file is the location where the log originated from
        *****************************************************************/
        FileComponent(GU::Core::String &file);


        /*****************************************************************
        * @brief:  Assignment operator
        * @param:  comp will be used to initialize the current object.
        * @return: A reference to the current object after it has been
        *          updated.
        *****************************************************************/
        FileComponent& operator = (const FileComponent &comp);


        /*****************************************************************
        * @brief:  This method formats the current objec into a string
        *          suitable for a log message.
        * @return: A formatted string for use in a log message.
        *****************************************************************/
        GU::Core::String format();


        GU::Core::String m_file;                //The file where the log message originated from
      };
    }
}
#endif
