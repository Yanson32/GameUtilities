#ifndef GU_PARTICLE_H_INCLUDED
#define GU_PARTICLE_H_INCLUDED
#include "GameUtilities/Particle System/Container.h"
#include "GameUtilities/Particle System/Attribute/Attribute.h"
#include <vector>

namespace GU
{
    namespace PS
    {
        namespace SY
        {
            struct Particle
            {
                std::vector<GU::PS::AT::Attribute<>> attributes;
            };
        }
    }
}

#endif // PARTICLE_H_INCLUDED
