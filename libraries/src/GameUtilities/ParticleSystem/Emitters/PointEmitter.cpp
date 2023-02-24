/**************************************************************************
*   @Author     Wayne J Larson Jr.
*   @Date       4/06/19
*   @class      This emitter class emits particles at a single point. 
*   @file       PointEmitter.cpp
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
#include "GameUtilities/ParticleSystem/Emitters/PointEmitter.h"
#include "GameUtilities/ParticleSystem/Systems/ParticleSystem.h"

namespace GU
{
    namespace PS
    {
        namespace EM
        {
            
            /************************************************************************//**
            *   @brief  Constructor. 
            *   @param  parent is a pointer to the parent particle system. 
            *   @param  ppf (particles per frame) is the number of particles in the system.
            *   @param  relativePosition is the relative position of the emitter. 
            ****************************************************************************/
            PointEmitter::PointEmitter(GU::PS::ParticleSystem *parent, 
            const std::size_t ppf, 
            Math::Vector2<float> relativePosition):
            Emitter(parent, ppf, relativePosition)
            {
                //ctor
            }

            
            /************************************************************************//**
            *   @brief  This method creates particles  
            ****************************************************************************/
            void PointEmitter::emit()
            {
                assert(m_Parent);
                Math::Vector2<float> position = m_Parent->getPosition() + m_RelativePosition;
                for(std::size_t i = 0; i < m_Ppf; ++i)
                {
                    //m_Parent->particles.position.emplace_back<Math::Point>(position.m_x, position.m_y);
                }
            }
        }
    }
}
