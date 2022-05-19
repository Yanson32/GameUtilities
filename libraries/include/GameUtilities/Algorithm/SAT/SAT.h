#ifndef SAT_H
#define SAT_H

#include <utility>
#include <Math/Vector2.h>

namespace GU
{
    namespace Al
    {
        class SatObject;

        std::pair<float, float> project(const GU::Al::SatObject &first, Math::Vector2<float> normal);        
    }
}

#endif
