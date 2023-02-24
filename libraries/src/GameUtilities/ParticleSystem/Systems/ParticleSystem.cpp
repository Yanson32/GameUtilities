/**************************************************************************
*   @Author     Wayne J Larson Jr.
*   @Date       04/06/19
*   @class      This class is the base class for all particle systems. 
*   @file       ParticleSystem.cpp
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
        void ParticleSystem::setPosition(const Math::Vector2<float> &position)
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
        Math::Vector2<float> ParticleSystem::getPosition() const
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
