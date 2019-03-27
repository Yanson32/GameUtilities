#ifndef GU_EMITTER_H
#define GU_EMITTER_H
#include <cstddef>
#include "Math/Vector.h"
#include "GameUtilities/Particle System/Particle.h"
namespace GU
{
    namespace PS
    {
        class ParticleSystem;
        namespace EM
        {

            class Emitter
            {
                public:
                    Emitter(GU::PS::ParticleSystem *parent, const std::size_t ppf, Math::Vector relativePosition = Math::Vector());
                    virtual void Emit() = 0;
                    void SetRelativePosition(const Math::Vector &relativePosition);
                    Math::Vector GetRelativePosition()const;
                    virtual ~Emitter();
                protected:
                    const unsigned m_Ppf = 0;           //Particles per frame
                    ParticleSystem *m_Parent = nullptr;
                    Math::Vector m_RelativePosition;
            };
        }
    }
}

#endif // GU_EMITTER_H
