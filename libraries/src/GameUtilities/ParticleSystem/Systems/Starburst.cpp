#include "GameUtilities/ParticleSystem/Systems/Starburst.h"
//#include "GameUtilities/ParticleSystem/Emitters/PointEmitter.h"
#include "GameUtilities/ParticleSystem/Attributes/Position.h"
#include "GameUtilities/ParticleSystem/Attributes/Velocity.h"
#include "GameUtilities/ParticleSystem/Attributes/LifeSpan.h"
#include "GameUtilities/ParticleSystem/Attributes/Manager.h"

#include "GameUtilities/ParticleSystem/Updaters/Position.h"
//#include "GameUtilities/ParticleSystem/Updaters/LifeSpan.h"
#include "GameUtilities/Core/Macros.h"

#include "Math/Degree.h"
#include <cmath>
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
            Starburst::Starburst(const Math::Vector2<float> &position, const std::size_t size):
			m_size(size),
			m_position(position)

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
				std::shared_ptr<GU::PS::AT::Position> pos(new GU::PS::AT::Position(*this, m_size));
                assert(pos != nullptr);
              
                //Initialize position container 
                for(std::size_t i = 0; i < m_size; ++i) 
                    pos->data.emplace_back(0, 0);		
				
				this->addAttribute(std::static_pointer_cast<GU::PS::AT::Base>(pos));

				for (std::size_t i = 0; i < m_size; ++i)
				{
					pos->data[i].first = m_position.x;
					pos->data[i].second = m_position.y;
				}


				std::shared_ptr<GU::PS::AT::Velocity> vel(new GU::PS::AT::Velocity(*this, m_size));
				assert(vel != nullptr);

                //Initialize velocity container 
                for(std::size_t i = 0; i < m_size; ++i) 
                    vel->data.emplace_back(0, 0);		

				this->addAttribute(std::static_pointer_cast<GU::PS::AT::Base>(vel));
                float degree = 360 / m_size;
				for(size_t i = 0; i < m_size; ++i)
				{
					float angle = degree * i;
					vel->data[i].first = std::sin(angle);
					vel->data[i].second = std::cos(angle);
				}

				//std::shared_ptr<GU::PS::CP::LifeSpan> life(new GU::PS::UP::LifeSpan(*this, size));
				//assert(life != nullptr);
				//this->addUpdater(std::static_pointer_cast<GU::PS::UP::Base>(life));
				//for(size_t i = 0; i  < size; ++i)
				//	life->data.emplace_back(1);

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
                UNUSED(magnitude);
/*                 for(int i = 0; i < particles.velocity.size(); ++i)
                {
                    particles.velocity[i].magnitude = magnitude;
                } */
            }
        }
    }
}
