/*********************************************************************************//**
*	@author Wayne J Larson Jr.
*   @date   8/7/2021
*   @file   String.cpp
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
#include "GameUtilities/Core/String.h"
#include <limits>
#include <string>
#include <iostream>
#include <cassert>

namespace GU
{
    namespace Core
    {

      class String::Impl
      {
        public:
          Impl(){}
          virtual ~Impl(){};
          std::string m_data;
          #ifdef MULTITHREAD
            mutable std::mutex eventQueueLock;
          #endif
      };


        std::size_t String::npos = std::numeric_limits<std::size_t>::max();

        /***************************************************************//**
        * @brief Constructor
        *******************************************************************/
        String::String():
        pimpl(new String::Impl())
        {
          assert(pimpl != nullptr);
        }
        

        /***************************************************************//**
        * @brief Constructor
        * @param data is a string of characters
        *******************************************************************/
        String::String(const std::string &data):
        pimpl(new String::Impl())
        {
          assert(pimpl != nullptr);
          std::string p = data;
          pimpl->m_data = data;
        }

        
        /***************************************************************//**
        * @brief Constructor
        * @param data is a pointer to a string of characters
        *******************************************************************/
        String::String(const char* data):
        pimpl(new String::Impl)
        {
          assert(pimpl != nullptr);
          pimpl->m_data = std::string(data);
        }
       
 
        /***************************************************************//**
        * @brief Copy constructor
        * @param data is the String object to be copied. 
        *******************************************************************/
        String::String(const String &data):
        pimpl(new String::Impl())
        {
          assert(pimpl != nullptr);
          pimpl->m_data = data.pimpl->m_data;
        }
       
 
        /***************************************************************//**
        * @brief  This method allows the String to be cast to a const char* 
        * @return A pointer to the string of characters 
        *******************************************************************/
        String::operator const char*() const
        {
          return pimpl->m_data.c_str();
        }
        
        
        /***************************************************************//**
        * @brief  copy assignment operator
        * @param  data is the String object to be copied. 
        * @return A copy of the updated string.
        *******************************************************************/
        String String::operator=(const String &data)
        {
          assert(pimpl != nullptr);
          pimpl->m_data.resize(0);
          for(std::size_t i = 0; i < data.pimpl->m_data.size(); ++i)
          {
            pimpl->m_data.push_back(data.pimpl->m_data[i]);
          }

          return pimpl->m_data;
        }

        
        /***************************************************************//**
        * @brief  assignment operator
        * @param  data is a pointer to the data to be assigned 
        * @return A copy of the updated string. 
        *******************************************************************/
        String String::operator=(const char* data)
        {
          assert(pimpl != nullptr);
          return pimpl->m_data = data;
        }


        /***************************************************************//**
        * @brief  Equality operator
        * @param  data is a String object to be checked for equality. 
        * @return True if this object and the passed object are equal 
        *******************************************************************/
        bool String::operator==(const String &data) const
        {
          assert(pimpl != nullptr);
          return this->pimpl->m_data == data.pimpl->m_data;
        }


        /***************************************************************//**
        * @brief  Equality operator
        * @param  data is a pointer to a string of characters to be checked
        *         against for equality. 
        * @return True if this object and the passed object are equal 
        *******************************************************************/
        bool String::operator==(const char* data) const
        {
          assert(pimpl != nullptr);
          return this->pimpl->m_data == String(data);
        }


        /***************************************************************//**
        * @brief  Less than or equal to operator 
        * @param  data is a String object to be checked if it is less than or 
        *         equal to this object. 
        * @return True if data is less than or equal to the this object
        *         and false otherwise. 
        *******************************************************************/
        bool String::operator<=(const String &data) const
        {
          assert(pimpl != nullptr);
          return this->pimpl->m_data <= data.pimpl->m_data;
        }


        /***************************************************************//**
        * @brief  Greater than or equal to operator
        * @param  data is a String object to be checked if it is greater
        *         than or equal to this object. 
        * @return True if data is greater than or equal to the this object. 
        *         and false otherwise
        *******************************************************************/
        bool String::operator>=(const String &data) const
        {
          assert(pimpl != nullptr);
          return this->pimpl->m_data >= data.pimpl->m_data;
        }

        
        /***************************************************************//**
        * @brief  This method returns an iterator to the beginning of the
        *         string. 
        * @return An iterator to the beginning of the string. 
        *******************************************************************/
        std::string::iterator String::begin() noexcept
        {
            return std::begin(this->pimpl->m_data);
        }


        /***************************************************************//**
        * @brief  This method returns a const iterator to the beginning of 
        *         the string. 
        * @return An iterator to the beginning of the string. 
        *******************************************************************/
        std::string::const_iterator String::begin() const noexcept
        {
            return std::begin(this->pimpl->m_data);
        }
        
        /***************************************************************//**
        * @brief  This method returns a const iterator to the beginning of 
        *         the string. 
        * @return An iterator to the beginning of the string. 
        *******************************************************************/
        std::string::const_iterator String::cbegin() const noexcept
        {
            return std::cbegin(this->pimpl->m_data);
        }
        

        /***************************************************************//**
        * @brief  This method returns a reverse iterator to the end of 
        *         the string. 
        * @return A reverse iterator to the end of the string. 
        *******************************************************************/
        std::string::reverse_iterator String::rbegin() noexcept
        {
            return std::rbegin(this->pimpl->m_data);
        }


        /***************************************************************//**
        * @brief  This method returns a const reverse iterator to the end of 
        *         the string. 
        * @return A const reverse iterator to the end of the string. 
        *******************************************************************/
        std::string::const_reverse_iterator String::rbegin() const noexcept
        {
            return std::rbegin(this->pimpl->m_data);
        }
        
    

        /***************************************************************//**
        * @brief  This method returns a const reverse iterator to the end of 
        *         the string. 
        * @return A const reverse iterator to the end of the string. 
        *******************************************************************/
        std::string::const_reverse_iterator String::crbegin() const noexcept
        {
            return std::crbegin(this->pimpl->m_data);
        }


        /***************************************************************//**
        * @brief  This method returns an iterator to one past the end of 
        *         the string. 
        * @return An iterator to one past the end of the string. 
        *******************************************************************/
        std::string::iterator String::end() noexcept
        {
            return std::end(this->pimpl->m_data);
        }


        /***************************************************************//**
        * @brief  This method returns a const iterator to one past the end of 
        *         the string. 
        * @return A const iterator to one past the end of the string. 
        *******************************************************************/
        std::string::const_iterator String::end() const noexcept
        {
            return std::end(this->pimpl->m_data);
        }
        
        
        /***************************************************************//**
        * @brief  This method returns a const iterator to one past the end of 
        *         the string. 
        * @return A const iterator to one past the end of the string. 
        *******************************************************************/
        std::string::const_iterator String::cend() const noexcept
        {
            return std::cend(this->pimpl->m_data);
        }
        
        /***************************************************************//**
        * @brief  This method returns a reverse iterator to one past the end of 
        *         the string. 
        * @return A reverse iterator to one past the end of the string. 
        *******************************************************************/
        std::string::reverse_iterator String::rend() noexcept
        {
            return std::rend(this->pimpl->m_data);
        }


        /***************************************************************//**
        * @brief  This method returns a const reverse iterator to one past 
        *         the end of the string. 
        * @return A const reverse iterator to one past the end of the string. 
        *******************************************************************/
        std::string::const_reverse_iterator String::rend() const noexcept
        {
            return std::rend(this->pimpl->m_data);
        }
        
        
        /***************************************************************//**
        * @brief  This method returns a const reverse iterator to one past 
        *         the end of the string. 
        * @return A const reverse iterator to one past the end of the string. 
        *******************************************************************/
        std::string::const_reverse_iterator String::crend() const noexcept
        {
            return std::crend(this->pimpl->m_data);
        }


        /***************************************************************//**
        * @brief  Not equal to operator
        * @param  data is a String object that will be checked to see if 
        *         it is not equal to the this object.
        * @return True if data is not equal to the this object and false
        *         otherwise.
        *******************************************************************/
        bool String::operator!=(const String &data) const
        {
          assert(pimpl != nullptr);
          return this->pimpl->m_data != data.pimpl->m_data;
        }


        /***************************************************************//**
        * @brief  Addition operator
        * @param  data is a String object that will be added to the this 
        *         object. 
        * @return A string that is equal to data concatinated to the this
        *         object.
        *******************************************************************/
        GU::Core::String String::operator+(const String &data) const
        {
          assert(pimpl != nullptr);
          return this->pimpl->m_data + data.pimpl->m_data;
        }


        /***************************************************************//**
        * @brief  Concatinate operator
        * @param  data is a String object that will be concatinated to the 
        *         this object. 
        * @return A a reference to this object. 
        *******************************************************************/
        GU::Core::String& String::operator+=(const String &data)
        {
          assert(pimpl != nullptr);
          this->pimpl->m_data += data.pimpl->m_data;
          return *this;
        }


        /***************************************************************//**
        * @brief  This method returns the number of characters in the
        *         string
        * @return The number of characters in the string
        *******************************************************************/
        std::size_t String::size() const
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.size();
        }


        /***************************************************************//**
        * @brief  This method returns the number of characters in the
        *         string.
        * @return The number of characters in the string.
        *******************************************************************/
        std::size_t String::length() const
        {
          assert(pimpl != nullptr);
          return this->size();
        }


        /***************************************************************//**
        * @brief  This method returns a pointer to the beginning of the 
        *         string data. 
        * @return A char pointer equal to the String object.
        *******************************************************************/
        const char * String::c_str() const
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.c_str();
        }


        /***************************************************************//**
        * @brief  This method returns a std::string equal to the this object.
        * @return A string equal to the this object. 
        *******************************************************************/
        std::string String::toStdString() const
        {
          assert(pimpl != nullptr);
          return pimpl->m_data;
        }


        /***************************************************************//**
        * @brief This method removes all characters from the string
        *******************************************************************/
        void String::clear() noexcept
        {
          assert(pimpl != nullptr);
          pimpl->m_data.clear();
        }


        /***************************************************************//**
        * @brief  This method returns a boolean true value when the
        *         string is empty.
        * @return A boolean true if the string is empty and false otherwise.
        *******************************************************************/
        bool String::empty() const
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.empty();
        }


        /***************************************************************//**
        * @brief This method changes the size of the string.
        * @param n is the new size of the string
        *******************************************************************/
        void String::resize (size_t n)
        {
          assert(pimpl != nullptr);
          pimpl->m_data.resize(n);
        }


        /***************************************************************//**
        * @brief This method changes the size of the string.
        * @param n is the new size of the string
        * @param c if the new size is bigger the new characters will
        *        be initialized to this value.
        *******************************************************************/
        void String::resize (size_t n, char c)
        {
          assert(pimpl != nullptr);
          pimpl->m_data.resize(n, c);
        }


        /***************************************************************//**
        * @brief  This method changes the capacity of the string.
        *         capacity is the number of characters the string
        *         can hold.
        * @return The current capacity of the string
        *******************************************************************/
        size_t String::capacity() const
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.capacity();
        }


        /***************************************************************//**
        * @brief  This method returns a caracter at the given position
        *         in the string.
        * @param  pos The position of the caracter ot be returned.
        * @return The character at the position passed to pos.
        *******************************************************************/
        char& String::operator[] (size_t pos)
        {
          assert(pimpl != nullptr);
          return pimpl->m_data[pos];
        }


        /***************************************************************//**
        * @brief  This method returns a caracter at the given position
        *         in the string.
        * @param  pos The position of the caracter ot be returned.
        * @return The character at the position passed to pos.
        *******************************************************************/
        const char& String::operator[] (size_t pos) const
        {
          assert(pimpl != nullptr);
          return pimpl->m_data[pos];
        }


        /***************************************************************//**
        * @brief  This method returns a caracter at the given position
        *         in the string. This method will throw an error if
        *         the character does not exist.
        * @param  pos The position of the caracter to be returned.
        * @return The character at the position passed to pos.
        *******************************************************************/
        char& String::at (size_t pos)
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.at(pos);
        }


        /***************************************************************//**
        * @brief  This method returns a caracter at the given position
        *         in the string. This method will throw an error if
        *         the character does not exist.
        * @param  pos The position of the caracter ot be returned.
        * @return The character at the position passed to pos.
        *******************************************************************/
        const char& String::at (size_t pos) const
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.at(pos);
        }


        /***************************************************************//**
        * @brief  This method returns the last character in the string
        * @return The last character in the string.
        *******************************************************************/
        char& String::back()
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.back();
        }


        /***************************************************************//**
        * @brief  This method returns the last character in the string
        * @return The last character in the string.
        *******************************************************************/
        const char& String::back() const
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.back();
        }


        /***************************************************************//**
        * @brief  This method returns the first character in the string
        * @return The first character in the string.
        *******************************************************************/
        char& String::front()
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.front();
        }


        /***************************************************************//**
        * @brief  This method returns the first character in the string
        * @return The first character in the string.
        *******************************************************************/
        const char& String::front() const
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.front();
        }


        /***************************************************************//**
        * @brief  This method appends the input string to the current
        *         string.
        * @param  str a string to be appended to the current string.
        * @return A reference to the updated string..
        *******************************************************************/
        String& String::operator+= (const std::string& str)
        {
          assert(pimpl != nullptr);
          pimpl->m_data += str;
          return *this;
        }


        /***************************************************************//**
        * @brief  This method appends the input string to the current
        *         string.
        * @param  s a string to be appended to the current string.
        * @return A reference to the updated string.
        *******************************************************************/
        String& String::operator+= (const char* s)
        {
          assert(pimpl != nullptr);
          pimpl->m_data += s;
          return *this;
        }


        /***************************************************************//**
        * @brief  This method appends the input string to the current
        *         string.
        * @param  c a string to be appended to the current string.
        * @return A reference to the updated string..
        *******************************************************************/
        String& String::operator+= (char c)
        {
          assert(pimpl != nullptr);
          pimpl->m_data += c;
          return *this;
        }


        /***************************************************************//**
        * @brief  This method appends the input string to the current
        *         string.
        * @param  str a string to be appended to the current string.
        * @return A reference to the updated string..
        *******************************************************************/
        String& String::append (const std::string& str)
        {
          assert(pimpl != nullptr);
          pimpl->m_data.append(str);
          return *this;
        }


        /***************************************************************//**
        * @brief  This method appends the input string to the current
        *         string.
        * @param  str a string to be appended to the current string.
        * @param  subpos the first character in str to be copied.
        * @param  sublen the length of the string to be copied from str
        * @return A reference to the updated string..
        *******************************************************************/
        String& String::append (const std::string& str, size_t subpos, size_t sublen)
        {
          assert(pimpl != nullptr);
          pimpl->m_data.append(str, subpos, sublen);
          return *this;
        }


        /***************************************************************//**
        * @brief  This method appends the input string to the current
        *         string.
        * @param  s a pointer to the string to be appended.
        * @return A reference to the updated string..
        *******************************************************************/
        String& String::append (const char* s)
        {
          assert(pimpl != nullptr);
          pimpl->m_data.append(s);
          return *this;
        }


        /***************************************************************//**
        * @brief  This method appends the input string to the current
        *         string.
        * @param  s a pointer to the string to be appended.
        * @param  n The number of characters to be appended.
        * @return A reference to the updated string.
        *******************************************************************/
        String& String::append (const char* s, size_t n)
        {
          assert(pimpl != nullptr);
          pimpl->m_data.append(s, n);
          return *this;
        }


        /***************************************************************//**
        * @brief  This method appends the character c n times to the
        *         current string.
        * @param  n is the number of characters to be appended.
        * @param  c the character to be appended.
        * @return A reference to the updated string..
        *******************************************************************/
        String& String::append (size_t n, char c)
        {
          assert(pimpl != nullptr);
          pimpl->m_data.append(n, c);
          return *this;
        }


        /***************************************************************//**
        * @brief  This method appends a string starting at first
        *         and ending at last to the current string.
        * @param  first iterator pointing to the first character to
        *         be appended.
        * @param  last iterator pointing to one past the last character
        *         in the string to be appended.
        * @return A reference to the updated string.
        ******************************************************************/
        template <class InputIterator>
        String& String::append (InputIterator first, InputIterator last)
        {
          assert(pimpl != nullptr);
          pimpl->m_data.append(first, last);
          return *this;
        }


        /**************************************************************//**
        * @brief This method adds a character to the end of the string.
        * @param c the character to be added.
        ******************************************************************/
        void String::push_back (char c)
        {
          assert(pimpl != nullptr);
          pimpl->m_data.push_back(c);
        }


        /**************************************************************//**
        * @brief  Replace the current string with a new string.
        * @param  str the string to be assigned.
        * @return A reference to the updated string.
        ******************************************************************/
        String& String::assign (const std::string& str)
        {
          assert(pimpl != nullptr);
          pimpl->m_data.assign(str);
          return *this;
        }


        /**************************************************************//**
        * @brief  Replace the current string with the substring of a
        *         new string.
        * @param  str the string to be assigned.
        * @param  subpos index to the beggining of the string in str.
        * @param  sublen the length of the substring.
        * @return A reference to the updated string.
        ******************************************************************/
        String& String::assign (const std::string& str, size_t subpos, size_t sublen)
        {
          assert(pimpl != nullptr);
          pimpl->m_data.assign(str, subpos, sublen);
          return *this;
        }


        /**************************************************************//**
        * @brief  Replace the current string with the new string.
        * @param  s the new string to be assigned.
        * @return A reference to the updated string.
        ******************************************************************/
        String& String::assign (const char* s)
        {
          assert(pimpl != nullptr);
          pimpl->m_data.assign(s);
          return *this;
        }


        /**************************************************************//**
        * @brief  Replace the current string with the new string.
        * @param  s the new string to be assigned.
        * @param  n the size of the new string.
        * @return A reference to the updated string.
        ******************************************************************/
        String& String::assign (const char* s, size_t n)
        {
          assert(pimpl != nullptr);
          pimpl->m_data.assign(s, n);
          return *this;
        }


        /**************************************************************//**
        * @brief  Replace the current string with n number of c characters.
        * @param  n the number of characters to be assigned.
        * @param  c the character to be assigned.
        * @return A reference to the updated string.
        ******************************************************************/
        String& String::assign (size_t n, char c)
        {
          assert(pimpl != nullptr);
          pimpl->m_data.assign(n, c);
          return *this;
        }


        /**************************************************************//**
        * @brief  Replace the current string with the string starting
        *         at first and ending at last
        * @param  first the first character in the string to be assigned.
        * @param  last the last character in the string to be assigned.
        * @return A reference to the updated string.
        ******************************************************************/
        template <class InputIterator>
        String& String::assign (InputIterator first, InputIterator last)
        {
          assert(pimpl != nullptr);
          pimpl->m_data.assign(first, last);
          return *this;
        }


        /**************************************************************//**
        * @brief This changes the strings capacity.
        * @param n the new capacity
        ******************************************************************/
        void String::reserve (size_t n)
        {
          assert(pimpl != nullptr);
          pimpl->m_data.reserve(n);
        }


        /**************************************************************//**
        * @brief Shrink the strings capacity to fit it's size.
        ******************************************************************/
        void String::shrink_to_fit()
        {
          assert(pimpl != nullptr);
          pimpl->m_data.shrink_to_fit();
        }


        /**************************************************************//**
        * @brief  Erase len characters starting at pos
        * @param  pos where to start erasing
        * @param  len the number of characters to be erased
        * @return A reference to the updated string.
        ******************************************************************/
        String& String::erase (size_t pos, size_t len)
        {
          assert(pimpl != nullptr);
          pimpl->m_data.erase(pos, len);
          return *this;
        }


        /**************************************************************//**
        * @brief  Erase all characters starting at p 
        * @param  p an iterator to the first erased character 
        * @return An iterator to the first erased charater or String::end()
        ******************************************************************/
        std::string::iterator String::erase (std::string::const_iterator p)
        {
            assert(pimpl != nullptr);
            return pimpl->m_data.erase(p);             
        }


        /**************************************************************//**
        * @brief  Erase all characters starting at first and ending at last. 
        * @param  first an iterator to the first erased character.
        * @param  last an iterator to the last erased character.
        * @return An iterator to the first erased charater or String::end()
        ******************************************************************/
        std::string::iterator String::erase (std::string::const_iterator first, std::string::const_iterator last)
        {
            assert(pimpl != nullptr);
            return pimpl->m_data.erase(first, last);             
        }


        /**************************************************************//**
        * @brief  Replace len characters starting at pos with str.
        * @param  pos where to start replacing.
        * @param  len the number of characters to be replaced.
        * @param  str the string to replace the substring with.
        * @return A reference to the updated string.
        ******************************************************************/
        String& String::replace (size_t pos, size_t len, const std::string& str)
        {
            assert(pimpl != nullptr);
            pimpl->m_data.replace(pos, len, str);
            return *this;
        }


        String& String::replace (std::string::const_iterator i1, std::string::const_iterator i2, const std::string& str)
        {
            assert(pimpl != nullptr);
            pimpl->m_data.replace(i1, i2, str);
            return *this;

        }
        



        /**************************************************************//**
        * @brief  Replace len characters starting at pos with the characters 
        *         in str starting at subpos  and ending at sublen.
        * @param  pos where to start replacing.
        * @param  len the number of characters to be replaced.
        * @param  str the string to get a substring from.
        * @param  subpos the start position of the substring.
        * @param  sublen the size of the substring.
        * @return A reference to the updated string.
        ******************************************************************/
        String& String::replace (size_t pos, size_t len, const std::string& str, size_t subpos, size_t sublen)
        {
          assert(pimpl != nullptr);
          pimpl->m_data.replace(pos, len, str, subpos, sublen);
          return *this;
        }


        /**************************************************************//**
        * @brief  Replace len characters starting at pos with s.
        * @param  pos where to start replacing.
        * @param  len the number of characters to be replaced.
        * @param  s the string used to replace the substring.
        * @return A reference to the updated string.
        ******************************************************************/
        String& String::replace (size_t pos, size_t len, const char* s)
        {
          assert(pimpl != nullptr);
          pimpl->m_data.replace(pos, len, s);
          return *this;
        }


        String& String::replace (std::string::const_iterator i1, std::string::const_iterator i2, const char* s)
        {
          assert(pimpl != nullptr);
          pimpl->m_data.replace(i1, i2, s);
          return *this;
        }


        /**********************************************************//**
        * @brief  Replace len characters starting at pos with n
        *         characters starting at s.
        * @param  pos where to start replacing.
        * @param  len the number of characters to be replaced.
        * @param  s the string used to replace the substring.
        * @param  n the lengh of the substring.
        * @return A reference to the updated string.
        **************************************************************/
        String& String::replace (size_t pos, size_t len, const char* s, size_t n)
        {
          assert(pimpl != nullptr);
          pimpl->m_data.replace(pos, len, s, n);
          return *this;
        }


        String& String::replace (std::string::const_iterator i1, std::string::const_iterator i2, const char* s, size_t n)
        {
          assert(pimpl != nullptr);
          pimpl->m_data.replace(i1, i2, s, n);
          return *this;
        }

        /**********************************************************//**
        * @brief  Replace len characters starting at pos with n
        *         characters of type c.
        * @param  pos where to start replacing.
        * @param  len the number of characters to be replaced.
        * @param  s the string used to replace the substring.
        * @param  n the lengh of the substring.
        * @param  c the character to fill with.
        * @return A reference to the updated string.
        **************************************************************/
        String& String::replace (size_t pos, size_t len, size_t n, char c)
        {
            assert(pimpl != nullptr);
            pimpl->m_data.replace(pos, len, n, c);
            return *this;
        }


        String& String::replace (std::string::const_iterator i1, std::string::const_iterator i2, size_t n, char c)
        {
            assert(pimpl != nullptr);
            pimpl->m_data.replace(i1, i2, n, c);
            return *this;
        }


        template <class InputIterator>
        String& String::replace (std::string::const_iterator i1, 
                                std::string::const_iterator i2, 
                                InputIterator first, 
                                InputIterator last)
        {
            assert(pimpl != nullptr);
            pimpl->m_data.replace(i1, i2, first, last);
            return *this;
        }

        String& String::replace (std::string::const_iterator i1, std::string::const_iterator i2, std::initializer_list<char> il)
        {
            assert(pimpl != nullptr);
            pimpl->m_data.replace(i1, i2, il);
            return *this;
        }


        /**********************************************************//**
        * @brief swap the characters in the current string with the
        *        characters in str.
        * @param str the string to swap the current string with
        **************************************************************/
        void String::swap (std::string& str)
        {
          assert(pimpl != nullptr);
          pimpl->m_data.swap(str);
        }


        /**********************************************************//**
        * @brief  Remove the last character in the string.
        **************************************************************/
        void String::pop_back()
        {
          assert(pimpl != nullptr);
          pimpl->m_data.pop_back();
        }


        /**********************************************************//**
        * @brief  Get the current string in c string form.
        * @return A pointer to the current string of data.
        **************************************************************/
        const char* String::data() const noexcept
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.data();
        }


        std::string::allocator_type String::get_allocator() const noexcept
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.get_allocator();
        }


        /**********************************************************//**
        * @brief  Copy a substring from the current string into s
        *         starting at position pos and ending at pos + len.
        * @param  s the pointer to store the copied string.
        * @param  len the number of characters to be copied.
        * @param  pos the position in the current string to start
        *         copying
        * @return The number of characters copied into s.
        **************************************************************/
        size_t String::copy (char* s, size_t len, size_t pos) const
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.copy(s, len, pos);
        }


        /**********************************************************//**
        * @brief  Find a string str in the current string
        *         starting at position pos.
        * @param  str the string to be found
        * @param  pos the position to start looking for str.
        * @return The position of the first character of the first match.
        *         in the current string or npos;
        **************************************************************/
        size_t String::find (const std::string& str, size_t pos) const noexcept
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.find(str, pos);
        }


        /**********************************************************//**
        * @brief  Find a string s in the current string
        *         starting at position pos.
        * @param  s the string to be found
        * @param  pos the position to start looking for str.
        * @return The position of the first character of the first match.
        *         in the current string or npos;
        **************************************************************/
        size_t String::find (const char* s, size_t pos) const
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.find(s, pos);
        }


        size_t String::find (const char* s, size_t pos, std::string::size_type n) const
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.find(s, pos, n);
        }


        /**********************************************************//**
        * @brief  Find a character c in the current string starting
        *         at position pos.
        * @param  c the character to be found
        * @param  pos the position to start looking for c.
        * @return The position of the first character of the first match.
        *         in the current string or npos;
        **************************************************************/
        size_t String::find (char c, size_t pos) const noexcept
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.find(c, pos);
        }


        /**********************************************************//**
        * @brief  Find the string at pos in reverse order.
        * @param  str the string to be found.
        * @param  pos the position to start looking for str.
        * @return The position of the first character of the first match.
        *         in the current string or npos;
        **************************************************************/
        size_t String::rfind (const std::string& str, size_t pos) const noexcept
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.rfind(str, pos);
        }


        /**********************************************************//**
        * @brief  Find the string s at pos in reverse order.
        * @param  s the string to be found.
        * @param  pos the position to start looking for str.
        * @return The position of the first character of the first match.
        *         in the current string or npos;
        **************************************************************/
        size_t String::rfind (const char* s, size_t pos) const
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.find(s, pos);
        }


        /**********************************************************//**
        * @brief  Find the string s at pos with length n in reverse order.
        * @param  s the string to be found.
        * @param  pos the position to start looking for str.
        * @param  n the length of the string.
        * @return The position of the first character of the first match.
        *         in the current string or npos;
        **************************************************************/
        size_t String::rfind (const char* s, size_t pos, size_t n) const
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.rfind(s, pos, n);
        }


        /**********************************************************//**
        * @brief  Find the character c at pos in reverse order.
        * @param  c the character to be found.
        * @param  pos the position to start looking for str.
        * @return The position of the first character of the first match.
        *         in the current string or npos;
        **************************************************************/
        size_t String::rfind (char c, size_t pos) const noexcept
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.rfind(c, pos);
        }


        /**********************************************************//**
        * @brief  Find the first character that matches any character
        *         in str.
        * @param  str the characters to search for
        * @param  pos the position to start looking for str.
        * @return The position of the first character of the first match.
        *         in the current string or npos;
        **************************************************************/
        size_t String::find_first_of (const std::string& str, size_t pos) const noexcept
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.find_first_of(str, pos);
        }


        /**********************************************************//**
        * @brief  Find the first character that matches any character
        *         in s.
        * @param  s the characters to search for
        * @param  pos the position to start looking for str.
        * @return The position of the first character of the first match.
        *         in the current string or npos;
        **************************************************************/
        size_t String::find_first_of (const char* s, size_t pos) const
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.find_first_of(s, pos);
        }


        /**********************************************************//**
        * @brief  Find the first character that matches any character
        *         in s starting at position pos and ending at position
        *         pos + n.
        * @param  s the characters to search for
        * @param  pos the position to start looking for str.
        * @param  n the lengh of the characters to look for
        * @return The position of the first character of the first match.
        *         in the current string or npos;
        **************************************************************/
        size_t String::find_first_of (const char* s, size_t pos, size_t n) const
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.find_first_of(s, pos, n);
        }


        /**********************************************************//**
        * @brief  Find the first instance of character c starting at
        *         position pos.
        * @param  c the character to search for
        * @param  pos the position to start looking for str.
        * @return The position of the first character of the first match.
        *         in the current string or npos;
        **************************************************************/
        size_t String::find_first_of (char c, size_t pos) const noexcept
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.find_first_of(c, pos);
        }


        /**********************************************************//**
        * @brief  Find the last instance of any character that matches
        *         any character in str starting at position pos.
        * @param  str the characters to search for
        * @param  pos the position to start looking for str.
        * @return The position of the first character of the first match.
        *         in the current string or npos;
        **************************************************************/
        size_t String::find_last_of (const std::string& str, size_t pos) const noexcept
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.find_last_of(str, pos);
        }


        /**********************************************************//**
        * @brief  Find the last instance of any character that matches
        *         a character in s starting at position pos.
        * @param  s the characters to search for
        * @param  pos the position to start looking for str.
        * @return The position of the first character of the first match.
        *         in the current string or npos;
        **************************************************************/
        size_t String::find_last_of (const char* s, size_t pos) const
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.find_last_of(s, pos);
        }


        /**********************************************************//**
        * @brief  Find the last instance of any character that matches
        *         a character in s starting at position pos and ending
        *         at pos + n.
        * @param  s the characters to search for
        * @param  pos the position to start looking for str.
        * @param  n the number of characters to search
        * @return The position of the first character of the first match.
        *         in the current string or npos;
        **************************************************************/
        size_t String::find_last_of (const char* s, size_t pos, size_t n) const
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.find_last_of(s, pos, n);
        }


        /**********************************************************//**
        * @brief  Find the last instance of character c starting
        *         at position pos.
        * @param  c the character to search for
        * @param  pos the position to start looking for c.
        * @return The position of the first character of the first match.
        *         in the current string or npos;
        **************************************************************/
        size_t String::find_last_of (char c, size_t pos) const noexcept
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.find_last_of(c, pos);
        }


        /**********************************************************//**
        * @brief  Find the first instance of any character not in str.
        *         starting at position pos.
        * @param  str the characters not to search for
        * @param  pos the position to start looking for str.
        * @return The position of the first character of the first match.
        *         in the current string or npos;
        **************************************************************/
        size_t String::find_first_not_of (const std::string& str, size_t pos) const noexcept
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.find_first_not_of(str, pos);
        }


        /**********************************************************//**
        * @brief  Find the first instance of any character not in s.
        *         starting at position pos.
        * @param  s the characters not to search for
        * @param  pos the position to start looking for str.
        * @return The position of the first character of the first match.
        *         in the current string or npos;
        **************************************************************/
        size_t String::find_first_not_of (const char* s, size_t pos) const
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.find_first_not_of(s, pos);
        }


        /**********************************************************//**
        * @brief  Find the first instance of any character not in s.
        *         starting at position pos and ending at pos + n.
        * @param  s the characters not to search for
        * @param  pos the position to start looking for s.
        * @param  n the number of characters to be searched
        * @return The position of the first character of the first match.
        *         in the current string or npos;
        **************************************************************/
        size_t String::find_first_not_of (const char* s, size_t pos, size_t n) const
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.find_first_not_of(s, pos, n);
        }


        /**********************************************************//**
        * @brief  Find the last instance of characte not in c.
        *         starting at position pos.
        * @param  c the characters not to search for
        * @param  pos the position to start looking for c.
        * @return The position of the first character of the first match.
        *         in the current string or npos;
        **************************************************************/
        size_t String::find_first_not_of (char c, size_t pos) const noexcept
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.find_first_not_of(c, pos);
        }


        /**********************************************************//**
        * @brief  Find the last instance of any character not in s.
        *         starting at position pos.
        * @param  s the characters not to search for
        * @param  pos the position to start looking for s.
        * @return The position of the first character of the first match.
        *         in the current string or npos;
        **************************************************************/
        size_t String::find_last_not_of (const std::string& str, size_t pos) const noexcept
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.find_last_not_of(str, pos);
        }


        /**********************************************************//**
        * @brief  Find the last instance of any character not in s.
        *         starting at position pos and ending at position pos + n.
        * @param  s the characters not to search for
        * @param  pos the position to start looking for s.
        * @param  n the max number of characters to be searched.
        * @return The position of the first character of the first match.
        *         in the current string or npos;
        **************************************************************/
        size_t String::find_last_not_of (const char* s, size_t pos) const
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.find_last_not_of(s, pos);
        }


        /**********************************************************//**
        * @brief  Find the last instance of any character not in s.
        *         starting at position pos and ending at position pos + n.
        * @param  s the characters not to search for
        * @param  pos the position to start looking for s.
        * @param  n the max number of characters to be searched.
        * @return The position of the first character of the first match.
        *         in the current string or npos;
        **************************************************************/
        size_t String::find_last_not_of (const char* s, size_t pos, size_t n) const
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.find_last_not_of(s, pos, n);
        }


        /**********************************************************//**
        * @brief  Find the last instance of any character other than c.
        *         starting at position pos .
        * @param  c the character not to search for
        * @param  pos the position to start looking for c.
        * @return The position of the first character of the first match.
        *         in the current string or npos;
        **************************************************************/
        size_t String::find_last_not_of (char c, size_t pos) const noexcept
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.find_last_not_of(c, pos);
        }


        /**********************************************************//**
        * @brief  Find a substring starting at position pos and
        *         ending at position pos + len .
        * @param  pos the position to start looking.
        * @param  len the max length of the substring.
        * @return The substring found.
        **************************************************************/
        String String::substr (size_t pos, size_t len) const
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.substr(pos, len);
        }

        
        /**********************************************************//**
        * @brief  This method compares the current string object 
        *         against the (str) parameter.
        * @param  str the string the current string will be compared to. 
        * @return 0 if the strings are equal 
        *         <0 if the value of the first character that does not
        *         match is lower or all characters match but (s) is
        *         shorter.
        *         >0 if the value of the first character that does not
        *         match is greater or all characters match but (s) is 
        *         longer. 
        **************************************************************/
        int String::compare (const std::string& str) const noexcept
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.compare(str);
        }


        /**********************************************************//**
        * @brief  This method compares a substring of the current 
        *         string object against the (str) parameter.
        * @param  pos the starting position of the substring in the 
        *         current string object. 
        * @param  len the length of the substring.
        * @param  str the string the current string will be compared to. 
        * @return 0 if the strings are equal 
        *         <0 if the value of the first character that does not
        *         match is lower or all characters match but (s) is
        *         shorter.
        *         >0 if the value of the first character that does not
        *         match is greater or all characters match but (s) is 
        *         longer. 
        **************************************************************/
        int String::compare (size_t pos, size_t len, const std::string& str) const
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.compare(pos, len, str);
        }


        /**********************************************************//**
        * @brief  This method compares a substring of the current 
        *         string object against a substring of the (str) 
        *         parameter.
        * @param  pos the starting position of the substring in the 
        *         current string object. 
        * @param  len the length of the substring.
        * @param  str the string the current string will be compared to. 
        * @param  subpos the starting postion of the substring in the 
        *         (str) object. 
        * @param  sublen the length of the substring in (str).
        * @return 0 if the strings are equal 
        *         <0 if the value of the first character that does not
        *         match is lower or all characters match but (s) is
        *         shorter.
        *         >0 if the value of the first character that does not
        *         match is greater or all characters match but (s) is 
        *         longer. 
        **************************************************************/
        int String::compare (size_t pos, size_t len, const std::string& str, size_t subpos, size_t sublen) const
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.compare(pos, len, str, subpos, sublen);
        }


        /**********************************************************//**
        * @brief  This method compares the current string object
        *         against string (s).
        * @param  s the string the current string will be compared to.
        * @return 0 if the strings are equal 
        *         <0 if the value of the first character that does not
        *         match is lower or all characters match but (s) is
        *         shorter.
        *         >0 if the value of the first character that does not
        *         match is greater or all characters match but (s) is 
        *         longer. 
        **************************************************************/
        int String::compare (const char* s) const
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.compare(s);
        }


        /**********************************************************//**
        * @brief  This method compares a substring of the current 
        *         string object starting at (pos) and ending at (pos) 
        *         + (len) against a string (s).
        * @param  pos the starting position of the substring in the 
        *         current string object. 
        * @param  len the length of the substring.
        * @param  s the string the current string will be compared to. 
        * @return 0 if the strings are equal 
        *         <0 if the value of the first character that does not
        *         match is lower or all characters match but (s) is
        *         shorter.
        *         >0 if the value of the first character that does not
        *         match is greater or all characters match but (s) is 
        *         longer. 
        **************************************************************/
        int String::compare (size_t pos, size_t len, const char* s) const
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.compare(pos, len, s);
        }


        /**********************************************************//**
        * @brief  This method compares a substring of the current 
        *         string object starting at (pos) and ending at (pos) 
        *         + (len) against a string (s) of size (n) 
        * @param  pos the starting position of the substring in the 
        *         current string object. 
        * @param  len the length of the substring.
        * @param  s the string the current string will be compared to. 
        * @param  n The size of the string the current string will be 
        *         compared to.
        * @return 0 if the strings are equal 
        *         <0 if the value of the first character that does not
        *         match is lower or all characters match but (s) is
        *         shorter.
        *         >0 if the value of the first character that does not
        *         match is greater or all characters match but (s) is 
        *         longer. 
        **************************************************************/
        int String::compare (size_t pos, size_t len, const char* s, size_t n) const
        {
          assert(pimpl != nullptr);
          return pimpl->m_data.compare(pos, len, s, n);
        }


        /**********************************************************//**
        * @brief Destructor.
        **************************************************************/
        String::~String()
        {
            if(pimpl != nullptr)
            {
                delete pimpl;
                pimpl = nullptr;
            }
        }
    }
}
