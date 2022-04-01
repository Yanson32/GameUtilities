#include "GameUtilities/Log/Component/DateComponent.h"
namespace GU
{
    namespace Log
    {

        DateComponent::DateComponent():
        LogComponent(componentId::DATE)
        {


        }


        DateComponent& DateComponent::operator = (const DateComponent &comp)
        {
          return *this;
        }


        GU::Core::String DateComponent::format()
        {
          //GU::Core::String temp;
          //auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
          //temp = ctime(&timenow);
          return "Date";
        }

    }
}
