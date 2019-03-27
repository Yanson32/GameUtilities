#ifndef GU_PARTICLE_SYSTEM_H
#define GU_PARTICLE_SYSTEM_H
#include "GameUtilities/Particle System/Particle.h"
#include "GameUtilities/Particle System/Emitters/Emitter.h"
#include "Math/Point.h"
namespace GU
{
    namespace PS
    {
        class ParticleSystem
        {
            public:
                /************************************************************//**
                *   @brief  Constructor.
                *   @param  size the number of particles in the system
                ****************************************************************/
                ParticleSystem(const std::size_t size);


                /************************************************************//**
                *   @brief  Per frame logic
                *   @param  deltaTime the time the previous frame took.
                ****************************************************************/
                virtual void update(const int &deltaTime) = 0;


                /************************************************************//**
                *   @brief  Chanes the position of the particle system.
                *   @param  position the new position of the particle system.
                ****************************************************************/
                void setPosition(const Math::Point &position);


                /************************************************************//**
                *   @brief  This method adds an emitter to the praticle system.
                *   @tparam Type the type of emitter
                *   @tparam Args the arguments used to construct an object
                *           of Type.
                *   @tparam args the arguments used to construct an object
                *           of Type.
                ****************************************************************/
                template<typename Type, typename... Args>
                void add(Args&&... args);


                /************************************************************//**
                *   @brief  This method adds an emitter to the particle system.
                *   @param  emitter a pointer to an GU::PS::EM::Emitter object
                ****************************************************************/
                void add(std::unique_ptr<GU::PS::EM::Emitter> emitter);


                /************************************************************//**
                *   @brief  This method returns the current position of the
                *           particle system.
                *   @return The current position of the particle system
                ****************************************************************/
                Math::Point getPosition() const;


                GU::PS::SY::Particle particles;
            private:
                Math::Point m_Position;
                std::vector<std::unique_ptr<GU::PS::EM::Emitter>> m_Emitters;
        };


        /************************************************************//**
        *   @brief  This method adds an emitter to the praticle system.
        *   @tparam Type the type of emitter
        *   @tparam Args the arguments used to construct an object
        *           of Type.
        *   @tparam args the arguments used to construct an object
        *           of Type.
        ****************************************************************/
        template<typename Type, typename... Args>
        void ParticleSystem::add(Args&&... args)
        {
            add(std::unique_ptr<GU::PS::EM::Emitter>(new Type(std::forward<Args>(args)...)));
        }
    }
}

#endif
