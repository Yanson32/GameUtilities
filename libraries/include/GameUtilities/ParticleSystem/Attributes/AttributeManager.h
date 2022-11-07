#ifndef ATTRIBUTES_MANAGER_H
#define ATTRIBUTES_MANAGER_H
/**************************************************************************
*   @Author     Wayne J Larson Jr.
*   @Date       4/06/19
*   @class      This class keeps trac of the particle systems attributes
*   @file       AttributeManager.h
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
#include <memory>
#include <vector>
#include <stack>

namespace GU
{
	namespace PS
	{
		namespace AT
		{
		    struct Remove
		    {
                public:
                    Remove(const std::size_t &newIndex):
                    index(newIndex)
                    {

                    }
                    std::size_t index = -1;
		    };
			struct Message
			{
			    Message()
			    {

			    }
			    enum Type
			    {
                    REMOVE
			    }type;
				union
				{
                    Remove remove;
				};
			};

			class PARTICLESYSTEM_EXPORT AttributeManager
			{
                public:
                    /************************************************************************//**
                    *   @brief  Constructor. 
                    ****************************************************************************/
                    AttributeManager();
                   
     
                    /************************************************************************//**
                    *   @brief  This method adds a message to the stack of messages. 
                    *   @param  message is the message to be added to the stack 
                    ****************************************************************************/
                    void sendMessage(const Message &message);
                    

                    /************************************************************************//**
                    *   @brief  This method determines if a component is in the Manager 
                    *   @param  id is the unique identifier of the component. 
                    *   @return True when the manager has a component and false otherwise. 
                    ****************************************************************************/
                    bool hasComponent(const int &id) const;


                    /************************************************************************//**
                    *   @brief  This method adds an attribute to the attribute manager.
                    *   @param  comp is a pointer to the component to be added.
                    ****************************************************************************/
                    void addAttribute(std::shared_ptr<GU::PS::AT::AttributeBase> comp);
                    

                    /************************************************************************//**
                    *   @brief  This method returns a pointer to an attribute at the given index. 
                    *   @param  id is the position of the attribute to be returned. 
                    *   @return A pointer to the attribute at the given index. 
                    ****************************************************************************/
                    std::shared_ptr<GU::PS::AT::AttributeBase> getComponent(const int &id) const;
                    

                    /************************************************************************//**
                    *   @brief  This method removes an attribute at the given index. 
                    *   @param  index is the position of the attribute to be removed 
                    ****************************************************************************/
					void remove(const std::size_t &index);
                    

                    /************************************************************************//**
                    *   @brief  Deconstructor. 
                    ****************************************************************************/
					virtual ~AttributeManager();
				private:
					std::vector<std::shared_ptr<GU::PS::AT::AttributeBase>> components;
					std::stack<GU::PS::AT::Message> messages;
			};
		}
	}
}

#endif
