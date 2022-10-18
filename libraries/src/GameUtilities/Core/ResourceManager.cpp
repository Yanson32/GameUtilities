#include "GameUtilities/Core/ResourceManager.h"
/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
*   @date 09/16/2022
*   @description    This class is responsible for loading game resources and making sure each resource is only loaded once.
*************************************************************************************/

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

#include <map>
#include <memory>
#include <cassert>
#include "GameUtilities/Core/Resource.h"
#include "GameUtilities/Core/String.h"
namespace GU
{

    namespace Core
    {

        class ResourceManager::Impl
        {
            public:
                std::map<int, std::shared_ptr<GU::Core::Resource>> m_map; 
        };


        ResourceManager::ResourceManager():
        m_pimpl(new ResourceManager::Impl())
        {
            assert(m_pimpl != nullptr);

        }

        
        /*********************************************************************************//**
        *	@brief  Add a previously loaded resource to the resource manager class. 
        *   @param  key is a unique identifier for the resource. 
        *   @param  value is a pointer to the resource. 
        *************************************************************************************/
        bool ResourceManager::add(const int &key, std::shared_ptr<GU::Core::Resource> value)
        {
            assert(m_pimpl != nullptr);
            assert(value != nullptr);
            assert(!this->isLoaded(key));
            if(this->isLoaded(key))
                return false;
            m_pimpl->m_map.insert(std::pair<int, std::shared_ptr<GU::Core::Resource>>(key, value)); 
            return true;
        }


        /*********************************************************************************//**
        *	@brief  This method returns true if the resource is currently loaded in the 
        *           resource manager. 
        *   @param  key is a unique identifier for the resource.
        *   @return True is returned if the resource is currently loaded in the resource manager.
        *************************************************************************************/
        bool ResourceManager::isLoaded(const int &key) const
        {
            assert(m_pimpl != nullptr);
            return m_pimpl->m_map.find(key) != m_pimpl->m_map.end();
        }

 
        /*********************************************************************************//**
        *	@brief  This method removes a resource from the resource manager.
        *   @param  key is a unique identifier for the resource. 
        *   @return True if the resource was removed and false otherwise.
        *************************************************************************************/
        bool ResourceManager::remove(const int &key)
        {
            assert(m_pimpl != nullptr);
            if(!this->isLoaded(key))
                return false;
            m_pimpl->m_map.erase(key); 
            return true;
        }
        

        /*********************************************************************************//**
        *	@brief  Destructor 
        *************************************************************************************/
        ResourceManager::~ResourceManager()
        {
            assert(m_pimpl != nullptr);
            if(m_pimpl != nullptr)
            {
                delete m_pimpl;
                m_pimpl = nullptr;
            }
        }
    }
}
