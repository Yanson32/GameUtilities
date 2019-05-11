#ifndef PARTICLE_SYSTEM_UPDATERS_BASE_H
#define PARTICLE_SYSTEM_UPDATERS_BASE_H
#include "particlesystem_export.h"

namespace GU
{
    namespace PS
    {
        namespace AT
        {
            class Manager;
        }

        namespace UP
        {

            class PARTICLESYSTEM_EXPORT Base
            {
                public:
                    Base();
                    virtual void update(GU::PS::AT::Manager &manager, const float &deltaTime) = 0;
                    virtual ~Base();

                protected:

                private:

            };
        }
    }
}
#endif // PARTICLE_SYSTEM_UPDATERS_BASE_H
