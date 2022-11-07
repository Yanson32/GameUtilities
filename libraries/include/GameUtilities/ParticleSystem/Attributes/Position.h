#ifndef ATTRIBUTES_POSITION_H
#define ATTRIBUTES_POSITION_H
/**************************************************************************
*   @Author     Wayne J Larson Jr.
*   @Date       04/06/19
*   @class      This class creates a position attribute.   
*   @file       Position.h
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
#include "GameUtilities/ParticleSystem/Attributes/AttributeBase.h"
#include "GameUtilities/ParticleSystem/Container.h"
namespace GU
{
	namespace PS
	{
		namespace AT
		{
			class PARTICLESYSTEM_EXPORT Position: public GU::PS::AT::AttributeBase
			{
				public:
                    /************************************************************************//**
                    *   @brief  Constructor 
                    *   @param  manager is a reference to the attribute manager. 
                    *   @param  size is the number of attributes to be created. 
                    ****************************************************************************/
					Position(GU::PS::AT::AttributeManager &manager, const std::size_t &size);
                    

                    /************************************************************************//**
                    *   @brief  This method removes an attribute from the container at the given 
                    *           index. 
                    *   @param  index is the position in the container of the attribute to be 
                    *           removed. 
                    ****************************************************************************/
					void remove(const std::size_t &index) override;
                public:
					GU::PS::Container<std::pair<float, float>> m_data;
			};
		}
	}
}
#endif
