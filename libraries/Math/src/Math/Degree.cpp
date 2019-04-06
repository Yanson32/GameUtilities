#include "Math/Constants.h"
#include "Math/Degree.h"
#include "Math/Radian.h"

namespace Math
{
    Degree::Degree(const float degree):
    m_Degrees(degree)
    {

    }

    Degree::Degree(const Radian &radian):
    m_Degrees(radian * 180 / pie)
    {

    }
}
