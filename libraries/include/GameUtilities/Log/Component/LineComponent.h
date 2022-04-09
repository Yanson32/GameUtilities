#ifndef GU_LOG_SECURITYCOMPONENT_H
#define GU_LOG_SECURITYCOMPONENT_H
/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
* @date 4/8/2022
* @description This class defines a LogComponent that represents the line number
*              where the log message originated from.
*************************************************************************************/

#include "log_export.h"
#include "GameUtilities/Core/String.h"
#include "GameUtilities/Log/Component/LogComponent.h"
#include "GameUtilities/Log/Component/ComponentId.h"
#include "GameUtilities/Log/LogType.h"

namespace GU
{
    namespace Log
    {
      struct LOG_EXPORT LineComponent: public LogComponent
      {
        /*****************************************************************
        * @brief: The constructor
        *****************************************************************/
        LineComponent();


        /*****************************************************************
        * @brief: The constructor
        * @param: line the line number where the log message originated from
        *****************************************************************/
        LineComponent(const int &line);


        /*****************************************************************
        * @brief:  Assignment operator overload.
        * @param:  comp contains the values to be assigned to the current
        *          object.
        * @return: A reference to the updated current object.
        *****************************************************************/
        LineComponent& operator = (const LineComponent &comp);


        /*****************************************************************
        * @brief:  This method creates a string from the current line number.
        * @return: A string representing the current line number.
        *****************************************************************/
        GU::Core::String format();

        
        int m_line = -1;
      };
    }
}
#endif
