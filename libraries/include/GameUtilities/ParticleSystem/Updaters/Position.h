#ifndef PARTICLE_SYSTEM_UPDATER_POSITION_H
#define PARTICLE_SYSTEM_UPDATER_POSITION_H
/**************************************************************************
*   @Author     Wayne J Larson Jr.
*   @Date       4/08/18
*   @class      This updater class is used to update the particles position.
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
#include "GameUtilities/ParticleSystem/Updaters/UpdaterBase.h"

namespace GU
{

    namespace PS
    {

        namespace UP
        {

            class PARTICLESYSTEM_EXPORT Position: public GU::PS::UP::UpdaterBase
            {
                public:
                    /************************************************************************//**
                    *   @brief  Constructor 
                    ****************************************************************************/
                    Position();
                    

                    /************************************************************************//**
                    *   @brief  This method updates the current position of the particle.
                    *   @param  manager is a reference to the attrubute manager.
                    *   @param  deltaTime is the length of time for a single frame 
                    ****************************************************************************/
                    virtual void update(GU::PS::AT::AttributeManager &manager, const float &deltaTime);
           
 
                    /************************************************************************//**
                    *   @brief  Destructor 
                    ****************************************************************************/
                    virtual ~Position();
            };
        }
    }
}
#endif // PARTICLE_SYSTEM_UPDATER_POSITION_H
