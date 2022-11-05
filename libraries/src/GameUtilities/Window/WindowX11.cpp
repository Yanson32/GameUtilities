/********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   10/18/22
*   @description    This class represents a window for the X11 windowing
*                   system.
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
#include "GameUtilities/Window/WindowX11.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cassert>
#include <iostream>

namespace GU
{
    namespace Win
    {
                
        class WindowX11::Impl
        {
            public:
                Display *d;
                Window w;
                XEvent e;
                int s;
        };
        
            
        WindowX11::WindowX11(const Math::Vector2<float> &size):
        WindowBase::WindowBase(size), 
        m_pimpl(new WindowX11::Impl())
        {

            const char *msg = "Hello, World!";

            m_pimpl->d = XOpenDisplay(NULL);
            if (m_pimpl->d == NULL) 
            {
                std::cerr << "Cannot open display"<< std::endl;
                exit(1);
            }

            m_pimpl->s = DefaultScreen(m_pimpl->d);
            m_pimpl->w = XCreateSimpleWindow(m_pimpl->d, 
                        RootWindow(m_pimpl->d, m_pimpl->s), 10, 10, size.x, size.y, 1, 
                        BlackPixel(m_pimpl->d, m_pimpl->s), WhitePixel(m_pimpl->d, m_pimpl->s));
           
            XSelectInput(m_pimpl->d, m_pimpl->w, ExposureMask | KeyPressMask);
            XMapWindow(m_pimpl->d, m_pimpl->w);

            while (true) 
            {
                XNextEvent(m_pimpl->d, &m_pimpl->e);
                if (m_pimpl->e.type == Expose) 
                {
                    XFillRectangle(m_pimpl->d, m_pimpl->w, DefaultGC(m_pimpl->d, m_pimpl->s), 20, 20, 10, 10);
                    XDrawString(m_pimpl->d, m_pimpl->w, DefaultGC(m_pimpl->d, m_pimpl->s), 10, 50, msg, strlen(msg));
                }
                
                if (m_pimpl->e.type == KeyPress)
                    break;
            }


        }
        

        void WindowX11::hide() const
        {
            
        }
        

        void WindowX11::show() const
        {

        }

        bool WindowX11::hasEvent() const
        {
            return true;
        }


        void WindowX11::handleGUEvent(EnginPtr engin, GU::Evt::EventPtr event)
        {
            std::cout << "WindowX11::handleGUEvent Not Implimented" << std::endl;
        }


        std::shared_ptr<GU::Evt::Event> WindowX11::getEvent() const
        {
            std::shared_ptr<GU::Evt::Event> event = nullptr;
            return event;
        }


        WindowX11::~WindowX11()
        {
            assert(m_pimpl != nullptr);
            XCloseDisplay(m_pimpl->d);
            if(m_pimpl != nullptr)
            {
                delete m_pimpl;
                m_pimpl = nullptr;
            }
        }
    }
}
