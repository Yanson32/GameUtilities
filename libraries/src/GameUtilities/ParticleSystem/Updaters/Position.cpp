#include "GameUtilities/ParticleSystem/Updaters/Position.h"
#include "GameUtilities/ParticleSystem/Attributes/Id.h"
#include "GameUtilities/ParticleSystem/Attributes/Manager.h"
#include "GameUtilities/ParticleSystem/Attributes/Velocity.h"
#include "GameUtilities/ParticleSystem/Attributes/Position.h"
#include <iostream>
namespace GU
{
    namespace PS
    {
        namespace UP
        {
            Position::Position()
            {
                //ctor
            }

            void Position::update(GU::PS::AT::Manager &manager, const float &deltaTime)
            {
                std::shared_ptr<GU::PS::AT::Velocity> vel = std::static_pointer_cast<GU::PS::AT::Velocity>(manager.getComponent(GU::PS::AT::Id::VELOCITY));
                std::shared_ptr<GU::PS::AT::Position> pos = std::static_pointer_cast<GU::PS::AT::Position>(manager.getComponent(GU::PS::AT::Id::POSITION));

                assert(vel != nullptr);
                assert(pos != nullptr);
                assert(pos->data.size() == vel->data.size());

                for(std::size_t i = 0; i < pos->data.size(); ++i)
                {
                    pos->data[i].first = pos->data[i].first + (vel->data[i].first * deltaTime);
                    pos->data[i].second = pos->data[i].second + (vel->data[i].second * deltaTime);
                }

            }

            Position::~Position()
            {
                //dtor
            }
        }
    }
}
