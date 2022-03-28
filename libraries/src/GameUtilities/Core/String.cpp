#include "GameUtilities/Core/String.h"
#include <limits>
#include <string>

namespace GU
{
    namespace Core
    {

      class String::impl
      {
        public:
          impl();
          virtual ~impl();
          std::string m_data;
          #ifdef MULTITHREAD
            mutable std::mutex eventQueueLock;
          #endif
      };


        std::size_t String::npos = std::numeric_limits<std::size_t>::max();


        /**************************************************************
        * @brief: Constructor
        * @param: data is a string of characters
        **************************************************************/
        String::String(const String &data)
        {
          pimpl->m_data = data.pimpl->m_data;
        }


        /**************************************************************
        * @brief: Constructor
        * @param: data is a string of characters
        **************************************************************/
        String::String(const std::string &data)
        {
            pimpl->m_data.insert(0, data.c_str(), sizeof(data.c_str()));
        }


        /**************************************************************
        * @brief: Constructor
        * @param: data is a string of characters
        **************************************************************/
        String::String(const char* data)
        {
              pimpl->m_data.insert(0, data, sizeof(data));
        }


        /**************************************************************
        * @brief: Deep copy assignment operator
        * @param: data is a string of characters
        **************************************************************/
        String String::operator=(const String &data)
        {
          pimpl->m_data.resize(0);
          for(std::size_t i = 0; i < data.pimpl->m_data.size(); ++i)
          {
            pimpl->m_data.push_back(data.pimpl->m_data[i]);
          }

          return pimpl->m_data;
        }


        /**************************************************************
        * @brief: Equality operator
        * @param: data is a string of characters
        **************************************************************/
        bool String::operator==(const String &data)
        {
          return this->pimpl->m_data == data.pimpl->m_data;
        }


        /**************************************************************
        * @brief: Less then equal
        * @param: data is a string of characters
        **************************************************************/
        bool String::operator<=(const String &data)
        {
          return this->pimpl->m_data <= data.pimpl->m_data;
        }


        /**************************************************************
        * @brief: Greater then equal
        * @param: data is a string of characters
        **************************************************************/
        bool String::operator>=(const String &data)
        {
          return this->pimpl->m_data >= data.pimpl->m_data;
        }


        /**************************************************************
        * @brief: Not equal
        * @param: data is a string of characters
        **************************************************************/
        bool String::operator!=(const String &data)
        {
          return this->pimpl->m_data != data.pimpl->m_data;
        }


        /**************************************************************
        * @brief: This method returns the number of characters in the
        *         string
        * @return: The number of characters in the string
        **************************************************************/
        std::size_t String::size() const
        {
            return pimpl->m_data.size();
        }


        /**************************************************************
        * @brief: This method returns the number of characters in the
        *         string
        * @return: The number of characters in the string
        **************************************************************/
        std::size_t String::length() const
        {
          return this->size();
        }


        /**************************************************************
        * @brief: This method returns the number of characters in the
        *         string
        * @return: The number of characters in the string
        **************************************************************/
        const char * String::c_str() const
        {
          return pimpl->m_data.c_str();
        }


        /**************************************************************
        * @brief: This method returns an std::string equal to the
        *         current string value.
        * @return: A string of characters equal to the current string
        *          value.
        **************************************************************/
        std::string String::toStdString() const
        {
          return pimpl->m_data;
        }


        /**************************************************************
        * @brief: This method removes all characters from the string
        **************************************************************/
        void String::clear() noexcept
        {
          pimpl->m_data.clear();
        }


        /**************************************************************
        * @brief:  This method returns a boolean true value when the
        *          string is empty.
        * @return: A boolean true if the string is empty.
        **************************************************************/
        bool String::empty() const
        {
          return pimpl->m_data.empty();
        }


        /**************************************************************
        * @brief:  This method changes the size of the string.
        * @param:  n is the new size of the string
        **************************************************************/
        void String::resize (size_t n)
        {
          pimpl->m_data.resize(n);
        }


