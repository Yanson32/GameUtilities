/**************************************************************************
*   @Author     Wayne J Larson Jr.
*   @Date       4/06/19
*   @class      This class keeps trac of the particle systems attributes
*   @file       AttributeManager.cpp
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
#include "GameUtilities/ParticleSystem/Attributes/AttributeManager.h"
#include "GameUtilities/ParticleSystem/Attributes/Position.h"
#include "GameUtilities/ParticleSystem/Attributes/Velocity.h"
#include "GameUtilities/ParticleSystem/Attributes/LifeSpan.h"
#include "GameUtilities/ParticleSystem/Attributes/Id.h"
#include <iostream>
#include <cassert>
namespace GU
{
	namespace PS
	{
		namespace AT
		{
            /************************************************************************//**
            *   @brief  Constructor. 
            ****************************************************************************/
			AttributeManager::AttributeManager()
			{

			}


            /************************************************************************//**
            *   @brief  This method adds a message to the stack of messages. 
            *   @param  message is the message to be added to the stack 
            ****************************************************************************/
            void AttributeManager::sendMessage(const Message &message)
            {
                m_messages.push(message);
            }

            
            /************************************************************************//**
            *   @brief  This method determines if a component is in the Manager 
            *   @param  id is the unique identifier of the component. 
            *   @return True when the manager has a component and false otherwise. 
            ****************************************************************************/
			bool AttributeManager::hasComponent(const int &id) const
			{
			    for(auto it = m_components.begin(); it != m_components.end(); it++)
                {
					//assert((*it) != nullptr);
					if((*it) != nullptr)
                    if((*it)->m_id == id)
                        return true;
                }

                return false;
			}
			

            /************************************************************************//**
            *   @brief  This method adds an attribute to the attribute manager.
            *   @param  comp is a pointer to the component to be added.
            ****************************************************************************/
			void AttributeManager::addAttribute(std::shared_ptr<GU::PS::AT::AttributeBase> comp)
			{
				assert(comp != nullptr);
                if(hasComponent(comp->m_id))
                    throw std::runtime_error("Component already exists");

			    m_components.push_back(comp);
			}
            

            /************************************************************************//**
            *   @brief  This method returns a pointer to an attribute at the given index. 
            *   @param  id is the position of the attribute to be returned. 
            *   @return A pointer to the attribute at the given index. 
            ****************************************************************************/
            std::shared_ptr<GU::PS::AT::AttributeBase> AttributeManager::getComponent(const int &id) const
            {

                for(std::size_t i = 0; i < m_components.size(); ++i)
                {
					assert(m_components[i] != nullptr);
                    if(m_components[i]->m_id == id)
                    {
                        return m_components[i];
                    }
                }
                throw std::runtime_error("Invalid component requested");
            }
            

            /************************************************************************//**
            *   @brief  This method removes an attribute at the given index. 
            *   @param  index is the position of the attribute to be removed 
            ****************************************************************************/
            void AttributeManager::remove(const std::size_t &index)
			{
				for(std::size_t i = 0; i < m_components.size(); ++i)
				{
					assert(m_components[i] != nullptr);
                    m_components[i]->remove(index);
				}
			}


            /************************************************************************//**
            *   @brief  Deconstructor. 
            ****************************************************************************/
			AttributeManager::~AttributeManager()
			{

			}
		}
	}
}
