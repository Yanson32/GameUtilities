#ifndef MATH_RAY_H
#define MATH_RAY_H
#include "Math/Radian.h"
#include "Math/Point.h"

namespace Math
{

    class Ray final
    {
        public:
            Ray() = default;
        private:
            Radian m_Radian;
            Point m_Point;

    };

}
#endif // MATH_RAY_H
