#ifndef GU_POINTEMITTER_H
#define GU_POINTEMITTER_H
#include "GameUtilities/Particle System/Emitters/Emitter.h"

namespace GU
{
    namespace PS
    {
        namespace EM
        {
            class PointEmitter: public Emitter
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
