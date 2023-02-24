/********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   10/18/22
*   @file   Window.cpp
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
#ifdef X11 
    #include "GameUtilities/Window/WindowX11.h"
#endif
#include <memory>
#include <cassert>

namespace GU
{
    namespace Win
    {

        class Window::Impl
        {
            public:
                Impl(const Math::Vector2<float> &size);
                    std::shared_ptr<GU::Win::WindowBase> m_windowImpl = nullptr; 
        };


        Window::Impl::Impl(const Math::Vector2<float> &size)
        {
                #ifdef X11 
                    m_windowImpl = std::shared_ptr<GU::Win::WindowBase>(new WindowX11(size));
                #endif
            
        }

        
        /********************************************************************//**
        *   @brief  Constructor. 
        *   @param  size is the size of the window. 
        ************************************************************************/
        Window::Window(const Math::Vector2<float> &size):
        WindowBase::WindowBase(size),
        m_pimpl(new Window::Impl(size))
        {
            assert(m_pimpl != nullptr);
            assert(m_pimpl->m_windowImpl != nullptr);
        }


        /********************************************************************//**
        *   @brief  This method hides the window.
        ************************************************************************/
        void Window::hide() const
        {
            assert(m_pimpl != nullptr);
            assert(m_pimpl->m_windowImpl != nullptr);
            m_pimpl->m_windowImpl->hide();

        }


        /********************************************************************//**
        *   @brief  This method displays the window. 
        ************************************************************************/
        void Window::show() const
        {
            assert(m_pimpl != nullptr);
            assert(m_pimpl->m_windowImpl != nullptr);
            m_pimpl->m_windowImpl->show();
        }

        
        /********************************************************************//**
        *   @brief  This method gets the next window event. 
        *   @param  event is a pointer to the next window event. 
        *   @return True when the event pointer is pointing to a valid event
        *           and false otherwise. 
        ************************************************************************/
 		bool Window::poll(GU::Evt::EventPtr &event)
        {
            assert(m_pimpl != nullptr);
            assert(m_pimpl->m_windowImpl != nullptr);
            m_pimpl->m_windowImpl->poll(event);
            return true;
        }
        

        /********************************************************************//**
        *   @brief  Set the window's title. 
        *   @param  title is the new title for the window.
        ************************************************************************/
        void Window::setTitle(const GU::Core::String &title)
        {
            assert(m_pimpl != nullptr);
            assert(m_pimpl->m_windowImpl != nullptr);
            m_pimpl->m_windowImpl->setTitle(title);
        }


        /********************************************************************//**
        *   @brief  This method closes the window. 
        ************************************************************************/
        void Window::close()
        {
            assert(m_pimpl != nullptr);
            assert(m_pimpl->m_windowImpl != nullptr);
            m_pimpl->m_windowImpl->close();
        }

    
        /********************************************************************//**
        *   @brief  This method returns true when the window is open. 
        *   @return True if the window is open and false otherwise. 
        ************************************************************************/
        bool Window::isOpen() const
        {
            assert(m_pimpl != nullptr);
            assert(m_pimpl->m_windowImpl != nullptr);
            return m_pimpl->m_windowImpl->isOpen();
        }


        /********************************************************************//**
        *   @brief  This method sets the size of the window. 
        *   @param  size is the new size of the window. size.x is the width
        *           and size.y is the height. 
        ************************************************************************/
        void Window::setSize(const Math::Vector2<float> &size)
        {
            assert(m_pimpl != nullptr);
            assert(m_pimpl->m_windowImpl != nullptr);
            m_pimpl->m_windowImpl->setSize(size);
        }

        
        /********************************************************************//**
        *   @brief  This method sets the position of the window. 
        *   @param  position is the new position of the window. position.x is
        *           the width and position.y is the height. 
        ************************************************************************/
        void Window::setPosition(const Math::Vector2<float> &position)
        {
            assert(m_pimpl != nullptr);
            assert(m_pimpl->m_windowImpl != nullptr);
            m_pimpl->m_windowImpl->setPosition(position);
        }


        /********************************************************************//**
        *   @brief  Destructor. 
        ************************************************************************/
        Window::~Window()
        {
            assert(m_pimpl != nullptr);
            assert(m_pimpl->m_windowImpl != nullptr);
        }
    }
}