        /**************************************************************
        * @brief:  This method changes the size of the string.
        * @param:  n is the new size of the string\
        * @param:  c if the new size is bigger the new characters will
        *          be initialized to this value.
        **************************************************************/
        void String::resize (size_t n, char c)
        {
          pimpl->m_data.resize(n, c);
        }


        /**************************************************************
        * @brief:  This method changes the capacity of the string.
        *          capacity is the number of characters the string
        *          can hold.
        * @return: The current capacity of the string
        **************************************************************/
        size_t String::capacity() const
        {
          return pimpl->m_data.capacity();
        }


        /**************************************************************
        * @brief:  This method returns a caracter at the given position
        *          in the string.
        * @param:  pos The position of the caracter ot be returned.
        * @return: The character at the position passed to pos.
        **************************************************************/
        char& String::operator[] (size_t pos)
        {
          return pimpl->m_data[pos];
        }


        /**************************************************************
        * @brief:  This method returns a caracter at the given position
        *          in the string.
        * @param:  pos The position of the caracter ot be returned.
        * @return: The character at the position passed to pos.
        **************************************************************/
        const char& String::operator[] (size_t pos) const
        {
          return pimpl->m_data[pos];
        }


        /**************************************************************
        * @brief:  This method returns a caracter at the given position
        *          in the string.
        * @param:  pos The position of the caracter ot be returned.
        * @return: The character at the position passed to pos.
        **************************************************************/
        char& String::at (size_t pos)
        {
          return pimpl->m_data.at(pos);
        }


        /**************************************************************
        * @brief:  This method returns a caracter at the given position
        *          in the string.
        * @param:  pos The position of the caracter ot be returned.
        * @return: The character at the position passed to pos.
        **************************************************************/
        const char& String::at (size_t pos) const
        {
          return pimpl->m_data.at(pos);
        }


        /**************************************************************
        * @brief:  This method returns the last character in the string
        * @return: The last character in the string.
        **************************************************************/
        char& String::back()
        {
          return pimpl->m_data.back();
        }


        /**************************************************************
        * @brief:  This method returns the last character in the string
        * @return: The last character in the string.
        **************************************************************/
        const char& String::back() const
        {
          return pimpl->m_data.back();
        }


        /**************************************************************
        * @brief:  This method returns the first character in the string
        * @return: The first character in the string.
        **************************************************************/
        char& String::front()
        {
          return pimpl->m_data.front();
        }


        /**************************************************************
        * @brief:  This method returns the first character in the string
        * @return: The first character in the string.
        **************************************************************/
        const char& String::front() const
        {
          return pimpl->m_data.front();
        }


        /**************************************************************
        * @brief:  This method appends the input string to the current
        *          string.
        * @param:  str a string to be appended to the current string.
        * @return: A reference to the updated string..
        **************************************************************/
        String& String::operator+= (const std::string& str)
        {
          pimpl->m_data += str;
          return *this;
        }


        /**************************************************************
        * @brief:  This method appends the input string to the current
        *          string.
        * @param:  s a string to be appended to the current string.
        * @return: A reference to the updated string..
        **************************************************************/
        String& String::operator+= (const char* s)
        {
          pimpl->m_data += s;
          return *this;
        }


        /**************************************************************
        * @brief:  This method appends the input string to the current
        *          string.
        * @param:  c a string to be appended to the current string.
        * @return: A reference to the updated string..
        **************************************************************/
        String& String::operator+= (char c)
        {
          pimpl->m_data += c;
          return *this;
        }


        /**************************************************************
        * @brief:  This method appends the input string to the current
        *          string.
        * @param:  str a string to be appended to the current string.
        * @return: A reference to the updated string..
        **************************************************************/
        String& String::append (const std::string& str)
        {
          pimpl->m_data.append(str);
          return *this;
        }


        /**************************************************************
        * @brief:  This method appends the input string to the current
        *          string.
        * @param:  str a string to be appended to the current string.
        * @param:  subpos the first character in str to be copied.
        * @param:  sublen the length of the string to be copied from str
        * @return: A reference to the updated string..
        **************************************************************/
        String& String::append (const std::string& str, size_t subpos, size_t sublen)
        {
          pimpl->m_data.append(str, subpos, sublen);
          return *this;
        }


