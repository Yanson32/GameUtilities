#ifndef GU_PARTICLE_H_INCLUDED
#define GU_PARTICLE_H_INCLUDED
#include "GameUtilities/Particle System/Container.h"
#include "GameUtilities/Particle System/Attribute/Attribute.h"


namespace GU
{
    namespace PS
    {
        struct Particle
        {
            std::vector<Attribute> attributes;
        }
    }
}

#endif // PARTICLE_H_INCLUDED
