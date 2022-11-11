#ifndef WINDOW_WINDOWX11_H
#define WINDOW_WINDOWX11_H
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
                WindowX11(const Math::Vector2<float> &size);
                virtual void hide() const override;
                virtual void show() const override;
                std::size_t toGUKeyboardId(const std::size_t &key);
			    virtual bool poll(GU::Evt::EventPtr &event) override;
                void setTitle(const GU::Core::String &title);
                virtual void close() override;
                virtual bool isOpen() const;
                void setSize(const Math::Vector2<float> &size);
                virtual void setPosition(const Math::Vector2<float> &position);
                

                /********************************************************************//**
                *   @breif  This method sets the x window application's synchronize 
                *           mode. Setting synchronize to true will cause the windows
                *           debugging messages to appear in the order they were created.
                *           synchronize mode is recommended for debugging only. 
                *   @param  synch when set to true will turn on synchronous behavior.
                ************************************************************************/
                void synchronize(const bool &synch);
                virtual ~WindowX11();
            public:
                class Impl;
                Impl *m_pimpl = nullptr;    /*!< Pointer to the class implimentation */
        };
    }
}

#endif