        /**************************************************************
        * @brief:  This method appends the input string to the current
        *          string.
        * @param:  s a pointer to the string to be appended.
        * @return: A reference to the updated string..
        **************************************************************/
        String& String::append (const char* s)
        {
          pimpl->m_data.append(s);
          return *this;
        }


        /**************************************************************
        * @brief:  This method appends the character c n times to the
        *          current string.
        * @param:  n is the number of characters to be appended.
        * @param:  c the character to be appended.
        * @return: A reference to the updated string..
        **************************************************************/
        String& String::append (const char* s, size_t n)
        {
          pimpl->m_data.append(s, n);
          return *this;
        }


        /**************************************************************
        * @brief:  This method appends the character c n times to the
        *          current string.
        * @param:  n is the number of characters to be appended.
        * @param:  c the character to be appended.
        * @return: A reference to the updated string..
        **************************************************************/
        String& String::append (size_t n, char c)
        {
          pimpl->m_data.append(n, c);
          return *this;
        }


        /**************************************************************
        * @brief:  This method appends a string starting at first
        *          and ending at last to the current string.
        * @param:  first iterator pointing to the first character to
        *          be appended.
        * @param:  last iterator pointing to one past the last character
        *          in the string to be appended.
        * @return: A reference to the updated string..
        **************************************************************/
        template <class InputIterator>
        String& String::append (InputIterator first, InputIterator last)
        {
          pimpl->m_data.append(first, last);
          return *this;
        }


        /**************************************************************
        * @brief:  This method adds a character to the end of the string.
        * @param:  c the character to be added.
        * @return: A reference to the updated string.
        **************************************************************/
        void String::push_back (char c)
        {
          pimpl->m_data.push_back(c);
        }


        /**************************************************************
        * @brief:  Replace the current string with a new string.
        * @param:  str the string to be assigned.
        * @return: A reference to the updated string.
        **************************************************************/
        String& String::assign (const std::string& str)
        {
          pimpl->m_data.assign(str);
          return *this;
        }


        /**************************************************************
        * @brief:  Replace the current string with the substring of a
        *          new string.
        * @param:  str the string to be assigned.
        * @param:  subpos index to the beggining of the string in str.
        * @param:  sublen the length of the substring.
        * @return: A reference to the updated string.
        **************************************************************/
        String& String::assign (const std::string& str, size_t subpos, size_t sublen)
        {
          pimpl->m_data.assign(str, subpos, sublen);
          return *this;
        }


        /**************************************************************
        * @brief:  Replace the current string with the new string.
        * @param:  s the new string to be assigned.
        * @return: A reference to the updated string.
        **************************************************************/
        String& String::assign (const char* s)
        {
          pimpl->m_data.assign(s);
          return *this;
        }


        /**************************************************************
        * @brief:  Replace the current string with the new string.
        * @param:  s the new string to be assigned.
        * @param:  n the size of the new string.
        * @return: A reference to the updated string.
        **************************************************************/
        String& String::assign (const char* s, size_t n)
        {
          pimpl->m_data.assign(s, n);
          return *this;
        }


        /**************************************************************
        * @brief:  Replace the current string with n number of c characters.
        * @param:  n the number of characters to be assigned.
        * @param:  c the character to be assigned.
        * @return: A reference to the updated string.
        **************************************************************/
        String& String::assign (size_t n, char c)
        {
          pimpl->m_data.assign(n, c);
          return *this;
        }


        /**************************************************************
        * @brief:  Replace the current string with the string starting
        *          at first and ending at last
        * @param:  first the first character in the string to be assigned.
        * @param:  last the last character in the string to be assigned.
        * @return: A reference to the updated string.
        **************************************************************/
        template <class InputIterator>
        String& String::assign (InputIterator first, InputIterator last)
        {
          pimpl->m_data.assign(first, last);
          return *this;
        }


        /**************************************************************
        * @brief:  This changes the strings capacity.
        * @param:  n the new capacity
        **************************************************************/
        void String::reserve (size_t n)
        {
          pimpl->m_data.reserve(n);
        }


