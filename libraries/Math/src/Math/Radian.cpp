#include "Math/Constants.h"
#include "Math/Radian.h"
#include "Math/Degree.h"

namespace Math
{
    Radian::Radian(const float radian):
    m_Radians(radian)
    {

    }

    Radian::Radian(const Degree &degree):
    m_Radians(degree * pie / 180)
    {

    }

    float Radian::GetRadians() const noexcept
    {
        return m_Radians;
    }

    void Radian::SetRadians(const float radians) noexcept
    {
        m_Radians = radians;
    }
}
