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
#include <memory>

namespace GU 
{
    namespace Core 
    {

        struct ArgumentData
        {
            std::shared_ptr<void> data; 
            std::string value;
        };

        class ProgramArguments
        {
            public:
                typedef void(*Callback)(ArgumentData);

                /***********************************************************************//**
                *   @brief  Constructor
                ***************************************************************************/
                ProgramArguments();
               
 
                /***********************************************************************//**
                *   @brief  Constructor
                *   @param  argc the number of arguments passed to main.
                *   @param  argv an array of strings. Each string is a parameter passed to
                *           main.
                ***************************************************************************/
                ProgramArguments(int argc, char **argv);
                
                
                /***********************************************************************//**
                *   @brief  This method adds a program option.
                *   @param  key is the program long option it should begin with -- eg --help.
                *   @param  shortKey is the short one character version of the option.
                *           The short version should begin with - eg. -h.
                *           the '\0' character can be used to indicate no short option.
                *   @param  data is a std::pair the first parameter being a function callback
                *           and the second parameter a void shared_ptr of user defined data.
                *   @return True if the option wass added and false otherwise.
                ***************************************************************************/
                bool add(const std::string &key, const char &shortKey, std::pair<Callback, ArgumentData> data);
                

                /***********************************************************************//**
                *   @brief  This method adds a program option.
                *   @param  key is the program long option it should begin with -- eg --help.
                *   @param  callback is a function pointer that will be called when either
                *           the long or short option is passed to the program and the run 
                *           method is called. 
                *   @return True if the option wass added and false otherwise.
                ***************************************************************************/
                bool add(const std::string &key, Callback callback);

    
                /***********************************************************************//**
                *   @brief  This method adds a program option.
                *   @param  key is the program long option it should begin with -- eg --help.
                *   @param  shortKey is the short one character version of the option.
                *           The short version should begin with - eg. -h.
                *           the '\0' character can be used to indicate no short option.
                *   @param  callback is a function pointer that will be called when either
                *           the long or short option is passed to the program and the run 
                *           method is called. 
                *   @return True if the option wass added and false otherwise.
                ***************************************************************************/
                bool add(const std::string &key, const char &shortKey, Callback callback);
                

                /***********************************************************************//**
                *   @brief  This method sets user defined data on a program option 
                *   @param  key is the program option.
                *   @param  data is a void shared pointer of user defined data. 
                *   @return True is return if the data is set and false otherwise.
                ***************************************************************************/
                bool setData(const GU::Core::String &key, std::shared_ptr<void> data);
                

                /***********************************************************************//**
                *   @brief  This method parsed the arguments passed to main 
                *   @param  argc is the number of arguments passed to main. 
                *   @param  argv is an array of string arguments passed to main. 
                ***************************************************************************/
                void parse(int argc, char **argv);
                

                /***********************************************************************//**
                *   @brief  This method calls all callback functions associated with 
                *           each program option. 
                ***************************************************************************/
                void run() const;
                

                /***********************************************************************//**
                *   @brief  This method returns the number of positional arguments
                *           passed to the main function. A positional argument is anything
                *           that is not a long or short option.
                *   @return The number of positional arguments.
                ***************************************************************************/
                std::size_t positionalSize() const;
                

                /***********************************************************************//**
                *   @brief  This method return positional arguments. 
                *   @param  index is the position of the argument starting at zero.
                *   @return A string containing the program option. 
                ***************************************************************************/
                std::string& operator [](const std::size_t &index);
                

                /***********************************************************************//**
                *   @brief  This method return positional arguments. 
                *   @param  index is the position of the argument starting at zero.
                *   @return A string containing the program option. 
                ***************************************************************************/
                std::string operator [](const std::size_t &index) const;
                

                /***********************************************************************//**
                *   @brief  Destructor. 
                ***************************************************************************/
                virtual ~ProgramArguments();
            private:
                /***********************************************************************//**
                *   @brief  This method determines if the key is a valid long key. 
                *   @param  key is the program option to be inspected. 
                *   @return True is return if the key is a long key and false otherwise.
                ***************************************************************************/
                bool isLongKey(const std::string &key) const;
                

                /***********************************************************************//**
                *   @brief  This method determines if the key is a valid short key. 
                *   @param  key is the program option to be inspected. 
                *   @return True is return if the key is a short key and false otherwise.
                ***************************************************************************/
                bool isShortKey(const std::string &key) const;
                

                /***********************************************************************//**
                *   @brief  This method determines if the key is a valid key value pair. 
                *   @param  key is the program option to be inspected. 
                *   @return True is returned if the key is a valid key value pair.
                ***************************************************************************/
                bool isKeyValue(const std::string &key) const;
                
                bool isPositional(const std::string &key) const;
                class Impl;
                Impl *m_pimpl = nullptr;
        };

    
    }
}
#endif
