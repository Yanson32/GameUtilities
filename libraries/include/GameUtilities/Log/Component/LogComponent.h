#ifndef GU_LOG_COMPONENT_H
#define GU_LOG_COMPONENT_H
/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
* @date 4/8/2022
* @description This class is used as a base class for all log components.
*************************************************************************************/
#include "log_export.h"
#include "GameUtilities/Core/String.h"
#include "GameUtilities/Log/Component/ComponentId.h"
namespace GU
{
    namespace Log
    {
      struct LOG_EXPORT LogComponent
      {
        /*****************************************************************
        * @brief: Constructor
        * @param: id is a unique identifyer for the current object type
        *****************************************************************/
        LogComponent(const componentId &id);


        /*****************************************************************
        * @brief:  Equality operator
        * @param:  comp will be used to check for equality against the
        *          current LogComponent object.
        * @return: True of the objects are equal and false otherwise
        *****************************************************************/
        bool operator == (const LogComponent &comp);


        /*****************************************************************
        * @brief:  Equality operator
        * @param:  comp will be used to check for equality against the
        *          current componentId object.
        * @return: True of the objects are equal and false otherwise
        *****************************************************************/
        bool operator == (const componentId &comp);


        /*****************************************************************
        * @brief:  This method formats the data in the current object
        *          and turns it into a string.
        * @return: The formatted string.
        *****************************************************************/
        virtual GU::Core::String format() = 0;

        const componentId m_id;            /// A unique identifyer for the component type
      };
    }
}
#endif
