#ifndef PARTICLE_SYSTEM_UPDATERS_BASE_H
#define PARTICLE_SYSTEM_UPDATERS_BASE_H
/**************************************************************************
*   @Author     Wayne J Larson Jr.
*   @Date       4/08/18
*   @class      This class is the base class for all updaters.
*   @file       UpdaterBase.h
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

namespace GU
{
    namespace PS
    {
        namespace AT
        {
            class AttributeManager;
        }

        namespace UP
        {

            class PARTICLESYSTEM_EXPORT UpdaterBase
            {
                public:
                    /************************************************************************//**
                    *   @brief  Constructor.  
                    ****************************************************************************/
                    UpdaterBase();
                    

                    /************************************************************************//**
                    *   @brief  This is a pure virtual method for updating an attribute.
                    *   @param  manager is a reference to the attrubute manager.
                    *   @param  deltaTime is the length of time for a single frame 
                    ****************************************************************************/
                    virtual void update(GU::PS::AT::AttributeManager &manager, const float &deltaTime) = 0;
                    

                    /************************************************************************//**
                    *   @brief  Destructor.
                    ****************************************************************************/
                    virtual ~UpdaterBase();

            };
        }
    }
}
#endif // PARTICLE_SYSTEM_UPDATERS_BASE_H
