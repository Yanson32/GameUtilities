#ifndef MATH_POINT_H
#define MATH_POINT_H

namespace Math
{
    class Vector;
    struct Point final
    {
        Point();
        Point(const float x, const float y);


        /**************************************************************//**
        *   @brief  The addition operator for a Point and Vector. The
        *           Vector will be added to the Point and the resulting
        *           Point will be returned.
        *   @param  vec is a mathmatical vector which will be added to the
        *           current point.
        *   @return A Math::Point object which represents the original point
        *           plus the input vector.
        ******************************************************************/
        Math::Point operator + (const Math::Vector &vec);
        float m_x = 0;
        float m_y = 0;
    };
}
#endif // MATH_POINT_H
