
#include "GameUtilities/Log/Component/TimeComponent.h"

namespace GU
{
    namespace Log
    {

        TimeComponent::TimeComponent():
        LogComponent(componentId::TIME)
        {

        }


        TimeComponent& TimeComponent::operator = (const TimeComponent &comp)
        {
          return *this;
        }


        GU::Core::String TimeComponent::format()
        {
          GU::Core::String temp;
          auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
          temp = ctime(&timenow);
          return temp;
        }
    }
}
