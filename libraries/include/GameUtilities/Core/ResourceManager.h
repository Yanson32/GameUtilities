#ifndef GAMEUTILITIES_RESOURCE_MANAGER_H
#define GAMEUTILITIES_RESOURCE_MANAGER_H
/*********************************************************************************//**
*   @author	   Wayne J Larson Jr.
*   @date 	   09/16/2022
*   @description   This class is responsible for loading game resources and making sure each resource is only loaded once.
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
#include "core_export.h"
#include <memory>
#include <cstring>
#include "GameUtilities/Core/NonCopyable.h"
#include "GameUtilities/Core/Resource.h"
#include <cassert>
namespace GU
{

    namespace Core
    {
        class String;
        class CORE_EXPORT ResourceManager: public NonCopyable
        {
            public:
                /*********************************************************************************//**
                *	@brief  Constructor
                *************************************************************************************/
                ResourceManager();
                

                /*********************************************************************************//**
                *	@brief  Load resource from memory.
                *   @param  key is a unique identifier for the resource.
                *   @param  data is a pointer to the resources data.
                *   @param  size is the total size of the data. 
                *   @param  True is returned if the resource is loaded sucessfully and false otherwise.
                *************************************************************************************/
                template <class Resource>
                bool load(const int &key, const std::shared_ptr<void> data, const std::size_t &size);
                

                /*********************************************************************************//**
                *	@brief  Load resource disk. 
                *   @param  key is a unique identifier for the resource.
                *   @param  file is the pathe to the resource on disk. 
                *   @param  True is returned if the resource is loaded sucessfully and false otherwise.
                *************************************************************************************/
                template <class Resource>
                bool load(const int &key, const GU::Core::String &file);
                

                /*********************************************************************************//**
                *	@brief  Add a previously loaded resource to the resource manager class. 
                *   @param  key is a unique identifier for the resource. 
                *   @param  value is a pointer to the resource. 
                *   @param  True is returned if the resource is added sucessfully and false otherwise.
                *************************************************************************************/
                bool add(const int &key, std::shared_ptr<GU::Core::Resource> value);
               
 
                /*********************************************************************************//**
                *	@brief  This method returns true if the resource is currently loaded in the 
                *           resource manager. 
                *   @param  key is a unique identifier for the resource.
                *   @return True is returned if the resource is currently loaded in the resource manager.
                *************************************************************************************/
                bool isLoaded(const int &key) const;
                
                
                /*********************************************************************************//**
                *	@brief  Thi method removes a resource from the resource manager.
                *   @param  key is a unique identifier for the resource. 
                *   @return True if the resource was removed and false otherwise.
                *************************************************************************************/
                bool remove(const int &key);
                

                /*********************************************************************************//**
                *	@brief  Destructor 
                *************************************************************************************/
                virtual ~ResourceManager();
            private:
                class Impl;
                Impl *m_pimpl = nullptr;
        };
        
        /*********************************************************************************//**
        *	@brief  Load resource from memory.
        *   @param  key is a unique identifier for the resource.
        *   @param  data is a pointer to the resources data.
        *   @param  size is the total size of the data. 
        *   @param  True is returned if the resource is loaded sucessfully and false otherwise.
        *************************************************************************************/
        template <class Resource>
        bool ResourceManager::load(const int &key, const std::shared_ptr<void> data, const std::size_t &size)
        {
            assert(m_pimpl != nullptr);
            assert(data != nullptr);
            std::shared_ptr<GU::Core::Resource> resource(new Resource());
            resource->load(data, size);
            return this->add(key, resource);
        }


        /*********************************************************************************//**
        *	@brief  Load resource disk. 
        *   @param  key is a unique identifier for the resource.
        *   @param  file is the pathe to the resource on disk. 
        *   @param  True is returned if the resource is loaded sucessfully and false otherwise.
        *************************************************************************************/
        template <class Resource>
        bool ResourceManager::load(const int &key, const GU::Core::String &file)
        {
            assert(m_pimpl != nullptr);
            std::shared_ptr<GU::Core::Resource> resource(new Resource());
            resource->load(file);
            return this->add(key, resource);
        }

    }
}

#endif

