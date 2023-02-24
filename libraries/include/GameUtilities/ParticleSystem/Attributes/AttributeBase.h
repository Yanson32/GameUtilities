#ifndef COMPONENT_PARTICLE_SYSTEM_BASE_H
#define COMPONENT_PARTICLE_SYSTEM_BASE_H
/**************************************************************************
*   @Author     Wayne J Larson Jr.
*   @Date       03/27/18
*   @class      This class is the base class for all attributes. 
*   @file       AttributeBase.h
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
#include <vector>

namespace GU
{
	namespace PS
	{
		namespace AT
		{
            class AttributeManager;
			class PARTICLESYSTEM_EXPORT AttributeBase
			{
				public:
                    /************************************************************************//**
                    *   @brief  Constructor. 
                    *   @param  manager is a reference to the attrubute manager.
                    *   @param  id is the unique identifier of the attribute. 
                    ****************************************************************************/
					AttributeBase(GU::PS::AT::AttributeManager& manager, const int &id = -1);
                    

                    /************************************************************************//**
                    *   @brief  This method removes an attribute at the given index. 
                    *   @param  index is the index of the attribute to be removed 
                    ****************************************************************************/
					virtual void remove(const std::size_t &index) = 0;
                    

                    /************************************************************************//**
                    *   @brief  Destructor. 
                    ****************************************************************************/
					virtual ~AttributeBase();
				protected:

                    GU::PS::AT::AttributeManager &m_manager;    /*!< Reference to the attribute manager class for the particle system*/ 
			    public:	
                    const int m_attributeId = -1;               /*!< Unique id for the attribute */ 
			};
		}
	}
}
#endif // COMPONENT_PARTICLE_SYSTEM_H
