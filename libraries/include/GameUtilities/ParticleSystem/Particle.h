#ifndef GU_PARTICLE_H_INCLUDED
#define GU_PARTICLE_H_INCLUDED
#include "particlesystem_export.h"
#include "GameUtilities/ParticleSystem/Container.h"
#include "Math/Vector2.h"
#include <vector>

namespace GU
{
    namespace PS
    {
		struct PARTICLESYSTEM_EXPORT Particle
        {
            Particle(const std::size_t newSize);
			std::size_t size;
			//std::vector<Component> components;
        };

    }
}

#endif // PARTICLE_H_INCLUDED
