/********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   10/18/22
*   @file   WindowX11.cpp 
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
#include "GameUtilities/Event/Events/Keyboard/KeyboardId.h"
#include "GameUtilities/Event/Events/Keyboard/OnKeyPressed.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cassert>
#include <iostream>
#include <memory>

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
        
            
        /********************************************************************//**
        *   @brief  Constructor. 
        *   @param  size is the size of the window. 
        ************************************************************************/
        WindowX11::WindowX11(const Math::Vector2<float> &size):
        WindowBase::WindowBase(size), 
        m_pimpl(new WindowX11::Impl())
        {

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

            #ifdef DEBUG
                synchronize(true); 
            #endif
        }
        
        
        /********************************************************************//**
        *   @brief  This method sets the x window application's synchronize 
        *           mode. Setting synchronize to true will cause the windows
        *           debugging messages to appear in the order they were created.
        *           synchronize mode is recommended for debugging only. 
        *   @param  synch when set to true will turn on synchronous behavior.
        ************************************************************************/
        void WindowX11::synchronize(const bool &synch)
        {
            XSynchronize(m_pimpl->d, synch);            
        }

        
        /********************************************************************//**
        *   @brief  This method hides the window.
        ************************************************************************/
        void WindowX11::hide() const
        {
            assert(m_pimpl != nullptr);        
            XUnmapWindow(m_pimpl->d, m_pimpl->w);
        }
        

        /********************************************************************//**
        *   @brief  This method displays the window. 
        ************************************************************************/
        void WindowX11::show() const
        {
            assert(m_pimpl != nullptr);        
            XMapWindow(m_pimpl->d, m_pimpl->w);
        }

        
        /********************************************************************//**
        *   @brief  Set the window's title. 
        *   @param  title is the new title for the window.
        ************************************************************************/
        void WindowX11::setTitle(const GU::Core::String &title)
        {
            XStoreName(m_pimpl->d, m_pimpl->w, title.c_str());
        }

        
        /********************************************************************//**
        *   @brief  This method converts a XWindow keyboard key to a GU key
        *           id. 
        *   @param  key is the XWindow keyboard key.
        *   @return An equivelent keyboard key to the input key but for the GU
        *           library. 
        ************************************************************************/
        std::size_t WindowX11::toGUKeyboardId(const std::size_t &key)
        {
            switch(key)
            {
                case 38:
                    return GU::Evt::KeyboardId::A;
                case 56:
                    return GU::Evt::KeyboardId::B;
                case 54:
                    return GU::Evt::KeyboardId::C;
                case 40:
                    return GU::Evt::KeyboardId::D;
                case 26:
                    return GU::Evt::KeyboardId::E;
                case 41:
                    return GU::Evt::KeyboardId::F;
                case 42:
                    return GU::Evt::KeyboardId::G;
                case 43:
                    return GU::Evt::KeyboardId::H;
                case 31:
                    return GU::Evt::KeyboardId::I;
                case 44:
                    return GU::Evt::KeyboardId::J;
                case 45:
                    return GU::Evt::KeyboardId::K;
                case 46:
                    return GU::Evt::KeyboardId::L;
                case 58:
                    return GU::Evt::KeyboardId::M;
                case 57:
                    return GU::Evt::KeyboardId::N;
                case 32:
                    return GU::Evt::KeyboardId::O;
                case 33:
                    return GU::Evt::KeyboardId::P;
                case 24:
                    return GU::Evt::KeyboardId::Q;
                case 27:
                    return GU::Evt::KeyboardId::R;
                case 39:
                    return GU::Evt::KeyboardId::S;
                case 28:
                    return GU::Evt::KeyboardId::T;
                case 30:
                    return GU::Evt::KeyboardId::U;
                case 55:
                    return GU::Evt::KeyboardId::V;
                case 25:
                    return GU::Evt::KeyboardId::W;
                case 53:
                    return GU::Evt::KeyboardId::X;
                case 29:
                    return GU::Evt::KeyboardId::Y;
                case 52:
                    return GU::Evt::KeyboardId::Z;
                case 10:
                    return GU::Evt::KeyboardId::ONE;
                case 11:
                    return GU::Evt::KeyboardId::TWO;
                case 12:
                    return GU::Evt::KeyboardId::THREE;
                case 13:
                    return GU::Evt::KeyboardId::FOUR;
                case 14:
                    return GU::Evt::KeyboardId::FIVE;
                case 15:
                    return GU::Evt::KeyboardId::SIX;
                case 16:
                    return GU::Evt::KeyboardId::SEVEN;
                case 17:
                    return GU::Evt::KeyboardId::EIGHT;
                case 18:
                    return GU::Evt::KeyboardId::NINE;
                case 19:
                    return GU::Evt::KeyboardId::ZERO;
                case 36:
                    return GU::Evt::KeyboardId::RETURN;
                case 65:
                    return GU::Evt::KeyboardId::SPACE;
                case 50:
                    return GU::Evt::KeyboardId::LEFT_SHIFT;
                case 62:
                    return GU::Evt::KeyboardId::RIGHT_SHIFT;
                case 37:
                    return GU::Evt::KeyboardId::LEFT_CTRL;
                case 105:
                    return GU::Evt::KeyboardId::RIGHT_CTRL;
                case 64:
                    return GU::Evt::KeyboardId::LEFT_ALT;
                case 108:
                    return GU::Evt::KeyboardId::RIGHT_ALT;
                case 133:
                    return GU::Evt::KeyboardId::META;
                case 9:
                    return GU::Evt::KeyboardId::ESC;
                case 111:
                    return GU::Evt::KeyboardId::UP_ARROW;
                case 116:
                    return GU::Evt::KeyboardId::DOWN_ARROW;
                case 113:
                    return GU::Evt::KeyboardId::LEFT_ARROW;
                case 114:
                    return GU::Evt::KeyboardId::RIGHT_ARROW;
                case 22:
                    return GU::Evt::KeyboardId::BACKSPACE;
                default:
                {
                    std::cerr << "Default case reached" << std::endl;
                    return key;
                }
            };
        }


        /********************************************************************//**
        *   @brief  This method closes the window. 
        ************************************************************************/
        void WindowX11::close()
        {
            assert(m_pimpl != nullptr);        
            XDestroyWindow(m_pimpl->d, m_pimpl->w);
            m_pimpl->d = nullptr;
        }


        /********************************************************************//**
        *   @brief  This method gets the next window event. 
        *   @param  event is a pointer to the next window event. 
        *   @return True when the event pointer is pointing to a valid event
        *           and false otherwise. 
        ************************************************************************/
	    bool WindowX11::poll(GU::Evt::EventPtr &event)
        {
            while (true) 
            {
                XNextEvent(m_pimpl->d, &m_pimpl->e);
                
                if (m_pimpl->e.type == KeyPress)
                {
                    event = std::shared_ptr<GU::Evt::OnKeyPressed>(new GU::Evt::OnKeyPressed(toGUKeyboardId(m_pimpl->e.xkey.keycode)));
                    return true; 
                }
            }
             
            return true;
        }
        

        /********************************************************************//**
        *   @brief  This method returns true when the window is open. 
        *   @return True if the window is open and false otherwise. 
        ************************************************************************/
        bool WindowX11::isOpen() const
        {
            assert(m_pimpl != nullptr);
            if(m_pimpl->d == nullptr)
                return false;
            return true;
        }


        /********************************************************************//**
        *   @brief  This method sets the size of the window. 
        *   @param  size is the new size of the window. size.x is the width
        *           and size.y is the height. 
        ************************************************************************/
        void WindowX11::setSize(const Math::Vector2<float> &size)
        {
            XWindowAttributes xwa;
            XGetWindowAttributes(m_pimpl->d, m_pimpl->w, &xwa);
            XMoveResizeWindow(m_pimpl->d, m_pimpl->w, xwa.x, xwa.y, size.x, size.y);
        }


        /********************************************************************//**
        *   @brief  This method sets the position of the window. 
        *   @param  position is the new position of the window. position.x is
        *           the width and position.y is the height. 
        ************************************************************************/
        void WindowX11::setPosition(const Math::Vector2<float> &position)
        {
            XWindowAttributes xwa;
            XGetWindowAttributes(m_pimpl->d, m_pimpl->w, &xwa);
            XMoveResizeWindow(m_pimpl->d, m_pimpl->w, position.x, position.y, xwa.width, xwa.height);
        }

    
        /********************************************************************//**
        *   @brief  Destructor. 
        ************************************************************************/
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