        /**************************************************************
        * @brief:  Shring the strings capacity to fit it's size.
        **************************************************************/
        void String::shrink_to_fit()
        {
          pimpl->m_data.shrink_to_fit();
        }


        /**************************************************************
        * @brief:  Erase len characters starting at pos
        * @param:  pos where to start erasing
        * @param:  len the number of characters to be erased
        * @return: A reference to the updated string.
        **************************************************************/
        String& String::erase (size_t pos, size_t len)
        {
          pimpl->m_data.erase(pos, len);
          return *this;
        }


        //iterator String::erase (const_iterator p)
        //{

        //}


        //iterator String::erase (const_iterator first, const_iterator last)
        //{

        //}


        /**************************************************************
        * @brief:  Replace len characters starting at pos with str.
        * @param:  pos where to start replacing.
        * @param:  len the number of characters to be replaced.
        * @param:  str the string to replace the substring with.
        * @return: A reference to the updated string.
        **************************************************************/
        String& String::replace (size_t pos, size_t len, const std::string& str)
        {
          pimpl->m_data.replace(pos, len, str);
          return *this;
        }


        //String& String::replace (const_iterator i1, const_iterator i2, const string& str)
        //{

        //}


        /**************************************************************
        * @brief:  Replace len characters starting at pos with the
        *          characters in str starting at subpos  and ending
        *          at sublen.
        * @param:  pos where to start replacing.
        * @param:  len the number of characters to be replaced.
        * @param:  str the string to get a substring from.
        * @param:  subpos the start position of the substring.
        * @param:  sublen the size of the substring.
        * @return: A reference to the updated string.
        **************************************************************/
        String& String::replace (size_t pos, size_t len, const std::string& str, size_t subpos, size_t sublen)
        {
          pimpl->m_data.replace(pos, len, str, subpos, sublen);
          return *this;
        }


        /**************************************************************
        * @brief:  Replace len characters starting at pos with s.
        * @param:  pos where to start replacing.
        * @param:  len the number of characters to be replaced.
        * @param:  s the string used to replace the substring.
        * @return: A reference to the updated string.
        **************************************************************/
        String& String::replace (size_t pos, size_t len, const char* s)
        {
          pimpl->m_data.replace(pos, len, s);
          return *this;
        }


        //String& String::replace (const_iterator i1, const_iterator i2, const char* s)
        //{

        //}


        /**************************************************************
        * @brief:  Replace len characters starting at pos with n
        *          characters starting at s.
        * @param:  pos where to start replacing.
        * @param:  len the number of characters to be replaced.
        * @param:  s the string used to replace the substring.
        * @param:  n the lengh of the substring.
        * @return: A reference to the updated string.
        **************************************************************/
        String& String::replace (size_t pos, size_t len, const char* s, size_t n)
        {
          pimpl->m_data.replace(pos, len, s, n);
          return *this;
        }


        //String& String::replace (const_iterator i1, const_iterator i2, const char* s, size_t n)
        //{

      //  }

        /**************************************************************
        * @brief:  Replace len characters starting at pos with n
        *          characters of type c.
        * @param:  pos where to start replacing.
        * @param:  len the number of characters to be replaced.
        * @param:  s the string used to replace the substring.
        * @param:  n the lengh of the substring.
        * @param:  c the character to fill with.
        * @return: A reference to the updated string.
        **************************************************************/
        String& String::replace (size_t pos, size_t len, size_t n, char c)
        {
          pimpl->m_data.replace(pos, len, n, c);
          return *this;
        }


        //String& String::replace (const_iterator i1, const_iterator i2, size_t n, char c)
        //{

        //}


        //template <class InputIterator>
        //String& String::replace (const_iterator i1, const_iterator i2, InputIterator first, InputIterator last)
      //  {

        //}

        //String& String::replace (const_iterator i1, const_iterator i2, initializer_list<char> il)
        //{

        //}


        /**************************************************************
        * @brief:  swap the characters in the current string with the
        *          characters in str.
        * @param:  str the string to swap the current string with
        **************************************************************/
        void String::swap (std::string& str)
        {
          pimpl->m_data.swap(str);
        }


