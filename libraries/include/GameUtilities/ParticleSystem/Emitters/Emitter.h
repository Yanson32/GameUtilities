#ifndef GU_EMITTER_H
#define GU_EMITTER_H
/**************************************************************************
*   @Author     Wayne J Larson Jr.
*   @Date       4/08/18
*   @class      This class is the base class for all Emitters 
*   @file       Emitter.h
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
#include <cstddef>
#include "particlesystem_export.h"
#include "Math/Vector.h"
#include "GameUtilities/ParticleSystem/Particle.h"

namespace GU
{
    namespace PS
    {
        class ParticleSystem;
        namespace EM
        {

            class PARTICLESYSTEM_EXPORT Emitter
            {
                public:
                    /************************************************************************//**
                    *   @brief  Constructor. 
                    *   @param  parent is a pointer to the parent particle system. 
                    *   @param  ppf (particles per frame) is the number of particles in the system.
                    *   @param  relativePosition is the relative position of the emitter. 
                    ****************************************************************************/
                    Emitter(GU::PS::ParticleSystem *parent, const std::size_t ppf, Math::Vector relativePosition = Math::Vector());
                    

                    /************************************************************************//**
                    *   @brief  This method creates particles  
                    ****************************************************************************/
                    virtual void emit() = 0;
                    
                    
                    /************************************************************************//**
                    *   @brief  This method sets the relative position of the emitter. 
                    *   @param  relativePosition is the new relative position of the emitter. 
                    ****************************************************************************/
                    void setRelativePosition(const Math::Vector &relativePosition);
                    

                    /************************************************************************//**
                    *   @brief  This method returns the relative position of the emitter. 
                    *   @return A Vector of the relative position for the Emitter. 
                    ****************************************************************************/
                    Math::Vector getRelativePosition() const;
                    

                    /************************************************************************//**
                    *   @brief  Destructor 
                    ****************************************************************************/
                    virtual ~Emitter();
                protected:
                    const unsigned m_ppf = 0;           //Particles per frame
                    ParticleSystem *m_parent = nullptr;
                    Math::Vector m_relativePosition;
            };
        }
    }
}

#endif // GU_EMITTER_H
