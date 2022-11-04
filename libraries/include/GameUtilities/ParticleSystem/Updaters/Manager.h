#ifndef PARTICLE_SYSTEM_UPDATER_MANAGER_H
#define PARTICLE_SYSTEM_UPDATER_MANAGER_H
#include "particlesystem_export.h"
#include "GameUtilities/ParticleSystem/Updaters/UpdaterBase.h"
#include <memory>
#include <vector>
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
            class PARTICLESYSTEM_EXPORT Manager
            {
                public:
                    Manager();
                    void addUpdater(std::shared_ptr<GU::PS::UP::UpdaterBase> comp);
                    void update(GU::PS::AT::Manager &manager, const float &deltaTime);
                    virtual ~Manager(){};

                protected:

                private:
                    std::vector<std::shared_ptr<GU::PS::UP::UpdaterBase>> data;
            };
        }
    }
}
#endif // PARTICLE_SYSTEM_UPDATER_MANAGER_H
