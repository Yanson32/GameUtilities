#ifndef PARTICLE_SYSTEM_UPDATER_POSITION_H
#define PARTICLE_SYSTEM_UPDATER_POSITION_H
#include "particlesystem_export.h"
#include "GameUtilities/ParticleSystem/Updaters/Base.h"

namespace GU
{
    namespace PS
    {
        namespace UP
        {
            class PARTICLESYSTEM_EXPORT Position: public GU::PS::UP::Base
            {
                public:
                    Position();
                    virtual void update(GU::PS::AT::Manager &manager, const float &deltaTime);
                    virtual ~Position();

                protected:

                private:
            };
        }
    }
}
#endif // PARTICLE_SYSTEM_UPDATER_POSITION_H
