#ifndef GU_STARBURST_H
#define GU_STARBURST_H

#include "GameUtilities/Particle System/Systems/ParticleSystem.h"
#include "Math/Point.h"

namespace GU
{
    namespace PS
    {
        namespace SY
        {
            class Starburst: public ParticleSystem
            {
                public:
                    /************************************************************//**
                    *   @brief  Constructor.
                    *   @param  position the base position of the particle system
                    *   @param  size the number of particles in the system.
                    ****************************************************************/
                    Starburst(const Math::Point &position, const std::size_t size);


                    /************************************************************//**
                    *   @brief  The per fram logic of the particle system
                    *   @param  deltaTime is the time the previous frame took.
                    ****************************************************************/
                    virtual void update(const int &deltaTime) override;


                    /************************************************************//**
                    *   @brief  Update the magnitude of the velocity vectors.
                    *   @param  magnitude the new magnitude of the vectors.
                    ****************************************************************/
                    void setMagnitude(const unsigned magnitude);
            };
        }
    }
}

#endif
