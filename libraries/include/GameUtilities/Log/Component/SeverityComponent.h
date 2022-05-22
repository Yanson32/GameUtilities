#ifndef GU_LOG_SECURITYCOMPONENT_H
#define GU_LOG_SECURITYCOMPONENT_H
/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
* @date 4/8/2022
* @description This class defines the severity of a log message.
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
        struct LOG_EXPORT SeverityComponent: public LogComponent
        {
            /*****************************************************************
            * @brief: The constructor
            *****************************************************************/
            SeverityComponent();


            /*****************************************************************
            * @brief: The constructor
            * @param: severity indicates how important the log is.
            *****************************************************************/
            SeverityComponent(const LogType &severity);


            /*****************************************************************
            * @brief:  Assignment operator overload.
            * @param:  comp contains the values to be assigned to the current
            *          object.
            * @return: A reference to the updated current object.
            *****************************************************************/
            SeverityComponent& operator = (const SeverityComponent &comp);


            /*****************************************************************
            * @brief:  This method creates a string from the current severity.
            * @return: A string representing the current severity object.
            *****************************************************************/
            GU::Core::String format();

            LogType m_severity = LogType::GU_MESSAGE;           //The logs severity
        };
    }
}
#endif
