#ifndef MATH_LINE_H
#define MATH_LINE_H
#include "Math/Point.h"

namespace Math
{
    class Line final
    {
        public:
            Line() = default;
            Line(const Point &start, const Point &end);
            Line Reverse() const;
            Line LeftNormal() const;
            Line RightNormal() const;
            unsigned Magnitude() const;
            Point m_Start;
            Point m_End;
    };
}
#endif // MATH_LINE_H
