#ifndef GU_LOG_TIMECOMPONENT_H
#define GU_LOG_TIMECOMPONENT_H
/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
* @date 5/24/2022
* @description  This class represents the time component for the log system 
*************************************************************************************/

#include "log_export.h"
#include "GameUtilities/Core/String.h"
#include "GameUtilities/Log/Component/LogComponent.h"
#include "GameUtilities/Log/Component/ComponentId.h"
#include <chrono>
#include <ctime>

namespace GU
{
    namespace Log
    {
        struct LOG_EXPORT TimeComponent: public LogComponent
        {
            
            public:
                /*********************************************************************************//**
                *	@brief  Constructor
                *************************************************************************************/
                TimeComponent();
                

                /*********************************************************************************//**
                *	@brief  Constructor
                *   @param  hours is the hour component of the current time
                *   @param  minutes is the minutes component of the current time.
                *   @param  seconds is the seconds component of the current time
                *************************************************************************************/
                TimeComponent(const int &hours, const int &minutes, const int &seconds);
                

                /*********************************************************************************//**
                *	@brief  This method copies the given object into the current object with deep copy.
                *   @param  comp is the object to be copied. 
                *   @return Is a reference to the current updated object
                *************************************************************************************/
                TimeComponent& operator = (const TimeComponent &comp);
                

                /*********************************************************************************//**
                *	@brief  This method returns a string which is formatted correctoy for a log file. 
                *           The string will represent the time the log was created.
                *   @return A string representing the time the log was created. 
                *************************************************************************************/
                GU::Core::String format();
            public:
                int m_hours;
                int m_minutes;
                int m_seconds;
      };
    }
}

#endif
