/********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   10/18/22
*   @description   This class represents a window 
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
#include "GameUtilities/Window/Window.h"
#include "GameUtilities/Window/WindowX11.h"
#include <memory>
#include <cassert>

namespace GU
{
    namespace Win
    {

        class Window::Impl
        {
            public:
                #ifdef X11 
                    std::shared_ptr<GU::Win::WindowBase> m_windowImpl = std::shared_ptr<GU::Win::WindowBase>(new WindowX11());
                #else
                    std::shared_ptr<GU::Win::WindowBase> m_windowImpl = nullptr;
                #endif
        };

        Window::Window():
        m_pimpl(new Window::Impl())
        {
            assert(m_pimpl != nullptr);
            assert(m_pimpl->m_windowImpl != nullptr);
        }

        Window::~Window()
        {
            assert(m_pimpl != nullptr);
            assert(m_pimpl->m_windowImpl != nullptr);
        }
    }
}