        /**************************************************************
        * @brief:  Remove the last character in the string.
        **************************************************************/
        void String::pop_back()
        {
          pimpl->m_data.pop_back();
        }


        /**************************************************************
        * @brief:  Get the current string in c string form.
        * @return: A pointer to the current string of data.
        **************************************************************/
        const char* String::data() const noexcept
        {
          return pimpl->m_data.data();
        }


        //allocator_type String::get_allocator() const noexcept
        //{

        //}


        /**************************************************************
        * @brief:  Copy a substring from the current string into s
        *          starting at position pos and ending at pos + len.
        * @param:  s the pointer to store the copied string.
        * @param:  len the number of characters to be copied.
        * @param:  pos the position in the current string to start
        *          copying
        * @return: The number of characters copied into s.
        **************************************************************/
        size_t String::copy (char* s, size_t len, size_t pos) const
        {
          return pimpl->m_data.copy(s, len, pos);
        }


        /**************************************************************
        * @brief:  Find a string str in the current string
        *          starting at position pos.
        * @param:  str the string to be found
        * @param:  pos the position to start looking for str.
        * @return: The position of the first character of the first match.
        *          in the current string or npos;
        **************************************************************/
        size_t String::find (const std::string& str, size_t pos) const noexcept
        {
          return pimpl->m_data.find(str, pos);
        }


        /**************************************************************
        * @brief:  Find a string s in the current string
        *          starting at position pos.
        * @param:  s the string to be found
        * @param:  pos the position to start looking for str.
        * @return: The position of the first character of the first match.
        *          in the current string or npos;
        **************************************************************/
        size_t String::find (const char* s, size_t pos) const
        {
          return pimpl->m_data.find(s, pos);
        }


        //size_t String::find (const char* s, size_t pos, size_type n) const
        //{

        //}


        /**************************************************************
        * @brief:  Find a character c in the current string starting
        *          at position pos.
        * @param:  c the character to be found
        * @param:  pos the position to start looking for c.
        * @return: The position of the first character of the first match.
        *          in the current string or npos;
        **************************************************************/
        size_t String::find (char c, size_t pos) const noexcept
        {
          return pimpl->m_data.find(c, pos);
        }


        /**************************************************************
        * @brief:  Find the string at pos in reverse order.
        * @param:  str the string to be found.
        * @param:  pos the position to start looking for str.
        * @return: The position of the first character of the first match.
        *          in the current string or npos;
        **************************************************************/
        size_t String::rfind (const std::string& str, size_t pos) const noexcept
        {
          return pimpl->m_data.rfind(str, pos);
        }


        /**************************************************************
        * @brief:  Find the string s at pos in reverse order.
        * @param:  s the string to be found.
        * @param:  pos the position to start looking for str.
        * @return: The position of the first character of the first match.
        *          in the current string or npos;
        **************************************************************/
        size_t String::rfind (const char* s, size_t pos) const
        {
          return pimpl->m_data.find(s, pos);
        }


        /**************************************************************
        * @brief:  Find the string s at pos with length n in reverse order.
        * @param:  s the string to be found.
        * @param:  pos the position to start looking for str.
        * @param:  n the length of the string.
        * @return: The position of the first character of the first match.
        *          in the current string or npos;
        **************************************************************/
        size_t String::rfind (const char* s, size_t pos, size_t n) const
        {
          return pimpl->m_data.rfind(s, pos, n);
        }


        /**************************************************************
        * @brief:  Find the character c at pos in reverse order.
        * @param:  c the character to be found.
        * @param:  pos the position to start looking for str.
        * @return: The position of the first character of the first match.
        *          in the current string or npos;
        **************************************************************/
        size_t String::rfind (char c, size_t pos) const noexcept
        {
          return pimpl->m_data.rfind(c, pos);
        }


        /**************************************************************
        * @brief:  Find the first character that matches any character
        *          in str.
        * @param:  str the characters to search for
        * @param:  pos the position to start looking for str.
        * @return: The position of the first character of the first match.
        *          in the current string or npos;
        **************************************************************/
        size_t String::find_first_of (const std::string& str, size_t pos) const noexcept
        {
          return pimpl->m_data.find_first_of(str, pos);
        }


