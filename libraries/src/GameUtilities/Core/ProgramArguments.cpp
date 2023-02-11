/*********************************************************************************//**
*	@author  Wayne J Larson Jr.
*   @date    2/09/2023
*   @file    ProgramArguments.cpp
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
#include "GameUtilities/Core/ProgramArguments.h"
#include <map>
#include <cassert>
#include <utility>
#include <iostream>
#include <vector>
#include <stdexcept>
namespace GU 
{
    namespace Core 
    {

        typedef std::pair<const std::string, const char> keytype;

        class ProgramArguments::Impl
        {
            public:
                ///Map of keys
                std::map<const std::string, const std::size_t> m_keyMap; 
           
                ///Map of short keys 
                std::map<const char, const std::size_t> m_shortKeyMap; 

                ///vector of positional arguments
                std::vector<std::string> m_positional;

                ///vector of long program options
                std::vector<std::string> m_longArgs;

                ///vector of key value pair program options 
                std::vector<std::pair<std::string, std::string>> m_keyValue;

                ///vector of short program options
                std::vector<char> m_shortArgs;

                ///Vector of data associated with each key
                std::vector<std::pair<ProgramArguments::Callback, std::shared_ptr<void>>> m_keyData;
               
                 
                /***********************************************************************//**
                *   @brief  This method returns true if the long key is in the correct key
                *           map. 
                *   @return True if the key is in the key map and False otherwise 
                ***************************************************************************/
                bool keyExists(const std::string key) const;
                

                /***********************************************************************//**
                *   @brief  This method returns true if the short key is in the correct key
                *           map. 
                *   @return True if the key is in the key map and False otherwise 
                ***************************************************************************/
                bool shortKeyExists(const char key) const;
                
        };

        
        /***********************************************************************//**
        *   @brief  This method returns true if the long key is in the correct key
        *           map. 
        *   @return True if the key is in the key map and False otherwise 
        ***************************************************************************/
        bool ProgramArguments::Impl::keyExists(const std::string key) const
        {
           
            if(m_keyMap.find(key) == m_keyMap.end())
                return false;
            return true;
        }

        
        /***********************************************************************//**
        *   @brief  This method returns true if the short key is in the correct key
        *           map. 
        *   @return True if the key is in the key map and False otherwise 
        ***************************************************************************/
        bool ProgramArguments::Impl::shortKeyExists(const char key) const
        {
            if(m_shortKeyMap.find(key) == m_shortKeyMap.end())
                return false;
            return true;
        }

        
        /***********************************************************************//**
        *   @brief  Constructor
        ***************************************************************************/
        ProgramArguments::ProgramArguments():
        m_pimpl(new ProgramArguments::Impl())
        {

        }


        /***********************************************************************//**
        *   @brief  Constructor
        *   @param  argc the number of arguments passed to main.
        *   @param  argv an array of strings. Each string is a parameter passed to
        *           main.
        ***************************************************************************/
        ProgramArguments::ProgramArguments(int argc, char **argv):
        m_pimpl(new ProgramArguments::Impl())
        {
            parse(argc, argv);
        }
        

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
        bool ProgramArguments::add(const std::string &key, const char &shortKey, std::pair<Callback, std::shared_ptr<void>> data)
        {
            //m_pimpl cannot be a nullptr 
            assert(m_pimpl != nullptr);

            if(!isLongKey(key))
                return false;
            
            //Exit if key already exists 
            if(m_pimpl->keyExists(key))
                return false; 

            //Callback parameter can not be a nullptr 
            if(data.first == nullptr)
                return false;
            
            m_pimpl->m_keyData.push_back(data);
            std::size_t index = m_pimpl->m_keyData.size() - 1;


            //Add short key if the null character is not passed
            if(shortKey != '\0')
                if(!m_pimpl->shortKeyExists(shortKey))
                    m_pimpl->m_shortKeyMap.insert(std::make_pair(shortKey, index));
            

            return m_pimpl->m_keyMap.insert(std::make_pair(key, index)).second;
        }

        
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
        bool ProgramArguments::add(const std::string &key, const char &shortKey, Callback callback)
        {
            std::pair<Callback, std::shared_ptr<void>> data;
            data.first = callback;
            data.second = nullptr;
            
            return add(key, shortKey, data);

        }
       
        
        /***********************************************************************//**
        *   @brief  This method sets user defined data on a program option 
        *   @param  key is the program option.
        *   @param  data is a void shared pointer of user defined data. 
        *   @return True is return if the data is set and false otherwise.
        ***************************************************************************/
        bool ProgramArguments::setData(const GU::Core::String &key, std::shared_ptr<void> data)
        {

        }
    
        
        /***********************************************************************//**
        *   @brief  This method parsed the arguments passed to main 
        *   @param  argc is the number of arguments passed to main. 
        *   @param  argv is an array of string arguments passed to main. 
        ***************************************************************************/
        void ProgramArguments::parse(int argc, char **argv)
        {
            assert(m_pimpl != nullptr);
            
            for(int i = 1; i < argc; ++i)
            {
                std::string key(argv[i]);
                
                if(isKeyValue(key))
                {

                    if(key.find_first_of('=') + 1 >= key.size())
                        throw std::runtime_error("Key value pair is not valid");
         
                    std::string tempKey = key.substr(0, key.find_first_of('='));
                    std::string tempValue = key.substr(key.find_first_of('=') + 1, key.size());
                    std::pair<std::string, std::string> val(tempKey, tempValue); 
                    m_pimpl->m_keyValue.push_back(val);
                }
                else if(isLongKey(key))
                {
                    m_pimpl->m_longArgs.push_back(key);
                }
                else if(isShortKey(key))
                {
                    key.erase(std::remove(key.begin(), key.end(), '-'));
                    
                    for(std::size_t i = 0; i < key.size(); ++i)
                    {
                        m_pimpl->m_shortArgs.push_back(key[i]); 
                    }

                }
                else
                {
                    m_pimpl->m_positional.push_back(key);
                }
            } 
        }
        
        
        /***********************************************************************//**
        *   @brief  This method calls all callback functions associated with 
        *           each program option. 
        ***************************************************************************/
        void ProgramArguments::run() const
        {
            //Handle long arguments
            for(std::size_t i = 0; i < m_pimpl->m_longArgs.size(); ++i)
            {
                if(m_pimpl->keyExists(m_pimpl->m_longArgs[i]))
                {
                    std::size_t index = m_pimpl->m_keyMap[m_pimpl->m_longArgs[i]];
                    m_pimpl->m_keyData[index].first(m_pimpl->m_keyData[index].second);
                }
                else
                {
                    std::runtime_error("invalid long key");
                }
            }

            //Handle key value pairs
            for(std::size_t i = 0; i < m_pimpl->m_keyValue.size(); ++i)
            {
                std::cout << "Key = " << m_pimpl->m_keyValue[i].first << " value = " << m_pimpl->m_keyValue[i].second << std::endl;
            }
           
            
            //Handle short arguments 
            for(std::size_t i = 0; i < m_pimpl->m_shortArgs.size(); ++i)
            {
                if(m_pimpl->shortKeyExists(m_pimpl->m_shortArgs[i]))
                {
                    std::size_t index = m_pimpl->m_shortKeyMap[m_pimpl->m_shortArgs[i]];
                    m_pimpl->m_keyData[index].first(m_pimpl->m_keyData[index].second);
                }
                else
                {
                    throw std::runtime_error("Invalid Short Key");
                }
            }
        }

        
        /***********************************************************************//**
        *   @brief  This method returns the number of positional arguments
        *           passed to the main function. A positional argument is anything
        *           that is not a long or short option.
        *   @return The number of positional arguments.
        ***************************************************************************/
        std::size_t ProgramArguments::positionalSize() const
        {
            return m_pimpl->m_positional.size();
        }
        

        /***********************************************************************//**
        *   @brief  This method return positional arguments. 
        *   @param  index is the position of the argument starting at zero.
        *   @return A string containing the program option. 
        ***************************************************************************/
        std::string& ProgramArguments::operator [](const std::size_t &index)
        {
            assert(index < m_pimpl->m_positional.size());
            return m_pimpl->m_positional[index];
        }

        
        /***********************************************************************//**
        *   @brief  This method return positional arguments. 
        *   @param  index is the position of the argument starting at zero.
        *   @return A string containing the program option. 
        ***************************************************************************/
        std::string ProgramArguments::operator [](const std::size_t &index) const
        {
            assert(index < m_pimpl->m_positional.size());
            return m_pimpl->m_positional[index];
        }

        
        /***********************************************************************//**
        *   @brief  This method determines if the key is a valid long key. 
        *   @param  key is the program option to be inspected. 
        *   @return True is return if the key is a long key and false otherwise.
        ***************************************************************************/
        bool ProgramArguments::isLongKey(const std::string &key) const
        {
            //There need to be at least 3 character in each key
            //Two -- characters and one other character
            if(key.size() < 3)
                return false;


            //The third character cannot be an = sign
            if(key[2] == '=')
                return false;

            //Make sure the first two character of the key are --
            for(std::size_t i = 0; i < key.size() && i < 2; ++i)
            {
                if(key[i] != '-')
                {
                    return false; 
                }
            }   

            return true;
        }

        
        /***********************************************************************//**
        *   @brief  This method determines if the key is a valid key value pair. 
        *   @param  key is the program option to be inspected. 
        *   @return True is returned if the key is a valid key value pair.
        ***************************************************************************/
        bool ProgramArguments::isKeyValue(const std::string &key) const
        {
            if(!isLongKey(key))
                return false;

            if(key.find('=') == std::string::npos)
                return false;

            return true;
        }

        
        /***********************************************************************//**
        *   @brief  This method determines if the key is a valid short key. 
        *   @param  key is the program option to be inspected. 
        *   @return True is return if the key is a short key and false otherwise.
        ***************************************************************************/
        bool ProgramArguments::isShortKey(const std::string &key) const
        {
            if(key.size() < 2)
                return false;

            if(key[0] != '-')
                return false;

            if(key.find('=') != std::string::npos)
                return false;

            return true;
        }


        /***********************************************************************//**
        *   @brief  Destructor. 
        ***************************************************************************/
        ProgramArguments::~ProgramArguments()
        {
            if(m_pimpl != nullptr)
            {
                delete m_pimpl;
                m_pimpl = nullptr;
            }

        }
    }
}
