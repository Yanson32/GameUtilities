#include "GameUtilities/Log/Component/DateComponent.h"
#include "GameUtilities/Core/Macros.h"
namespace GU
{
    namespace Log
    {

        /*********************************************************************************//**
        *	@brief  Constructor 
        *************************************************************************************/
        DateComponent::DateComponent():
        LogComponent(componentId::DATE)
        {


        }


        /*********************************************************************************//**
        *	@brief  This method will copy the data members of the given component into the 
        *           current component.
        *   @param  comp is the log component to be copied. 
        *   @return A reference to the current date object.
        *************************************************************************************/
        DateComponent& DateComponent::operator = (const DateComponent &comp) 
        {
          UNUSED(comp);
          return *this;
        }


        /*********************************************************************************//**
        *	@brief  This method converts the data stored in the current component into a string. 
        *   @return A string equal to the current data in the log component. 
        *************************************************************************************/
        GU::Core::String DateComponent::format()
        {
          //GU::Core::String temp;
          //auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
          //temp = ctime(&timenow);
          return "Date";
        }

    }
}
