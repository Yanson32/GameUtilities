#ifndef GU_LOG_MSGCOMPONENT_H
#define GU_LOG_MSGCOMPONENT_H
/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
* @date 4/8/2022
* @description This class defines the human readable message of the log message.
*************************************************************************************/
#include "log_export.h"
#include "GameUtilities/Core/String.h"
#include "GameUtilities/Log/Component/LogComponent.h"
#include "GameUtilities/Log/Component/ComponentId.h"


namespace GU
{
    namespace Log
    {
      struct LOG_EXPORT MsgComponent: public LogComponent
      {

        /*****************************************************************
        * @brief: The constructor
        *****************************************************************/
        MsgComponent();


        /*****************************************************************
        * @brief: The constructor
        * @param: msg is the human readable message to be displayed in the
        *         log message.
        *****************************************************************/
        MsgComponent(const GU::Core::String &msg);


        /*****************************************************************
        * @brief:  Assignment operator for the MsgComponent.
        * @param:  comp this object will be used to initialize the current
        *          object.
        * @return: A reference to the updated current object.
        *****************************************************************/
        MsgComponent& operator = (const MsgComponent &comp);


        /*****************************************************************
        * @brief:  This method creates a string formatted appropriatly for
        *          a log message.
        * @return: The formatted string.
        *****************************************************************/
        GU::Core::String format();
    public:
        GU::Core::String m_msg;              ///The current log message
      };
    }
}
#endif
