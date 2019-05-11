#include "Math/Point.h"
#include "Math/Vector.h"

namespace Math
{
    Point::Point()
    {
        //ctor
    }

    Point::Point(const float x, const float y):
    m_x(x),
    m_y(y)
    {

    }

    /**************************************************************//**
    *   @brief  The addition operator for a Point and Vector. The
    *           Vector will be added to the Point and the resulting
    *           Point will be returned.
    *   @param  vec is a mathmatical vector which will be added to the
    *           current point.
    *   @return A Math::Point object which represents the original point
    *           plus the input vector.
    ******************************************************************/
    Math::Point Point::operator + (const Math::Vector &vec)
    {
        return Math::Point(this->m_x += vec.GetX(), this->m_y += vec.GetY());
    }
}
