#ifndef GAMEUTILITIES_PROGRAM_ARGUMENTS
#define GAMEUTILITIES_PROGRAM_ARGUMENTS
/*********************************************************************************//**
*	@author  Wayne J Larson Jr.
*   @date    2/09/2023
*   @file    ProgramArguments.h
*************************************************************************************/

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
#include <string>
#include "GameUtilities/Core/String.h"
namespace GU 
{
    namespace Core 
    {

        class ProgramArguments
        {
            public:
                typedef void(*Callback)(void*);
                ProgramArguments();
                ProgramArguments(int argc, char **argv);
                bool add(const std::string &key, const char &shortKey = '\0', Callback callback = nullptr);
                bool add(const std::string &key, const char &shortKey, std::pair<Callback, void*> data);
                bool setData(const GU::Core::String &key, void* data);
                void parse(int argc, char **argv);
                bool isLongKey(const std::string &key) const;
                bool isShortKey(const std::string &key) const;
                bool isKeyValue(const std::string &key) const;
                void run() const;
                std::size_t positionalSize() const;
                std::string& operator [](const std::size_t &index);
                std::string operator [](const std::size_t &index) const;
                virtual ~ProgramArguments();
            private:
                class Impl;
                Impl *m_pimpl = nullptr;
        };
    }
}
#endif
