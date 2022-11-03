/**************************************************************************
*   @Author     Wayne J Larson Jr.
*   @Date       4/08/18
*   @class      This updater class is used to update the particles position.
*   @file       Position.cpp
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
#include "GameUtilities/ParticleSystem/Updaters/Position.h"
#include "GameUtilities/ParticleSystem/Attributes/Id.h"
#include "GameUtilities/ParticleSystem/Attributes/Manager.h"
#include "GameUtilities/ParticleSystem/Attributes/Velocity.h"
#include "GameUtilities/ParticleSystem/Attributes/Position.h"
#include <iostream>

namespace GU
{

    namespace PS
    {

        namespace UP
        {

            /************************************************************************//**
            *   @brief  Constructor 
            ****************************************************************************/
            Position::Position()
            {
                //ctor
            }


            /************************************************************************//**
            *   @brief  This method updates the current position of the particle.
            *   @param  manager is a reference to the attrubute manager.
            *   @param  deltaTime is the length of time for a single frame 
            ****************************************************************************/
            void Position::update(GU::PS::AT::Manager &manager, const float &deltaTime)
            {
                typedef GU::PS::AT::Velocity Velocity; 
                typedef GU::PS::AT::Position Position; 
                std::shared_ptr<Velocity> vel = std::static_pointer_cast<Velocity>(manager.getComponent(GU::PS::AT::Id::VELOCITY));
                std::shared_ptr<Position> pos = std::static_pointer_cast<Position>(manager.getComponent(GU::PS::AT::Id::POSITION));

                assert(vel != nullptr);
                assert(pos != nullptr);
                assert(pos->data.size() == vel->data.size());

                for(std::size_t i = 0; i < pos->data.size(); ++i)
                {
                    pos->data[i].first = pos->data[i].first + (vel->data[i].first * deltaTime);
                    pos->data[i].second = pos->data[i].second + (vel->data[i].second * deltaTime);
                }

            }


            /************************************************************************//**
            *   @brief  Destructor 
            ****************************************************************************/
            Position::~Position()
            {
                //dtor
            }
        }
    }
}
