#include "GameUtilities/Particle System/Systems/Starburst.h"
#include "GameUtilities/Particle System/Emitters/PointEmitter.h"
#include "Math/Degree.h"
namespace GU
{
    namespace PS
    {
        namespace SY
        {
            Starburst::Starburst(const Math::Point &position, const std::size_t size):
            GU::PS::ParticleSystem(size)
            {
                for(int i = 0; i < particles.position.Size(); ++i)
                {
                    particles.position[i] = position;
                }

            }

            void Starburst::Update(const int &deltaTime)
            {

            }

            void Starburst::SetMagnitude(const unsigned magnitude)
            {
                for(int i = 0; i < particles.velocity.Size(); ++i)
                {
                    particles.velocity[i].magnitude = magnitude;
                }
            }
        }
    }
}
