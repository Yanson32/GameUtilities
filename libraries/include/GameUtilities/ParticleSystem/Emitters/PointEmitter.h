#ifndef GU_POINTEMITTER_H
#define GU_POINTEMITTER_H
#include "particlesystem_export.h"
#include "GameUtilities/ParticleSystem/Emitters/Emitter.h"

namespace GU
{
    namespace PS
    {
        namespace EM
        {
            class PARTICLESYSTEM_EXPORT PointEmitter: public Emitter
            {
                public:
                    PointEmitter(GU::PS::ParticleSystem *parent, const std::size_t ppf, Math::Vector relativePosition = Math::Vector());
                    virtual void Emit();
                protected:
                private:
            };
        }
    }
}

#endif // GU_POINTEMITTER_H
