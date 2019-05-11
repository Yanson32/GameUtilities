#include "GameUtilities/ParticleSystem/Systems/ParticleSystem.h"
#include "GameUtilities/ParticleSystem/Emitters/PointEmitter.h"
namespace GU
{
    namespace PS
    {
        /************************************************************//**
        *   @brief  Constructor.
        *   @param  size the number of particles in the system
        ****************************************************************/
        ParticleSystem::ParticleSystem(const std::size_t size)
        {
            this->add<GU::PS::EM::PointEmitter>(this, size);
        }


        /************************************************************//**
        *   @brief  Chanes the position of the particle system.
        *   @param  position the new position of the particle system.
        ****************************************************************/
        void ParticleSystem::setPosition(const Math::Point &position)
        {
/*             m_Position = position;
            for(std::size_t i = 0; i < particles.position.size(); ++i)
            {
                particles.position[i] = m_Position;
            } */
        }


        /************************************************************//**
        *   @brief  This method returns the current position of the
        *           particle system.
        *   @return The current position of the particle system
        ****************************************************************/
        Math::Point ParticleSystem::getPosition() const
        {
            return m_Position;
        }


        /************************************************************//**
        *   @brief  Per frame logic
        *   @param  deltaTime the time the previous frame took.
        ****************************************************************/
        void ParticleSystem::update(const int &deltaTime)
        {

        }


        /************************************************************//**
        *   @brief  This method adds an emitter to the particle system.
        *   @param  emitter a pointer to an GU::PS::EM::Emitter object
        ****************************************************************/
        void ParticleSystem::add(std::unique_ptr<GU::PS::EM::Emitter> emitter)
        {
            m_Emitters.push_back(std::move(emitter));
        }
    }
}
