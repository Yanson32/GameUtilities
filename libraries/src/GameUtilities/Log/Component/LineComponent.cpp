#include "GameUtilities/Log/Component/LineComponent.h"
#include "GameUtilities/Log/Component/ComponentId.h"
#include <sstream>
#include <iostream>

namespace GU
{
    namespace Log
    {

        /*****************************************************************
        * @brief: The constructor
        *****************************************************************/
        LineComponent::LineComponent():
        LogComponent(GU::Log::componentId::LINE)
        {

        }


        /*****************************************************************
        * @brief: The constructor
        * @param: line the line number where the log message originated from
        *****************************************************************/
        LineComponent::LineComponent(const int &line):
        LogComponent(GU::Log::componentId::LINE),
        m_line(line)
        {

        }


        /*****************************************************************
        * @brief:  Assignment operator overload.
        * @param:  comp contains the values to be assigned to the current
        *          object.
        * @return: A reference to the updated current object.
        *****************************************************************/
        LineComponent& LineComponent::operator = (const LineComponent &comp)
        {
            m_line = comp.m_line;
            return *this;
        }


        /*****************************************************************
        * @brief:  This method creates a string from the current line number.
        * @return: A string representing the current line number.
        *****************************************************************/
        GU::Core::String LineComponent::format()
        {
            std::stringstream ss;
            ss << m_line;
            std::cout << "m_line " << m_line << std::endl;
            return ss.str();
        }
    }
}
