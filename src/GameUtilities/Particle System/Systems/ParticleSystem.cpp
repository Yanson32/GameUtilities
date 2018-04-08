#include "GameUtilities/Particle System/Systems/ParticleSystem.h"

namespace GU
{
    namespace PS
    {

        ParticleSystem::ParticleSystem(const std::size_t size):
        particles(size)
        {

        }

        void ParticleSystem::SetPosition(const Math::Point &position)
        {
            m_Position = position;
        }

        Math::Point ParticleSystem::GetPosition() const
        {
            return m_Position;
        }

        void ParticleSystem::Update(const int &deltaTime)
        {

        }

        void ParticleSystem::Add(std::unique_ptr<GU::PS::EM::Emitter> emitter)
        {
            emitters.push_back(std::move(emitter));
        }
    }
}
