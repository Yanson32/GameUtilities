#include "Math/Line.h"
#include <cmath>

namespace Math
{

    Line::Line(const Point &start, const Point &end):
    m_Start(start),
    m_End(end)
    {

    }

    Line Line::Reverse() const
    {
        return Line(m_End, m_Start);
    }

    Line Line::LeftNormal() const
    {
        float dx = m_End.m_x - m_Start.m_x;
        float dy = m_End.m_y - m_Start.m_y;
        return Line(m_Start, {-dy, dx});
    }

    Line Line::RightNormal() const
    {
        float dx = m_End.m_x - m_Start.m_x;
        float dy = m_End.m_y - m_Start.m_y;
        return Line(m_Start, {dy, -dx});
    }

    unsigned Line::Magnitude() const
    {
        auto a = std::abs(m_End.m_x - m_Start.m_x);
        auto b = std::abs(m_End.m_y - m_Start.m_y);
        return std::sqrt(a * a + b * b);
    }
}