        /**************************************************************
        * @brief:  Find the first character that matches any character
        *          in s.
        * @param:  s the characters to search for
        * @param:  pos the position to start looking for str.
        * @return: The position of the first character of the first match.
        *          in the current string or npos;
        **************************************************************/
        size_t String::find_first_of (const char* s, size_t pos) const
        {
          return pimpl->m_data.find_first_of(s, pos);
        }


        /**************************************************************
        * @brief:  Find the first character that matches any character
        *          in s starting at position pos and ending at position
        *          pos + n.
        * @param:  s the characters to search for
        * @param:  pos the position to start looking for str.
        * @param:  n the lengh of the characters to look for
        * @return: The position of the first character of the first match.
        *          in the current string or npos;
        **************************************************************/
        size_t String::find_first_of (const char* s, size_t pos, size_t n) const
        {
          return pimpl->m_data.find_first_of(s, pos, n);
        }


        /**************************************************************
        * @brief:  Find the first instance of character c starting at
        *          position pos.
        * @param:  c the character to search for
        * @param:  pos the position to start looking for str.
        * @return: The position of the first character of the first match.
        *          in the current string or npos;
        **************************************************************/
        size_t String::find_first_of (char c, size_t pos) const noexcept
        {
          return pimpl->m_data.find_first_of(c, pos);
        }


        /**************************************************************
        * @brief:  Find the last instance of any character that matches
        *          any character in str starting at position pos.
        * @param:  str the characters to search for
        * @param:  pos the position to start looking for str.
        * @return: The position of the first character of the first match.
        *          in the current string or npos;
        **************************************************************/
        size_t String::find_last_of (const std::string& str, size_t pos) const noexcept
        {
          return pimpl->m_data.find_last_of(str, pos);
        }


        /**************************************************************
        * @brief:  Find the last instance of any character that matches
        *          a character in s starting at position pos.
        * @param:  s the characters to search for
        * @param:  pos the position to start looking for str.
        * @return: The position of the first character of the first match.
        *          in the current string or npos;
        **************************************************************/
        size_t String::find_last_of (const char* s, size_t pos) const
        {
          return pimpl->m_data.find_last_of(s, pos);
        }


        /**************************************************************
        * @brief:  Find the last instance of any character that matches
        *          a character in s starting at position pos and ending
        *          at pos + n.
        * @param:  s the characters to search for
        * @param:  pos the position to start looking for str.
        * @param:  n the number of characters to search
        * @return: The position of the first character of the first match.
        *          in the current string or npos;
        **************************************************************/
        size_t String::find_last_of (const char* s, size_t pos, size_t n) const
        {
          return pimpl->m_data.find_last_of(s, pos, n);
        }


        /**************************************************************
        * @brief:  Find the last instance of character c starting
        *          at position pos.
        * @param:  c the character to search for
        * @param:  pos the position to start looking for c.
        * @return: The position of the first character of the first match.
        *          in the current string or npos;
        **************************************************************/
        size_t String::find_last_of (char c, size_t pos) const noexcept
        {
          return pimpl->m_data.find_last_of(c, pos);
        }


        /**************************************************************
        * @brief:  Find the first instance of any character not in str.
        *          starting at position pos.
        * @param:  str the characters not to search for
        * @param:  pos the position to start looking for str.
        * @return: The position of the first character of the first match.
        *          in the current string or npos;
        **************************************************************/
        size_t String::find_first_not_of (const std::string& str, size_t pos) const noexcept
        {
          return pimpl->m_data.find_first_not_of(str, pos);
        }


        /**************************************************************
        * @brief:  Find the first instance of any character not in s.
        *          starting at position pos.
        * @param:  s the characters not to search for
        * @param:  pos the position to start looking for str.
        * @return: The position of the first character of the first match.
        *          in the current string or npos;
        **************************************************************/
        size_t String::find_first_not_of (const char* s, size_t pos) const
        {
          return pimpl->m_data.find_first_not_of(s, pos);
        }


