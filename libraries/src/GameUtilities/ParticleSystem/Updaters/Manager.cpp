#include "GameUtilities/ParticleSystem/Updaters/Manager.h"
#include "GameUtilities/ParticleSystem/Attributes/Manager.h"
#include <cassert>
namespace GU
{
    namespace PS
    {
        namespace UP
        {
            Manager::Manager()
            {
                //ctor
            }

            void Manager::addUpdater(std::shared_ptr<GU::PS::UP::Base> comp)
            {
                assert(comp != nullptr);
                data.push_back(comp);
            }

            void Manager::update(GU::PS::AT::Manager &manager, const float &deltaTime)
            {
                for(std::size_t i = 0; i < data.size(); ++i)
                {
                    data[i]->update(manager, deltaTime);
                }
            }
//            Manager::~Manager()
//            {
//                //dtor
//            }
        }
    }
}
