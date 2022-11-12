#ifndef WINDOW_WINDOWX11_H
#define WINDOW_WINDOWX11_H
/********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   10/18/22
*   @class  WindowX11
*   @file   WindowX11.h
*   @brief  This class represents a window for the X11 windowing system.
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

#include <X11/Xlib.h>
#include "window_export.h"
#include "GameUtilities/Window/WindowBase.h"
#include "GameUtilities/Event/Events/Event.h"


namespace GU
{
    namespace Win
    {


        class WINDOW_EXPORT WindowX11: public WindowBase
        {
            public:
                /********************************************************************//**
                *   @brief  Constructor. 
                *   @param  size is the size of the window. 
                ************************************************************************/
                WindowX11(const Math::Vector2<float> &size);
                

                /********************************************************************//**
                *   @brief  This method sets the x window application's synchronize 
                *           mode. Setting synchronize to true will cause the windows
                *           debugging messages to appear in the order they were created.
                *           synchronize mode is recommended for debugging only. 
                *   @param  synch when set to true will turn on synchronous behavior.
                ************************************************************************/
                void synchronize(const bool &synch);
                

                /********************************************************************//**
                *   @brief  This method hides the window.
                ************************************************************************/
                virtual void hide() const override;
                

                /********************************************************************//**
                *   @brief  This method displays the window. 
                ************************************************************************/
                virtual void show() const override;
                

                /********************************************************************//**
                *   @brief  Set the window's title. 
                *   @param  title is the new title for the window.
                ************************************************************************/
                void setTitle(const GU::Core::String &title);
                

                /********************************************************************//**
                *   @brief  This method converts a XWindow keyboard key to a GU key
                *           id. 
                *   @param  key is the XWindow keyboard key.
                *   @return An equivelent keyboard key to the input key but for the GU
                *           library. 
                ************************************************************************/
                std::size_t toGUKeyboardId(const std::size_t &key);
                

                /********************************************************************//**
                *   @brief  This method closes the window. 
                ************************************************************************/
                virtual void close() override;
                

                /********************************************************************//**
                *   @brief  This method gets the next window event. 
                *   @param  event is a pointer to the next window event. 
                *   @return True when the event pointer is pointing to a valid event
                *           and false otherwise. 
                ************************************************************************/
			    virtual bool poll(GU::Evt::EventPtr &event) override;
                

                /********************************************************************//**
                *   @brief  This method returns true when the window is open. 
                *   @return True if the window is open and false otherwise. 
                ************************************************************************/
                virtual bool isOpen() const;
                

                /********************************************************************//**
                *   @brief  This method sets the size of the window. 
                *   @param  size is the new size of the window. size.x is the width
                *           and size.y is the height. 
                ************************************************************************/
                void setSize(const Math::Vector2<float> &size);
                

                /********************************************************************//**
                *   @brief  This method sets the position of the window. 
                *   @param  position is the new position of the window. position.x is
                *           the width and position.y is the height. 
                ************************************************************************/
                virtual void setPosition(const Math::Vector2<float> &position);
                

                /********************************************************************//**
                *   @brief  Destructor. 
                ************************************************************************/
                virtual ~WindowX11();
            public:
                class Impl;
                Impl *m_pimpl = nullptr;    /*!< Pointer to the class implimentation */
        };
    }
}

#endif
