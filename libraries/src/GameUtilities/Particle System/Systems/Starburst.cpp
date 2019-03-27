#include "GameUtilities/Particle System/Systems/Starburst.h"
#include "GameUtilities/Particle System/Emitters/PointEmitter.h"
#include "Math/Degree.h"
namespace GU
{
    namespace PS
    {
        namespace SY
        {
            /************************************************************//**
            *   @brief  Constructor.
            *   @param  position the base position of the particle system
            *   @param  size the number of particles in the system.
            ****************************************************************/
            Starburst::Starburst(const Math::Point &position, const std::size_t size):
            GU::PS::ParticleSystem(size)
            {
                setPosition(position);
                setMagnitude(1);
            }


            /************************************************************//**
            *   @brief  The per fram logic of the particle system
            *   @param  deltaTime is the time the previous frame took.
            ****************************************************************/
            void Starburst::update(const int &deltaTime)
            {
                for(int i = 0; i < particles.position.size(); ++i)
                {
                    particles.position[i] = particles.position[i] + particles.velocity[i];
                }

                for(auto element : particles.position)
                    element = element;
            }


            /************************************************************//**
            *   @brief  Update the magnitude of the velocity vectors.
            *   @param  magnitude the new magnitude of the vectors.
            ****************************************************************/
            void Starburst::setMagnitude(const unsigned magnitude)
            {
                for(int i = 0; i < particles.velocity.size(); ++i)
                {
                    particles.velocity[i].magnitude = magnitude;
                }
            }
        }
    }
}
