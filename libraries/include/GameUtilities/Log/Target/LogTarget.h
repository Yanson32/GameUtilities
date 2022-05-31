#ifndef GU_LOG_TARGET_H
#define GU_LOG_TARGET_H
/*********************************************************************************//**
*	@author	        Wayne J Larson Jr.
*	@date 	        5/30/22
*	@description    This is the base class for all Log Targets. 
*************************************************************************************/

#include "log_export.h"
#include "GameUtilities/Core/String.h"
#include <iostream>
namespace GU
{
    namespace Log
    {
  		class LOG_EXPORT LogTarget
  		{
  			public:
                /*********************************************************************************//**
                *	@brief  Constructor 
                *************************************************************************************/
  				LogTarget();
                

                /*********************************************************************************//**
                *	@brief  This method writes a string to the log target.
                *   @param  msg is the string to be written. 
                *************************************************************************************/
  				virtual void write(const GU::Core::String &msg) = 0;
                

                /*********************************************************************************//**
                *	@brief  This method retruns true if the current log target and the passed log
                *           target are equal.
                *   @param  logTarget is the log target the current log target will be checked against
                *           for equality.
                *   @return True if the current log target and passed log target are equal and false
                *           otherwise. 
                *************************************************************************************/
                bool operator == (const LogTarget &logTarget) const;
                

                /*********************************************************************************//**
                *	@brief  Destructor 
                *************************************************************************************/
  				virtual ~LogTarget();

  		};
	}
}

#endif
