#ifndef WINDOW_WINDOW_H
#define WINDOW_WINDOW_H
/********************************************************************//**
*   @author Wayne J Larson Jr.
*   @date   10/18/22
*   @file   Window.h
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
#include "GameUtilities/Window/WindowBase.h"
#include "GameUtilities/Event/Events/Event.h"
#include <Math/Vector2.h>
#include <memory>


namespace GU
{
    namespace Win
    {
        
        /********************************************************************//**
        *   @class  Window
        *   @brief  This class represents a window 
        ************************************************************************/
        class WINDOW_EXPORT Window: public WindowBase
        {
            public:
                /********************************************************************//**
                *   @brief  Constructor. 
                *   @param  size is the size of the window. 
                ************************************************************************/
                Window(const Math::Vector2<float> &size);
                

                /********************************************************************//**
                *   @brief  This method hides the window.
                ************************************************************************/
                virtual void hide() const override;
                

                /********************************************************************//**
                *   @brief  This method displays the window. 
                ************************************************************************/
                virtual void show() const override;
                

                /********************************************************************//**
                *   @brief  This method gets the next window event. 
                *   @param  event is a pointer to the next window event. 
                *   @return True when the event pointer is pointing to a valid event
                *           and false otherwise. 
                ************************************************************************/
			    virtual bool poll(GU::Evt::EventPtr &event) override;
                

                /********************************************************************//**
                *   @brief  Set the window's title. 
                *   @param  title is the new title for the window.
                ************************************************************************/
                virtual void setTitle(const GU::Core::String &title);
                

                /********************************************************************//**
                *   @brief  This method closes the window. 
                ************************************************************************/
                virtual void close() override;
                

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
                virtual void setSize(const Math::Vector2<float> &size);
                

                /********************************************************************//**
                *   @brief  This method sets the position of the window. 
                *   @param  position is the new position of the window. position.x is
                *           the width and position.y is the height. 
                ************************************************************************/
                virtual void setPosition(const Math::Vector2<float> &position);
                

                /********************************************************************//**
                *   @brief  Destructor. 
                ************************************************************************/
                virtual ~Window();
            private:
                class Impl;
                Impl *m_pimpl = nullptr;    /**< A pointer to the class implimentation */
        };
    }
};

#endif


