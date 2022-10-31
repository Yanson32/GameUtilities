#include "GameUtilities/Log/Component/DateComponent.h"
#include "GameUtilities/Core/Macros.h"
#include <string>
#include <sstream>

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
        *	@brief  Constructor 
        *   @param  month is the month component of the current date.
        *   @param  day is the day component of the current date.
        *   @param  year is the year component of the current date.
        *************************************************************************************/
        DateComponent::DateComponent(const unsigned &month, const unsigned &day, const unsigned &year):
        LogComponent(componentId::DATE),
        m_month(month),
        m_day(day),
        m_year(year)
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
          std::stringstream ss;
          ss << std::to_string(m_month);
          ss << " ";
          ss << std::to_string(m_day);
          ss << " ";
          ss << std::to_string(m_year);
          return ss.str(); 
        }

    }
}
