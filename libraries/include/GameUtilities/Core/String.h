#ifndef GAMEUTILITIES_STRING_H
#define GAMEUTILITIES_STRING_H
/*********************************************************************************//**
*	@author Wayne J Larson Jr.
*   @date   8/7/2021
*   @file   String.h
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
#include <cstring>
#include "core_export.h"
#include <string>
#include <iterator>
#include <initializer_list>

namespace GU
{
    namespace Core
    {
        /*********************************************************************************//**
        *   @class  String
        *   @brief  This class represents a string of characters.
        *************************************************************************************/
        class CORE_EXPORT String
        {
            public:
                /***************************************************************//**
                * @brief Constructor
                *******************************************************************/
                String();


                /***************************************************************//**
                * @brief Constructor
                * @param data is a string of characters
                *******************************************************************/
                String(const std::string &data);
                

                /***************************************************************//**
                * @brief Constructor
                * @param data is a pointer to a string of characters
                *******************************************************************/
                String(const char* data);

                
                /***************************************************************//**
                * @brief Copy constructor
                * @param data is the String object to be copied. 
                *******************************************************************/
                String(const String &data);


                /***************************************************************//**
                * @brief  This method allows the String to be cast to a const char* 
                * @return A pointer to the string of characters 
                *******************************************************************/
                operator const char*() const;
                
                /***************************************************************//**
                * @brief  copy assignment operator
                * @param  data is the String object to be copied. 
                * @return A copy of the updated string.
                *******************************************************************/
                String operator=(const String &data);

                
                /***************************************************************//**
                * @brief  assignment operator
                * @param  data is a pointer to the data to be assigned 
                * @return A copy of the updated string. 
                *******************************************************************/
                String operator=(const char* data);


                /***************************************************************//**
                * @brief  Equality operator
                * @param  data is a String object to be checked for equality. 
                * @return True if this object and the passed object are equal 
                *******************************************************************/
                bool operator==(const String &data) const;


                /***************************************************************//**
                * @brief  Equality operator
                * @param  data is a pointer to a string of characters to be checked
                *         against for equality. 
                * @return True if this object and the passed object are equal 
                *******************************************************************/
                bool operator==(const char* data) const;


                /***************************************************************//**
                * @brief  Less than or equal to operator 
                * @param  data is a String object to be checked if it is less than or 
                *         equal to this object. 
                * @return True if data is less than or equal to the this object
                *         and false otherwise. 
                *******************************************************************/
                bool operator<=(const String &data) const;


                /***************************************************************//**
                * @brief  Greater than or equal to operator
                * @param  data is a String object to be checked if it is greater
                *         than or equal to this object. 
                * @return True if data is greater than or equal to the this object. 
                *         and false otherwise
                *******************************************************************/
                bool operator>=(const String &data) const;


                /***************************************************************//**
                * @brief  Not equal to operator
                * @param  data is a String object that will be checked to see if 
                *         it is not equal to the this object.
                * @return True if data is not equal to the this object and false
                *         otherwise.
                *******************************************************************/
                bool operator!=(const String &data) const;


                /***************************************************************//**
                * @brief  Addition operator
                * @param  data is a String object that will be added to the this 
                *         object. 
                * @return A string that is equal to data concatinated to the this
                *         object.
                *******************************************************************/
                GU::Core::String operator+(const String &data) const;
                
                
                /***************************************************************//**
                * @brief  Concatinate operator
                * @param  data is a String object that will be concatinated to the 
                *         this object. 
                * @return A a reference to this object. 
                *******************************************************************/
                GU::Core::String& operator+=(const String &data);
                

                /***************************************************************//**
                * @brief  This method returns the number of characters in the
                *         string
                * @return The number of characters in the string
                *******************************************************************/
                std::size_t size() const;
                

                /***************************************************************//**
                * @brief  This method returns an iterator to the beginning of the
                *         string. 
                * @return An iterator to the beginning of the string. 
                *******************************************************************/
                std::string::iterator begin() noexcept;
                

                /***************************************************************//**
                * @brief  This method returns a const iterator to the beginning of 
                *         the string. 
                * @return An iterator to the beginning of the string. 
                *******************************************************************/
                std::string::const_iterator begin() const noexcept;
                

                /***************************************************************//**
                * @brief  This method returns a const iterator to the beginning of 
                *         the string. 
                * @return An iterator to the beginning of the string. 
                *******************************************************************/
                std::string::const_iterator cbegin() const noexcept;
                

                /***************************************************************//**
                * @brief  This method returns a reverse iterator to the end of 
                *         the string. 
                * @return A reverse iterator to the end of the string. 
                *******************************************************************/
                std::string::reverse_iterator rbegin() noexcept;
                

                /***************************************************************//**
                * @brief  This method returns a const reverse iterator to the end of 
                *         the string. 
                * @return A const reverse iterator to the end of the string. 
                *******************************************************************/
                std::string::const_reverse_iterator rbegin() const noexcept;
                

                /***************************************************************//**
                * @brief  This method returns a const reverse iterator to the end of 
                *         the string. 
                * @return A const reverse iterator to the end of the string. 
                *******************************************************************/
                std::string::const_reverse_iterator crbegin() const noexcept;
                

                /***************************************************************//**
                * @brief  This method returns an iterator to one past the end of 
                *         the string. 
                * @return An iterator to one past the end of the string. 
                *******************************************************************/
                std::string::iterator end() noexcept;
                

                /***************************************************************//**
                * @brief  This method returns a const iterator to one past the end of 
                *         the string. 
                * @return A const iterator to one past the end of the string. 
                *******************************************************************/
                std::string::const_iterator end() const noexcept;
                

                /***************************************************************//**
                * @brief  This method returns a const iterator to one past the end of 
                *         the string. 
                * @return A const iterator to one past the end of the string. 
                *******************************************************************/
                std::string::const_iterator cend() const noexcept;
                

                /***************************************************************//**
                * @brief  This method returns a reverse iterator to one past the end of 
                *         the string. 
                * @return A reverse iterator to one past the end of the string. 
                *******************************************************************/
                std::string::reverse_iterator rend() noexcept;
                

                /***************************************************************//**
                * @brief  This method returns a const reverse iterator to one past 
                *         the end of the string. 
                * @return A const reverse iterator to one past the end of the string. 
                *******************************************************************/
                std::string::const_reverse_iterator rend() const noexcept;
                
                
                /***************************************************************//**
                * @brief  This method returns a const reverse iterator to one past 
                *         the end of the string. 
                * @return A const reverse iterator to one past the end of the string. 
                *******************************************************************/
                std::string::const_reverse_iterator crend() const noexcept;
                

                /***************************************************************//**
                * @brief This method returns the number of characters in the
                *         string.
                * @return The number of characters in the string.
                *******************************************************************/
                std::size_t length() const;


                /***************************************************************//**
                * @brief  This method returns a pointer to the beginning of the 
                *         string data. 
                * @return A char pointer equal to the String object.
                *******************************************************************/
                const char * c_str() const;


                /***************************************************************//**
                * @brief This method returns a std::string equal to the this object.
                * @return A string equal to the this object. 
                *******************************************************************/
                std::string toStdString() const;


                /***************************************************************//**
                * @brief This method removes all characters from the string
                *******************************************************************/
                void clear() noexcept;


                /***************************************************************//**
                * @brief  This method returns a boolean true value when the
                *         string is empty.
                * @return A boolean true if the string is empty and false otherwise.
                *******************************************************************/
                bool empty() const;


                /***************************************************************//**
                * @brief  This method changes the size of the string.
                * @param  n is the new size of the string
                *******************************************************************/
                void resize (size_t n);


                /***************************************************************//**
                * @brief This method changes the size of the string.
                * @param n is the new size of the string
                * @param c if the new size is bigger the new characters will
                *        be initialized to this value.
                *******************************************************************/
                void resize (size_t n, char c);


                /***************************************************************//**
                * @brief  This method changes the capacity of the string.
                *         capacity is the number of characters the string
                *         can hold.
                * @return The current capacity of the string
                *******************************************************************/
                size_t capacity() const;


                /***************************************************************//**
                * @brief  This method returns a caracter at the given position
                *         in the string.
                * @param  pos The position of the caracter ot be returned.
                * @return The character at the position passed to pos.
                *******************************************************************/
                char& operator[] (size_t pos);


                /***************************************************************//**
                * @brief  This method returns a caracter at the given position
                *         in the string.
                * @param  pos The position of the caracter ot be returned.
                * @return The character at the position passed to pos.
                *******************************************************************/
                const char& operator[] (size_t pos) const;


                /***************************************************************//**
                * @brief  This method returns a caracter at the given position
                *         in the string. This method will throw an error if
                *         the character does not exist.
                * @param  pos The position of the caracter to be returned.
                * @return The character at the position passed to pos.
                *******************************************************************/
                char& at (size_t pos);


                /***************************************************************//**
                * @brief  This method returns a caracter at the given position
                *         in the string. This method will throw an error if
                *         the character does not exist.
                * @param  pos The position of the caracter ot be returned.
                * @return The character at the position passed to pos.
                *******************************************************************/
                const char& at (size_t pos) const;


                /***************************************************************//**
                * @brief  This method returns the last character in the string
                * @return The last character in the string.
                *******************************************************************/
                char& back();


                /***************************************************************//**
                * @brief  This method returns the last character in the string
                * @return The last character in the string.
                *******************************************************************/
                const char& back() const;


                /***************************************************************//**
                * @brief  This method returns the first character in the string
                * @return The first character in the string.
                *******************************************************************/
                char& front();


                /***************************************************************//**
                * @brief  This method returns the first character in the string
                * @return The first character in the string.
                *******************************************************************/
                const char& front() const;


                /***************************************************************//**
                * @brief  This method appends the input string to the current
                *         string.
                * @param  str a string to be appended to the current string.
                * @return A reference to the updated string..
                *******************************************************************/
                String& operator+= (const std::string& str);


                /***************************************************************//**
                * @brief  This method appends the input string to the current
                *         string.
                * @param  s a string to be appended to the current string.
                * @return A reference to the updated string.
                *******************************************************************/
                String& operator+= (const char* s);


                /***************************************************************//**
                * @brief  This method appends the input string to the current
                *         string.
                * @param  c a string to be appended to the current string.
                * @return A reference to the updated string..
                *******************************************************************/
                String& operator+= (char c);


                /***************************************************************//**
                * @brief  This method appends the input string to the current
                *         string.
                * @param  str a string to be appended to the current string.
                * @return A reference to the updated string..
                *******************************************************************/
                String& append (const std::string& str);


                /***************************************************************//**
                * @brief  This method appends the input string to the current
                *         string.
                * @param  str a string to be appended to the current string.
                * @param  subpos the first character in str to be copied.
                * @param  sublen the length of the string to be copied from str
                * @return A reference to the updated string..
                *******************************************************************/
                String& append (const std::string& str, size_t subpos, size_t sublen);


                /***************************************************************//**
                * @brief  This method appends the input string to the current
                *         string.
                * @param  s a pointer to the string to be appended.
                * @return A reference to the updated string..
                *******************************************************************/
                String& append (const char* s);


                /***************************************************************//**
                * @brief  This method appends the input string to the current
                *         string.
                * @param  s a pointer to the string to be appended.
                * @param  n The number of characters to be appended.
                * @return A reference to the updated string.
                *******************************************************************/
                String& append (const char* s, size_t n);


                /***************************************************************//**
                * @brief  This method appends the character c n times to the
                *         current string.
                * @param  n is the number of characters to be appended.
                * @param  c the character to be appended.
                * @return A reference to the updated string..
                *******************************************************************/
                String& append (size_t n, char c);


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
                String& append (InputIterator first, InputIterator last);


                /**************************************************************//**
                * @brief  This method adds a character to the end of the string.
                * @param  c the character to be added.
                ******************************************************************/
                void push_back (char c);


                /**************************************************************//**
                * @brief  Replace the current string with a new string.
                * @param  str the string to be assigned.
                * @return A reference to the updated string.
                ******************************************************************/
                String& assign (const GU::Core::String& str);


                /**************************************************************//**
                * @brief  Replace the current string with the substring of a
                *         new string.
                * @param  str the string to be assigned.
                * @param  subpos index to the beggining of the string in str.
                * @param  sublen the length of the substring.
                * @return A reference to the updated string.
                ******************************************************************/
                String& assign (const GU::Core::String& str, size_t subpos, size_t sublen);


                /**************************************************************//**
                * @brief  Replace the current string with the new string.
                * @param  s the new string to be assigned.
                * @return A reference to the updated string.
                ******************************************************************/
                String& assign (const char* s);


                /**************************************************************//**
                * @brief  Replace the current string with the new string.
                * @param  s the new string to be assigned.
                * @param  n the size of the new string.
                * @return A reference to the updated string.
                ******************************************************************/
                String& assign (const char* s, size_t n);


                /**************************************************************//**
                * @brief  Replace the current string with n number of c characters.
                * @param  n the number of characters to be assigned.
                * @param  c the character to be assigned.
                * @return A reference to the updated string.
                ******************************************************************/
                String& assign (size_t n, char c);


                /**************************************************************//**
                * @brief  Replace the current string with the string starting
                *         at first and ending at last
                * @param  first the first character in the string to be assigned.
                * @param  last the last character in the string to be assigned.
                * @return A reference to the updated string.
                ******************************************************************/
                template <class InputIterator>
                String& assign (InputIterator first, InputIterator last);

                GU::Core::String& assign (std::initializer_list<char> il);

                /**************************************************************//**
                * @brief  This changes the strings capacity.
                * @param  n the new capacity
                ******************************************************************/
                void reserve (size_t n = 0);


                /**************************************************************//**
                * @brief  Shrink the strings capacity to fit it's size.
                ******************************************************************/
                void shrink_to_fit();


                /**************************************************************//**
                * @brief  Erase len characters starting at pos
                * @param  pos where to start erasing
                * @param  len the number of characters to be erased
                * @return A reference to the updated string.
                ******************************************************************/
                String& erase (size_t pos = 0, size_t len = npos);
                

                /**************************************************************//**
                * @brief  Erase all characters starting at p 
                * @param  p an iterator to the first erased character 
                * @return An iterator to the first erased charater or String::end()
                ******************************************************************/
                std::string::iterator erase (std::string::const_iterator p);
                

                /**************************************************************//**
                * @brief  Erase all characters starting at first and ending at last. 
                * @param  first an iterator to the first erased character.
                * @param  last an iterator to the last erased character.
                * @return An iterator to the first erased charater or String::end()
                ******************************************************************/
                std::string::iterator erase (std::string::const_iterator first, std::string::const_iterator last);


                /**************************************************************//**
                * @brief  Replace len characters starting at pos with str.
                * @param  pos where to start replacing.
                * @param  len the number of characters to be replaced.
                * @param  str the string to replace the substring with.
                * @return A reference to the updated string.
                ******************************************************************/
                String& replace (size_t pos, size_t len, const std::string& str);


                
                /**************************************************************//**
                * @brief  Replace len characters starting at pos with str.
                * @param  pos where to start replacing.
                * @param  len the number of characters to be replaced.
                * @param  str the string to replace the substring with.
                * @return A reference to the updated string.
                ******************************************************************/
                String& replace (std::string::const_iterator i1, std::string::const_iterator i2, const std::string& str);


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
                String& replace (size_t pos, size_t len, const std::string& str, size_t subpos, size_t sublen);


                /**************************************************************//**
                * @brief  Replace len characters starting at pos with s.
                * @param  pos where to start replacing.
                * @param  len the number of characters to be replaced.
                * @param  s the string used to replace the substring.
                * @return A reference to the updated string.
                ******************************************************************/
                String& replace (size_t pos, size_t len, const char* s);
                String& replace (std::string::const_iterator i1, std::string::const_iterator i2, const char* s);


                /**********************************************************//**
                * @brief  Replace len characters starting at pos with n
                *         characters starting at s.
                * @param  pos where to start replacing.
                * @param  len the number of characters to be replaced.
                * @param  s the string used to replace the substring.
                * @param  n the lengh of the substring.
                * @return A reference to the updated string.
                **************************************************************/
                String& replace (size_t pos, size_t len, const char* s, size_t n);
                String& replace (std::string::const_iterator i1, std::string::const_iterator i2, const char* s, size_t n);


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
                String& replace (size_t pos, size_t len, size_t n, char c);
                String& replace (std::string::const_iterator i1, std::string::const_iterator i2, size_t n, char c);
                template <class InputIterator>
                String& replace (std::string::const_iterator i1, 
                                std::string::const_iterator i2, 
                                InputIterator first, 
                                InputIterator last);
                String& replace (std::string::const_iterator i1, std::string::const_iterator i2, std::initializer_list<char> il);


                /**********************************************************//**
                * @brief swap the characters in the current string with the
                *        characters in str.
                * @param str the string to swap the current string with
                **************************************************************/
                void swap (std::string& str);


                /**********************************************************//**
                * @brief Remove the last character in the string.
                **************************************************************/
                void pop_back();


                /**********************************************************//**
                * @brief  Get the current string in c string form.
                * @return A pointer to the current string of data.
                **************************************************************/
                const char* data() const noexcept;
                std::string::allocator_type get_allocator() const noexcept;


                /**********************************************************//**
                * @brief  Copy a substring from the current string into s
                *         starting at position pos and ending at pos + len.
                * @param  s the pointer to store the copied string.
                * @param  len the number of characters to be copied.
                * @param  pos the position in the current string to start
                *         copying
                * @return The number of characters copied into s.
                **************************************************************/
                size_t copy (char* s, size_t len, size_t pos = 0) const;


                /**********************************************************//**
                * @brief  Find a string str in the current string
                *         starting at position pos.
                * @param  str the string to be found
                * @param  pos the position to start looking for str.
                * @return The position of the first character of the first match.
                *         in the current string or npos;
                **************************************************************/
                size_t find (const std::string& str, size_t pos = 0) const noexcept;


                /**********************************************************//**
                * @brief  Find a string s in the current string
                *         starting at position pos.
                * @param  s the string to be found
                * @param  pos the position to start looking for s.
                * @return The position of the first character of the first match.
                *         in the current string or npos;
                **************************************************************/
                size_t find (const char* s, size_t pos = 0) const;
                size_t find (const char* s, size_t pos, std::string::size_type n) const;


                /**********************************************************//**
                * @brief  Find a character c in the current string starting
                *         at position pos.
                * @param  c the character to be found
                * @param  pos the position to start looking for c.
                * @return The position of the first character of the first match.
                *         in the current string or npos;
                **************************************************************/
                size_t find (char c, size_t pos = 0) const noexcept;

                /***********************************************************//**
                * @brief  Find the string str at pos in reverse order.
                * @param  str the string to be found.
                * @param  pos the position to start looking for str.
                * @return The position of the first character of the first match.
                *         in the current string or npos;
                **************************************************************/
                size_t rfind (const std::string& str, size_t pos = npos) const noexcept;


                /**********************************************************//**
                * @brief  Find the string s at pos in reverse order.
                * @param  s the string to be found.
                * @param  pos the position to start looking for s.
                * @return The position of the first character of the first match.
                *         in the current string or npos;
                **************************************************************/
                size_t rfind (const char* s, size_t pos = npos) const;


                /**********************************************************//**
                * @brief  Find the string s at pos with length n in reverse order.
                * @param  s the string to be found.
                * @param  pos the position to start looking for s.
                * @param  n the length of the string.
                * @return The position of the first character of the first match.
                *         in the current string or npos;
                **************************************************************/
                size_t rfind (const char* s, size_t pos, size_t n) const;


                /**********************************************************//**
                * @brief  Find the character c at pos in reverse order.
                * @param  c the character to be found.
                * @param  pos the position to start looking for c.
                * @return The position of the first character of the first match.
                *         in the current string or npos;
                **************************************************************/
                size_t rfind (char c, size_t pos = npos) const noexcept;


                /**********************************************************//**
                * @brief  Find the first character that matches any character
                *         in str.
                * @param  str the characters to search for
                * @param  pos the position to start looking for str.
                * @return The position of the first character of the first match.
                *         in the current string or npos;
                **************************************************************/
                size_t find_first_of (const std::string& str, size_t pos = 0) const noexcept;


                /**********************************************************//**
                * @brief  Find the first character that matches any character
                *         in s starting at position pos.
                * @param  s the characters to search for
                * @param  pos the position to start looking for s.
                * @return The position of the first character of the first match.
                *         in the current string or npos;
                **************************************************************/
                size_t find_first_of (const char* s, size_t pos = 0) const;


                /**********************************************************//**
                * @brief  Find the first character that matches any character
                *         in s starting at position pos and ending at position
                *         pos + n.
                * @param  s the characters to search for
                * @param  pos the position to start looking for s.
                * @param  n the number of the characters to search
                * @return The position of the first character of the first match.
                *         in the current string or npos;
                **************************************************************/
                size_t find_first_of (const char* s, size_t pos, size_t n) const;


                /**********************************************************//**
                * @brief  Find the first instance of character c starting at
                *         position pos.
                * @param  c the character to search for
                * @param  pos the position to start looking for c.
                * @return The position of the first character of the first match.
                *         in the current string or npos;
                **************************************************************/
                size_t find_first_of (char c, size_t pos = 0) const noexcept;


                /**********************************************************//**
                * @brief  Find the last instance of any character that matches
                *         a character in str starting at position pos.
                * @param  str the characters to search for
                * @param  pos the position to start looking for str.
                * @return The position of the first character of the first match.
                *         in the current string or npos;
                **************************************************************/
                size_t find_last_of (const std::string& str, size_t pos = npos) const noexcept;


                /**********************************************************//**
                * @brief  Find the last instance of any character that matches
                *         a character in s starting at position pos.
                * @param  s the characters to search for
                * @param  pos the position to start looking for s.
                * @return The position of the first character of the first match.
                *         in the current string or npos;
                **************************************************************/
                size_t find_last_of (const char* s, size_t pos = npos) const;


                /**********************************************************//**
                * @brief  Find the last instance of any character that matches
                *         a character in s starting at position pos and ending
                *         at pos + n.
                * @param  s the characters to search for
                * @param  pos the position to start looking for s.
                * @param  n the number of characters to search
                * @return The position of the first character of the first match.
                *         in the current string or npos;
                **************************************************************/
                size_t find_last_of (const char* s, size_t pos, size_t n) const;


                /**********************************************************//**
                * @brief  Find the last instance of character c starting
                *         at position pos.
                * @param  c the character to search for
                * @param  pos the position to start looking for c.
                * @return The position of the first character of the first match.
                *         in the current string or npos;
                **************************************************************/
                size_t find_last_of (char c, size_t pos = npos) const noexcept;


                /**********************************************************//**
                * @brief  Find the first instance of any character not in str.
                *         starting at position pos.
                * @param  str the characters not to search for
                * @param  pos the position to start looking for str.
                * @return The position of the first character of the first match.
                *         in the current string or npos;
                **************************************************************/
                size_t find_first_not_of (const std::string& str, size_t pos = 0) const noexcept;


                /**********************************************************//**
                * @brief  Find the first instance of any character not in s.
                *         starting at position pos.
                * @param  s the characters not to search for
                * @param  pos the position to start looking for s.
                * @return The position of the first character of the first match.
                *         in the current string or npos;
                **************************************************************/
                size_t find_first_not_of (const char* s, size_t pos = 0) const;


                /**********************************************************//**
                * @brief  Find the first instance of any character not in s.
                *         starting at position pos and ending at pos + n.
                * @param  s the characters not to search for
                * @param  pos the position to start looking for s.
                * @param  n the number of characters to be searched
                * @return The position of the first character of the first match.
                *         in the current string or npos;
                **************************************************************/
                size_t find_first_not_of (const char* s, size_t pos, size_t n) const;


                /**********************************************************//**
                * @brief  Find the first instance of characte not in c.
                *         starting at position pos.
                * @param  c the characters not to search for
                * @param  pos the position to start looking for c.
                * @return The position of the first character of the first match.
                *         in the current string or npos;
                **************************************************************/
                size_t find_first_not_of (char c, size_t pos = 0) const noexcept;


                /**********************************************************//**
                * @brief  Find the last instance of character not in c.
                *         starting at position pos.
                * @param  c the characters not to search for
                * @param  pos the position to start looking for c.
                * @return The position of the first character of the first match.
                *         in the current string or npos;
                **************************************************************/
                size_t find_last_not_of (const std::string& str, size_t pos = npos) const noexcept;


                /**********************************************************//**
                * @brief  Find the last instance of any character not in s.
                *         starting at position pos.
                * @param  s the characters not to search for
                * @param  pos the position to start looking for s.
                * @return The position of the first character of the first match.
                *         in the current string or npos;
                **************************************************************/
                size_t find_last_not_of (const char* s, size_t pos = npos) const;


                /**********************************************************//**
                * @brief  Find the last instance of any character not in s.
                *         starting at position pos and ending at position pos + n.
                * @param  s the characters not to search for
                * @param  pos the position to start looking for s.
                * @param  n the max number of characters to be searched.
                * @return The position of the first character of the first match.
                *         in the current string or npos;
                **************************************************************/
                size_t find_last_not_of (const char* s, size_t pos, size_t n) const;


                /**********************************************************//**
                * @brief  Find the last instance of any character other than c.
                *         starting at position pos .
                * @param  c the character not to search for
                * @param  pos the position to start looking for c.
                * @return The position of the first character of the first match.
                *         in the current string or npos;
                **************************************************************/
                size_t find_last_not_of (char c, size_t pos = npos) const noexcept;


                /**********************************************************//**
                * @brief  Find a substring starting at position pos and
                *         ending at position pos + len .
                * @param  pos the position to start looking.
                * @param  len the max length of the substring.
                * @return The substring found.
                **************************************************************/
                String substr (size_t pos = 0, size_t len = npos) const;

                
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
                int compare (const std::string& str) const noexcept;
                

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
                int compare (size_t pos, size_t len, const std::string& str) const;


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
                int compare (size_t pos, size_t len, const std::string& str, size_t subpos, size_t sublen) const;


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
                int compare (const char* s) const;
                

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
                int compare (size_t pos, size_t len, const char* s) const;
                

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
                int compare (size_t pos, size_t len, const char* s, size_t n) const;


                /**************************************************************
                * @brief: Destructor.
                **************************************************************/
                virtual ~String();

                static std::size_t npos;        /**< The maximum size of the string */
            private:
                typedef size_t size_type;       /**< The type used to define the size of the string  */
                class Impl;
                Impl* pimpl = nullptr;          /**< Pointer to implimentation */
        };

    }
}


#endif
