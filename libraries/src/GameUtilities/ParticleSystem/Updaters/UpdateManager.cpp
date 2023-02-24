/**************************************************************************
*   @Author     Wayne J Larson Jr.
*   @Date       4/08/18
*   @class      This class stores all of the updaters for a particle system.   
*   @file       UpdateManager.cpp
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
#include "GameUtilities/ParticleSystem/Updaters/UpdateManager.h"
#include "GameUtilities/ParticleSystem/Attributes/AttributeManager.h"
#include <cassert>
namespace GU
{
    namespace PS
    {
        namespace UP
        {
            
            /************************************************************************//**
            *   @brief  Constructor 
            ****************************************************************************/
            UpdateManager::UpdateManager()
            {
                //ctor
            }

            
            /************************************************************************//**
            *   @brief  This method adds an Updater to the manager class. 
            *   @param  comp is a shared pointer to the updater to be added to the class. 
            ****************************************************************************/
            void UpdateManager::addUpdater(std::shared_ptr<GU::PS::UP::UpdaterBase> comp)
            {
                assert(comp != nullptr);
                data.push_back(comp);
            }

            
            /************************************************************************//**
            *   @brief  This method will call the update method of all stored updaters.
            *   @param  manager is a reference to the attrubute manager.
            *   @param  deltaTime is the length of time for a single frame 
            ****************************************************************************/
            void UpdateManager::update(GU::PS::AT::AttributeManager &manager, const float &deltaTime)
            {
                for(std::size_t i = 0; i < data.size(); ++i)
                {
                    data[i]->update(manager, deltaTime);
                }
            }


            /************************************************************************//**
            *   @brief  Destructor.
            ****************************************************************************/
            UpdateManager::~UpdateManager()
            {
                //dtor
            }
        }
    }
}
