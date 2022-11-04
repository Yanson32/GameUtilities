#include "GameUtilities/ParticleSystem/Updaters/UpdateManager.h"
#include "GameUtilities/ParticleSystem/Attributes/Manager.h"
#include <cassert>
namespace GU
{
    namespace PS
    {
        namespace UP
        {
            UpdateManager::UpdateManager()
            {
                //ctor
            }

            void UpdateManager::addUpdater(std::shared_ptr<GU::PS::UP::UpdaterBase> comp)
            {
                assert(comp != nullptr);
                data.push_back(comp);
            }

            void UpdateManager::update(GU::PS::AT::Manager &manager, const float &deltaTime)
            {
                for(std::size_t i = 0; i < data.size(); ++i)
                {
                    data[i]->update(manager, deltaTime);
                }
            }


            UpdateManager::~UpdateManager()
            {
                //dtor
            }
        }
    }
}
