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
                ParticleSystem(const std::size_t size);
                virtual void Update(const int &deltaTime) = 0;
                void SetPosition(const Math::Point &position);
                template<typename Type, typename... Args>
                void Add(Args&&... args);
                void Add(std::unique_ptr<GU::PS::EM::Emitter> emitter);
                Math::Point GetPosition() const;
                GU::PS::SY::Particle particles;
                std::vector<std::unique_ptr<GU::PS::EM::Emitter>> emitters;
            private:
                Math::Point m_Position;
        };


        template<typename Type, typename... Args>
        void ParticleSystem::Add(Args&&... args)
        {
            Add(std::unique_ptr<GU::PS::EM::Emitter>(new Type(std::forward<Args>(args)...)));
        }
    }
}

#endif
