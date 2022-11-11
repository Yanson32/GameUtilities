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
#include "GameUtilities/ParticleSystem/Systems/Starburst.h"
#include "GameUtilities/ParticleSystem/Emitters/PointEmitter.h"
#include "GameUtilities/ParticleSystem/Attributes/Position.h"
#include "GameUtilities/ParticleSystem/Attributes/Velocity.h"
#include "GameUtilities/ParticleSystem/Attributes/LifeSpan.h"
#include "GameUtilities/ParticleSystem/Attributes/AttributeManager.h"

#include "GameUtilities/ParticleSystem/Updaters/Position.h"
//#include "GameUtilities/ParticleSystem/Updaters/LifeSpan.h"
#include "GameUtilities/Core/Macros.h"

#include "Math/Degree.h"
#include <cmath>
#include <cassert>
namespace GU
{
    namespace PS
    {
        namespace SY
        {
            
            /**********************************************************//**
            *   @brief  Constructor.
            *   @param  position the base position of the particle system
            *   @param  size the number of particles in the system.
            ****************************************************************/
            Starburst::Starburst(const Math::Vector2<float> &position, const std::size_t size):
			m_size(size),
			m_position(position)

            {
                //setPosition(position);
                setMagnitude(1);
				init();


            }


            /************************************************************//**
            *   @brief  The per fram logic of the particle system
            *   @param  deltaTime is the time the previous frame took.
            ****************************************************************/
            void Starburst::update(const float &deltaTime)
            {
                GU::PS::UP::UpdateManager::update(*this, deltaTime);
            }

            
            /************************************************************//**
            *   @brief  Initialize the particle system. 
            ****************************************************************/
			void Starburst::init()
			{
				std::shared_ptr<GU::PS::AT::Position> pos(new GU::PS::AT::Position(*this, m_size));
                assert(pos != nullptr);
              
				for (std::size_t i = 0; i < m_size; ++i)
				{
                    pos->m_data.emplace_back(0, 0);		
					pos->m_data[i].first = m_position.x;
					pos->m_data[i].second = m_position.y;
				}
				
                this->addAttribute(std::static_pointer_cast<GU::PS::AT::AttributeBase>(pos));


				std::shared_ptr<GU::PS::AT::Velocity> vel(new GU::PS::AT::Velocity(*this, m_size));
				assert(vel != nullptr);

                float degree = 360 / m_size;
				for(size_t i = 0; i < m_size; ++i)
				{
                    vel->m_data.emplace_back(0, 0);		
					float angle = degree * i;
					vel->m_data[i].first = std::sin(angle);
					vel->m_data[i].second = std::cos(angle);
				}

				this->addAttribute(std::static_pointer_cast<GU::PS::AT::AttributeBase>(vel));

				std::shared_ptr<GU::PS::AT::LifeSpan> life(new GU::PS::AT::LifeSpan(*this, m_size));
				assert(life != nullptr);
			
                //Initialize life container	
                for(size_t i = 0; i  < m_size; ++i)
					life->m_data.emplace_back(1);

				this->addAttribute(std::static_pointer_cast<GU::PS::AT::AttributeBase>(life));

                //Add updaters to class
                std::shared_ptr<GU::PS::UP::UpdaterBase> up(new GU::PS::UP::Position());
                this->addUpdater(up);
			}


            /************************************************************//**
            *   @brief  Update the magnitude of the velocity vectors.
            *   @param  magnitude the new magnitude of the vectors.
            ****************************************************************/
            void Starburst::setMagnitude(const unsigned magnitude)
            {
                UNUSED(magnitude);
/*                 for(int i = 0; i < particles.velocity.size(); ++i)
                {
                    particles.velocity[i].magnitude = magnitude;
                } */
            }
        }
    }
}
