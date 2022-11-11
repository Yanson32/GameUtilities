#ifndef GU_ATTRIBUTES_STARBURST_H
#define GU_ATTRIBUTES_STARBURST_H
/**************************************************************************
*   @Author     Wayne J Larson Jr.
*   @Date       04/06/19
*   @file       StarBurst.h
*   @class      AttributeManager 
*   @brief      This class creates a particle system in which all the
*               particles start at a point and radiate out from the middle. 
**************************************************************************/

/*************************************************************************
*                           COPYRIGHT NOTICE
* GameUtilities is a toolkit for making 2d video games.
* Copyright (C) 2018 Wayne J Larson Jr. 
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 3 as 
* published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
***************************************************************************/

#include "particlesystem_export.h"
//#include "GameUtilities/ParticleSystem/Systems/ParticleSystem.h"
#include "GameUtilities/ParticleSystem/Attributes/AttributeManager.h"
#include "GameUtilities/ParticleSystem/Updaters/UpdateManager.h"
#include "Math/Vector2.h"

namespace GU
{
    namespace PS
    {
        namespace SY
        {
            class PARTICLESYSTEM_EXPORT Starburst:
                public GU::PS::AT::AttributeManager,
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


                    /************************************************************//**
                    *   @brief  Initialize the particle system. 
                    ****************************************************************/
					virtual void init();


                    /************************************************************//**
                    *   @brief  Update the magnitude of the velocity vectors.
                    *   @param  magnitude the new magnitude of the vectors.
                    ****************************************************************/
                    void setMagnitude(const unsigned magnitude);
                public:
					std::size_t m_size = 10;            /*!< The number of particles in the system */
                    Math::Vector2<float> m_position;    /*!< The position of the particle system */
            };
        }
    }
}

#endif
