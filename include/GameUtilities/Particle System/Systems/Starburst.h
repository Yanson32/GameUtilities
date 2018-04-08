#ifndef GU_STARBURST_H
#define GU_STARBURST_H

#include "GameUtilities/Particle System/Systems/ParticleSystem.h"
#include "Math/Point.h"

namespace GU
{
    namespace PS
    {
        namespace SY
        {
            class Starburst: public ParticleSystem
            {
                public:
                    Starburst(const Math::Point &position, const std::size_t size);
                    void SetMagnitude(const unsigned magnitude);
                    virtual void Update(const int &deltaTime) override;
            };
        }
    }
}

#endif
