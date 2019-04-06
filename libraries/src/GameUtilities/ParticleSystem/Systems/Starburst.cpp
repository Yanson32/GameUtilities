#include "GameUtilities/ParticleSystem/Systems/Starburst.h"
//#include "GameUtilities/ParticleSystem/Emitters/PointEmitter.h"
#include "GameUtilities/ParticleSystem/Attributes/Position.h"
#include "GameUtilities/ParticleSystem/Attributes/Velocity.h"
#include "GameUtilities/ParticleSystem/Attributes/LifeSpan.h"
#include "GameUtilities/ParticleSystem/Attributes/Manager.h"

#include "GameUtilities/ParticleSystem/Updaters/Position.h"
#include "Math/Degree.h"
#include <cmath>
#include <iostream>
#include <cassert>
namespace GU
{
    namespace PS
    {
        namespace SY
        {
            /**********************************************************//**
            *   @brief  Constructor.
            *   @param  position the base position of the particle system
            *   @param  size the number of particles in the system.
            ****************************************************************/
            Starburst::Starburst(const Math::Point &newPosition, const std::size_t newSize):
			size(newSize),
			position(newPosition)

            {
                //setPosition(position);
                setMagnitude(1);
				init();


            }


            /************************************************************//**
            *   @brief  The per fram logic of the particle system
            *   @param  deltaTime is the time the previous frame took.
            ****************************************************************/
            void Starburst::update(const float &deltaTime)
            {
                GU::PS::UP::Manager::update(*this, deltaTime);
            }

			void Starburst::init()
			{
				std::shared_ptr<GU::PS::AT::Position> pos(new GU::PS::AT::Position(*this, size));
				assert(pos != nullptr);
				this->addAttribute(std::static_pointer_cast<GU::PS::AT::Base>(pos));

				for(size_t i = 0; i < size; ++i)
					pos->data.emplace_back<std::pair<float, float>>(std::pair<float, float>(position.m_x, position.m_y));

                std::cout << "position added" << std::endl;

				std::shared_ptr<GU::PS::AT::Velocity> vel(new GU::PS::AT::Velocity(*this, size));
				assert(vel != nullptr);
				this->addAttribute(std::static_pointer_cast<GU::PS::AT::Base>(vel));
                float degree = 360 / size;
				for(size_t i = 0; i < size; ++i)
				{
					float angle = degree * i;

					vel->data.emplace_back<std::pair<float, float>>(std::pair<float, float>(std::sin(angle), std::cos(angle)));
				}

//				std::shared_ptr<GU::PS::CP::LifeSpan> life(new GU::PS::CP::LifeSpan(*this, size));
//				assert(life != nullptr);
//				this->add(std::static_pointer_cast<GU::PS::CP::Base>(life));
//				for(size_t i = 0; i  < size; ++i)
//					life->data.emplace_back(1);

                //Add updaters to class
                std::shared_ptr<GU::PS::UP::Base> up(new GU::PS::UP::Position());
                this->addUpdater(up);
			}
            /************************************************************//**
            *   @brief  Update the magnitude of the velocity vectors.
            *   @param  magnitude the new magnitude of the vectors.
            ****************************************************************/
            void Starburst::setMagnitude(const unsigned magnitude)
            {
/*                 for(int i = 0; i < particles.velocity.size(); ++i)
                {
                    particles.velocity[i].magnitude = magnitude;
                } */
            }
        }
    }
}
