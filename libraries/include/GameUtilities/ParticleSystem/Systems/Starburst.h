#ifndef GU_ATTRIBUTES_STARBURST_H
#define GU_ATTRIBUTES_STARBURST_H

#include "particlesystem_export.h"
//#include "GameUtilities/ParticleSystem/Systems/ParticleSystem.h"
#include "GameUtilities/ParticleSystem/Attributes/Manager.h"
#include "GameUtilities/ParticleSystem/Updaters/UpdateManager.h"
#include "Math/Vector2.h"

namespace GU
{
    namespace PS
    {
        namespace SY
        {
            class PARTICLESYSTEM_EXPORT Starburst:
                public GU::PS::AT::Manager,
                public GU::PS::UP::UpdateManager
            {
                public:
                    /************************************************************//**
                    *   @brief  Constructor.
                    *   @param  position the base position of the particle system
                    *   @param  size the number of particles in the system.
                    ****************************************************************/
                    Starburst(const Math::Vector2<float> &position, const std::size_t size);


                    /************************************************************//**
                    *   @brief  The per fram logic of the particle system
                    *   @param  deltaTime is the time the previous frame took.
                    ****************************************************************/
                    virtual void update(const float &deltaTime);

					virtual void init();

                    /************************************************************//**
                    *   @brief  Update the magnitude of the velocity vectors.
                    *   @param  magnitude the new magnitude of the vectors.
                    ****************************************************************/
                    void setMagnitude(const unsigned magnitude);

					std::size_t m_size = 10;
                    Math::Vector2<float> m_position;
            };
        }
    }
}

#endif