        /**************************************************************
        * @brief:  Find the first instance of any character not in s.
        *          starting at position pos and ending at pos + n.
        * @param:  s the characters not to search for
        * @param:  pos the position to start looking for s.
        * @param:  n the number of characters to be searched
        * @return: The position of the first character of the first match.
        *          in the current string or npos;
        **************************************************************/
        size_t String::find_first_not_of (const char* s, size_t pos, size_t n) const
        {
          return pimpl->m_data.find_first_not_of(s, pos, n);
        }


        /**************************************************************
        * @brief:  Find the last instance of characte not in c.
        *          starting at position pos.
        * @param:  c the characters not to search for
        * @param:  pos the position to start looking for c.
        * @return: The position of the first character of the first match.
        *          in the current string or npos;
        **************************************************************/
        size_t String::find_first_not_of (char c, size_t pos) const noexcept
        {
          return pimpl->m_data.find_first_not_of(c, pos);
        }


        /**************************************************************
        * @brief:  Find the last instance of any character not in s.
        *          starting at position pos.
        * @param:  s the characters not to search for
        * @param:  pos the position to start looking for s.
        * @return: The position of the first character of the first match.
        *          in the current string or npos;
        **************************************************************/
        size_t String::find_last_not_of (const std::string& str, size_t pos) const noexcept
        {
          return pimpl->m_data.find_last_not_of(str, pos);
        }


        /**************************************************************
        * @brief:  Find the last instance of any character not in s.
        *          starting at position pos and ending at position pos + n.
        * @param:  s the characters not to search for
        * @param:  pos the position to start looking for s.
        * @param:  n the max number of characters to be searched.
        * @return: The position of the first character of the first match.
        *          in the current string or npos;
        **************************************************************/
        size_t String::find_last_not_of (const char* s, size_t pos) const
        {
          return pimpl->m_data.find_last_not_of(s, pos);
        }


        /**************************************************************
        * @brief:  Find the last instance of any character not in s.
        *          starting at position pos and ending at position pos + n.
        * @param:  s the characters not to search for
        * @param:  pos the position to start looking for s.
        * @param:  n the max number of characters to be searched.
        * @return: The position of the first character of the first match.
        *          in the current string or npos;
        **************************************************************/
        size_t String::find_last_not_of (const char* s, size_t pos, size_t n) const
        {
          return pimpl->m_data.find_last_not_of(s, pos, n);
        }


        /**************************************************************
        * @brief:  Find the last instance of any character other than c.
        *          starting at position pos .
        * @param:  c the character not to search for
        * @param:  pos the position to start looking for c.
        * @return: The position of the first character of the first match.
        *          in the current string or npos;
        **************************************************************/
        size_t String::find_last_not_of (char c, size_t pos) const noexcept
        {
          return pimpl->m_data.find_last_not_of(c, pos);
        }


        /**************************************************************
        * @brief:  Find a substring starting at position pos and
        *          ending at position pos + len .
        * @param:  pos the position to start looking.
        * @param:  len the max length of the substring.
        * @return: The substring found.
        **************************************************************/
        String String::substr (size_t pos, size_t len) const
        {
          return pimpl->m_data.substr(pos, len);
        }

        int String::compare (const std::string& str) const noexcept
        {
          return pimpl->m_data.compare(str);
        }


        int String::compare (size_t pos, size_t len, const std::string& str) const
        {
          return pimpl->m_data.compare(pos, len, str);
        }


        int String::compare (size_t pos, size_t len, const std::string& str, size_t subpos, size_t sublen) const
        {
          return pimpl->m_data.compare(pos, len, str, subpos, sublen);
        }


        int String::compare (const char* s) const
        {
          return pimpl->m_data.compare(s);
        }


        int String::compare (size_t pos, size_t len, const char* s) const
        {
          return pimpl->m_data.compare(pos, len, s);
        }


        int String::compare (size_t pos, size_t len, const char* s, size_t n) const
        {
          return pimpl->m_data.compare(pos, len, s, n);
        }


        /**************************************************************
        * @brief: Destructor.
        **************************************************************/
        String::~String()
        {

        }
    }
}
