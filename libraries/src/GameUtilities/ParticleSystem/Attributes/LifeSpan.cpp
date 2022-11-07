/**************************************************************************
*   @Author     Wayne J Larson Jr.
*   @Date       04/06/19
*   @class      This class represents a lifespan attribute, which will
*               cause the particle to delete itself after an amount of
*               time has elapsed. 
*   @file       LifeSpan.cpp  
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
#include "GameUtilities/ParticleSystem/Attributes/LifeSpan.h"
#include "GameUtilities/ParticleSystem/Attributes/AttributeManager.h"
#include "GameUtilities/ParticleSystem/Attributes/Id.h"

namespace GU
{
	namespace PS
	{
		namespace AT
		{
            /************************************************************************//**
            *   @brief  Constructor 
            *   @param  manager is a reference to the attribute manager. 
            *   @param  size is the number of attributes to be created. 
            ****************************************************************************/
            LifeSpan::LifeSpan(GU::PS::AT::AttributeManager &manager, const std::size_t &size):
            AttributeBase::AttributeBase(manager, GU::PS::AT::LIFESPAN),
			m_data(size)
			{

			}

            
            /************************************************************************//**
            *   @brief  This method removes an attribute from the container at the given 
            *           index. 
            *   @param  index is the position in the container of the attribute to be 
            *           removed. 
            ****************************************************************************/
			void LifeSpan::remove(const std::size_t &index)
			{
			   this->m_data.remove(index);
			}

		}
	}
}
