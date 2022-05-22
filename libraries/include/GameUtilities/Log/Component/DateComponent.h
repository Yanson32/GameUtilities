#ifndef GU_LOG_DATECOMPONENT_H
#define GU_LOG_DATECOMPONENT_H
/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
*   @date 4/8/2022
*   @description    This class defines a log component for dates. 
*************************************************************************************/

#include "log_export.h"
#include "GameUtilities/Core/String.h"
#include "GameUtilities/Log/Component/LogComponent.h"
#include "GameUtilities/Log/Component/ComponentId.h"
#include <chrono>

namespace GU
{
    namespace Log
    {
        struct LOG_EXPORT DateComponent: public LogComponent
        {
            /*********************************************************************************//**
            *	@brief  Constructor 
            *************************************************************************************/
            DateComponent();
            

            /*********************************************************************************//**
            *	@brief  This method will copy the data members of the given component into the 
            *           current component.
            *   @param  comp is the log component to be copied. 
            *   @return A reference to the current date object.
            *************************************************************************************/
            DateComponent& operator = (const DateComponent &comp);
            

            /*********************************************************************************//**
            *	@brief  This method converts the data stored in the current component into a string. 
            *   @return A string equal to the current data in the log component. 
            *************************************************************************************/
            GU::Core::String format();
        };
    }
}
#endif
