/**************************************************************************
*   @Author     Wayne J Larson Jr.
*   @Date       4/06/19
*   @class      This class emits particles aling a line. 
*   @file       LineEmitter.cpp
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

#include "GameUtilities/ParticleSystem/Emitters/Line.h"


namespace GU
{
    namespace PS
    {
        namespace EM
        {
            
            /************************************************************************//**
            *   @brief  Constructor. 
            *   @param  parent is a pointer to the parent particle system. 
            *   @param  ppf (particles per frame) is the number of particles in the system.
            *   @param  relativePosition is the relative position of the emitter. 
            ****************************************************************************/
            LineEmitter::LineEmitter(GU::PS::ParticleSystem *parent, const std::size_t ppf, Math::Vector relativePosition):
            Emitter(parent, ppf, relativePosition)
            {
                //ctor
            }

            
            /************************************************************************//**
            *   @brief  This method creates particles  
            ****************************************************************************/
            void LineEmitter::emit()
            {

            }


            /************************************************************************//**
            *   @brief  Destructor.
            ****************************************************************************/
            LineEmitter::~LineEmitter()
            {
                //dtor
            }
        }
    }
}
