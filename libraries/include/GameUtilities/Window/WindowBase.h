#ifndef WINDOW_WINDOWBASE_H
#define WINDOW_WINDOWBASE_H
/********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   10/18/22
*   @description   This class the base class for all windows.
************************************************************************/

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

#include "window_export.h"
#include <Math/Vector2.h>
#include <memory>
#include "GameUtilities/Event/Events/Event.h"
#include "GameUtilities/Event/EventQueue.h"
#include "GameUtilities/Event/EventHandler.h"

namespace GU
{
    namespace Win
    {
        class WINDOW_EXPORT WindowBase: public GU::Evt::EventQueue, public GU::Evt::EventHandler
        {
            public:
                WindowBase(const Math::Vector2<float> &size);
                virtual void hide() const = 0;
                virtual void show() const = 0;
                virtual void handleGUEvent(EnginPtr engin, GU::Evt::EventPtr event) = 0;
                virtual ~WindowBase();
        };
    }
}

#endif

