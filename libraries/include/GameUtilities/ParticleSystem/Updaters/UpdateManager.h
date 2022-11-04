#ifndef PARTICLE_SYSTEM_UPDATER_MANAGER_H
#define PARTICLE_SYSTEM_UPDATER_MANAGER_H
/**************************************************************************
*   @Author     Wayne J Larson Jr.
*   @Date       4/08/18
*   @class      This class stores all of the updaters for a particle system.   
*   @file       UpdateManager.h
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
#include "GameUtilities/ParticleSystem/Updaters/UpdaterBase.h"
#include <memory>
#include <vector>
namespace GU
{
    namespace PS
    {
        namespace AT
        {
            class Manager;
        }
        namespace UP
        {
            class PARTICLESYSTEM_EXPORT UpdateManager
            {
                public:
                    /************************************************************************//**
                    *   @brief  Constructor 
                    ****************************************************************************/
                    UpdateManager();
                    

                    /************************************************************************//**
                    *   @brief  This method adds an Updater to the manager class. 
                    *   @param  comp is a shared pointer to the updater to be added to the class. 
                    ****************************************************************************/
                    void addUpdater(std::shared_ptr<GU::PS::UP::UpdaterBase> comp);
                    

                    /************************************************************************//**
                    *   @brief  This method will call the update method of all stored updaters.
                    *   @param  manager is a reference to the attrubute manager.
                    *   @param  deltaTime is the length of time for a single frame 
                    ****************************************************************************/
                    void update(GU::PS::AT::Manager &manager, const float &deltaTime);
                    

                    /************************************************************************//**
                    *   @brief  Destructor.
                    ****************************************************************************/
                    virtual ~UpdateManager();

                protected:

                private:
                    std::vector<std::shared_ptr<GU::PS::UP::UpdaterBase>> data;
            };
        }
    }
}
#endif // PARTICLE_SYSTEM_UPDATER_MANAGER_H
