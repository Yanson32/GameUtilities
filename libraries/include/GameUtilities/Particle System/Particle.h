#ifndef GU_PARTICLE_H_INCLUDED
#define GU_PARTICLE_H_INCLUDED
#include "GameUtilities/Particle System/Container.h"
#include "GameUtilities/RGBA.h"
#include "Math/Point.h"
#include "Math/Vector.h"
#include <vector>

namespace GU
{
    namespace PS
    {
        namespace SY
        {
            struct Particle
            {
                Particle(const std::size_t size):
                position(size),
                velocity(size),
                lifeSpan(size),
                color(size){}
                GU::PS::Container<Math::Point>      position;
                GU::PS::Container<Math::Vector>     velocity;
                GU::PS::Container<unsigned>         lifeSpan;
                GU::PS::Container<RGBA>             color;
            };
        }
    }
}

#endif // PARTICLE_H_INCLUDED
