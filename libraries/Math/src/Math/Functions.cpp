#include "Math/Functions.h"
#include "Math/Constants.h"
#include "Math/Radian.h"
#include "Math/Degree.h"
#include <cmath>
namespace Math
{
    /*********************************************************//**
    *   @brief  Get the cosign of a Math::Radian object.
    *   @param  rad a Math::Radian object which will be used to
    *           calculate the cosign.
    *   @return a float representing the cosign of the input
    *           Math::Radian object.
    *************************************************************/
    float cos(const Radian &rad)
    {
        return std::cos(rad.m_Radians);
    }


    /***********************************************************//**
    *   @brief  Get the cosign of the Math::Degree object.
    *   @param  deg a Math::Degree object which will be used to
    *           calculate the cosign.
    *   @return a float representing the cosign of the input
    *           Math::Degree object.
    ***************************************************************/
    float cos(const Degree &deg)
    {
        return std::cos(deg.m_Degrees);
    }


    /***********************************************************//**
    *   @brief  Get the sin of the Math::Radian object.
    *   @param  deg a Math::Radian object which will be used to
    *           calculate the sign.
    *   @return a float representing the sin of the input
    *           Math::Radian object.
    ***************************************************************/
    float sin(const Radian &rad)
    {
        return std::sin(rad.m_Radians);
    }


    /***********************************************************//**
    *   @brief  Get the sin of the Math::Degree object.
    *   @param  deg a Math::Degree object which will be used to
    *           calculate the sign.
    *   @return a float representing the sin of the input
    *           Math::Degree object.
    ***************************************************************/
    float sin(const Degree &deg)
    {
        return std::sin(deg.m_Degrees);
    }
}
