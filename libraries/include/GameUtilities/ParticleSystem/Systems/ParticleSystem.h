#ifndef GU_PARTICLE_SYSTEM_ATTRIBUTES_H
#define GU_PARTICLE_SYSTEM_ATTRIBUTES_H
/**************************************************************************
*   @Author     Wayne J Larson Jr.
*   @Date       04/06/19
*   @class      This class is the base class for all particle systems. 
*   @file       ParticleSystem.h
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
#include "GameUtilities/ParticleSystem/Attributes/Manager.h"
//#include "GameUtilities/ParticleSystem/Emitters/Emitter.h"
#include "Math/Point.h"
namespace GU
{
    namespace PS
    {
        class PARTICLESYSTEM_EXPORT ParticleSystem
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


                GU::PS::CP::Manager manager;
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
