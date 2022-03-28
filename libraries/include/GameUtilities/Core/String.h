#ifndef GAMEUTILITIES_STRING_H
#define GAMEUTILITIES_STRING_H
#include <cstring>
#include "core_export.h"
#include <string>

namespace GU
{
    namespace Core
    {
        class CORE_EXPORT String
        {
            public:
                /**************************************************************
                * @brief: Constructor
                * @param: data is a string of characters
                **************************************************************/
                String(const std::string &data);


                /**************************************************************
                * @brief: Constructor
                * @param: data is a string of characters
                **************************************************************/
                String(const char* data = nullptr);


                /**************************************************************
                * @brief: Constructor
                * @param: data is a string of characters
                **************************************************************/
                String(const String &data);


                /**************************************************************
                * @brief: Deep copy assignment operator
                * @param: data is a string of characters
                **************************************************************/
                String operator=(const String &data);


                /**************************************************************
                * @brief: Equality operator
                * @param: data is a string of characters
                **************************************************************/
                bool operator==(const String &data);


                /**************************************************************
                * @brief: Less then equal
                * @param: data is a string of characters
                **************************************************************/
                bool operator<=(const String &data);


                /**************************************************************
                * @brief: Greater then equal
                * @param: data is a string of characters
                **************************************************************/
                bool operator>=(const String &data);


                /**************************************************************
                * @brief: Not equal
                * @param: data is a string of characters
                **************************************************************/
                bool operator!=(const String &data);


                /**************************************************************
                * @brief: This method returns the number of characters in the
                *         string
                * @return: The number of characters in the string
                **************************************************************/
                std::size_t size() const;


                /**************************************************************
                * @brief: This method returns the number of characters in the
                *         string
                * @return: The number of characters in the string
                **************************************************************/
                std::size_t length() const;


                /**************************************************************
                * @brief: This method returns the number of characters in the
                *         string
                * @return: The number of characters in the string
                **************************************************************/
                const char * c_str() const;


                /**************************************************************
                * @brief: This method returns an std::string equal to the
                *         current string value.
                * @return: A string of characters equal to the current string
                *          value.
                **************************************************************/
                std::string toStdString() const;


                /**************************************************************
                * @brief: This method removes all characters from the string
                **************************************************************/
                void clear() noexcept;


                /**************************************************************
                * @brief:  This method returns a boolean true value when the
                *          string is empty.
                * @return: A boolean true if the string is empty.
                **************************************************************/
                bool empty() const;


                /**************************************************************
                * @brief:  This method changes the size of the string.
                * @param:  n is the new size of the string
                **************************************************************/
                void resize (size_t n);


                /**************************************************************
                * @brief:  This method changes the size of the string.
                * @param:  n is the new size of the string\
                * @param:  c if the new size is bigger the new characters will
                *          be initialized to this value.
                **************************************************************/
                void resize (size_t n, char c);


                /**************************************************************
                * @brief:  This method changes the capacity of the string.
                *          capacity is the number of characters the string
                *          can hold.
                * @return: The current capacity of the string
                **************************************************************/
                size_t capacity() const;


                /**************************************************************
                * @brief:  This method returns a caracter at the given position
                *          in the string.
                * @param:  pos The position of the caracter ot be returned.
                * @return: The character at the position passed to pos.
                **************************************************************/
                char& operator[] (size_t pos);


                /**************************************************************
                * @brief:  This method returns a caracter at the given position
                *          in the string.
                * @param:  pos The position of the caracter ot be returned.
                * @return: The character at the position passed to pos.
                **************************************************************/
                const char& operator[] (size_t pos) const;


                /**************************************************************
                * @brief:  This method returns a caracter at the given position
                *          in the string.
                * @param:  pos The position of the caracter ot be returned.
                * @return: The character at the position passed to pos.
                **************************************************************/
                char& at (size_t pos);


                /**************************************************************
                * @brief:  This method returns a caracter at the given position
                *          in the string.
                * @param:  pos The position of the caracter ot be returned.
                * @return: The character at the position passed to pos.
                **************************************************************/
                const char& at (size_t pos) const;


                /**************************************************************
                * @brief:  This method returns the last character in the string
                * @return: The last character in the string.
                **************************************************************/
                char& back();


                /**************************************************************
                * @brief:  This method returns the last character in the string
                * @return: The last character in the string.
                **************************************************************/
                const char& back() const;


                /**************************************************************
                * @brief:  This method returns the first character in the string
                * @return: The first character in the string.
                **************************************************************/
                char& front();


                /**************************************************************
                * @brief:  This method returns the first character in the string
                * @return: The first character in the string.
                **************************************************************/
                const char& front() const;


                /**************************************************************
                * @brief:  This method appends the input string to the current
                *          string.
                * @param:  str a string to be appended to the current string.
                * @return: A reference to the updated string..
                **************************************************************/
                String& operator+= (const std::string& str);


                /**************************************************************
                * @brief:  This method appends the input string to the current
                *          string.
                * @param:  s a string to be appended to the current string.
                * @return: A reference to the updated string..
                **************************************************************/
                String& operator+= (const char* s);


                /**************************************************************
                * @brief:  This method appends the input string to the current
                *          string.
                * @param:  c a string to be appended to the current string.
                * @return: A reference to the updated string..
                **************************************************************/
                String& operator+= (char c);


                /**************************************************************
                * @brief:  This method appends the input string to the current
                *          string.
                * @param:  str a string to be appended to the current string.
                * @return: A reference to the updated string..
                **************************************************************/
                String& append (const std::string& str);


                /**************************************************************
                * @brief:  This method appends the input string to the current
                *          string.
                * @param:  str a string to be appended to the current string.
                * @param:  subpos the first character in str to be copied.
                * @param:  sublen the length of the string to be copied from str
                * @return: A reference to the updated string..
                **************************************************************/
                String& append (const std::string& str, size_t subpos, size_t sublen);


                /**************************************************************
                * @brief:  This method appends the input string to the current
                *          string.
                * @param:  s a pointer to the string to be appended.
                * @return: A reference to the updated string..
                **************************************************************/
                String& append (const char* s);


                /**************************************************************
                * @brief:  This method appends the input string to the current
                *          string.
                * @param:  s a pointer to the string to be appended.
                * @param:  The number of characters to be appended.
                * @return: A reference to the updated string..
                **************************************************************/
                String& append (const char* s, size_t n);


                /**************************************************************
                * @brief:  This method appends the character c n times to the
                *          current string.
                * @param:  n is the number of characters to be appended.
                * @param:  c the character to be appended.
                * @return: A reference to the updated string..
                **************************************************************/
                String& append (size_t n, char c);


                /**************************************************************
                * @brief:  This method appends a string starting at first
                *          and ending at last to the current string.
                * @param:  first iterator pointing to the first character to
                *          be appended.
                * @param:  last iterator pointing to one past the last character
                *          in the string to be appended.
                * @return: A reference to the updated string.
                **************************************************************/
                template <class InputIterator>
                String& append (InputIterator first, InputIterator last);


                /**************************************************************
                * @brief:  This method adds a character to the end of the string.
                * @param:  c the character to be added.
                **************************************************************/
                void push_back (char c);


                /**************************************************************
                * @brief:  Replace the current string with a new string.
                * @param:  str the string to be assigned.
                * @return: A reference to the updated string.
                **************************************************************/
                String& assign (const std::string& str);


                /**************************************************************
                * @brief:  Replace the current string with the substring of a
                *          new string.
                * @param:  str the string to be assigned.
                * @param:  subpos index to the beggining of the string in str.
                * @param:  sublen the length of the substring.
                * @return: A reference to the updated string.
                **************************************************************/
                String& assign (const std::string& str, size_t subpos, size_t sublen);


                /**************************************************************
                * @brief:  Replace the current string with the new string.
                * @param:  s the new string to be assigned.
                * @return: A reference to the updated string.
                **************************************************************/
                String& assign (const char* s);


                /**************************************************************
                * @brief:  Replace the current string with the new string.
                * @param:  s the new string to be assigned.
                * @param:  n the size of the new string.
                * @return: A reference to the updated string.
                **************************************************************/
                String& assign (const char* s, size_t n);


                /**************************************************************
                * @brief:  Replace the current string with n number of c characters.
                * @param:  n the number of characters to be assigned.
                * @param:  c the character to be assigned.
                * @return: A reference to the updated string.
                **************************************************************/
                String& assign (size_t n, char c);


                /**************************************************************
                * @brief:  Replace the current string with the string starting
                *          at first and ending at last
                * @param:  first the first character in the string to be assigned.
                * @param:  last the last character in the string to be assigned.
                * @return: A reference to the updated string.
                **************************************************************/
                template <class InputIterator>
                String& assign (InputIterator first, InputIterator last);


                /**************************************************************
                * @brief:  This changes the strings capacity.
                * @param:  n the new capacity
                **************************************************************/
                void reserve (size_t n = 0);


                /**************************************************************
                * @brief:  Shring the strings capacity to fit it's size.
                **************************************************************/
                void shrink_to_fit();


                /**************************************************************
                * @brief:  Erase len characters starting at pos
                * @param:  pos where to start erasing
                * @param:  len the number of characters to be erased
                * @return: A reference to the updated string.
                **************************************************************/
                String& erase (size_t pos = 0, size_t len = npos);
                //iterator erase (const_iterator p);
                //iterator erase (const_iterator first, const_iterator last);


                /**************************************************************
                * @brief:  Replace len characters starting at pos with str.
                * @param:  pos where to start replacing.
                * @param:  len the number of characters to be replaced.
                * @param:  str the string to replace the substring with.
                * @return: A reference to the updated string.
                **************************************************************/
                String& replace (size_t pos, size_t len, const std::string& str);
                //String& replace (const_iterator i1, const_iterator i2, const string& str);


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
                String& replace (size_t pos, size_t len, const std::string& str, size_t subpos, size_t sublen);


                /**************************************************************
                * @brief:  Replace len characters starting at pos with s.
                * @param:  pos where to start replacing.
                * @param:  len the number of characters to be replaced.
                * @param:  s the string used to replace the substring.
                * @return: A reference to the updated string.
                **************************************************************/
                String& replace (size_t pos, size_t len, const char* s);
                //String& replace (const_iterator i1, const_iterator i2, const char* s);


                /**************************************************************
                * @brief:  Replace len characters starting at pos with n
                *          characters starting at s.
                * @param:  pos where to start replacing.
                * @param:  len the number of characters to be replaced.
                * @param:  s the string used to replace the substring.
                * @param:  n the lengh of the substring.
                * @return: A reference to the updated string.
                **************************************************************/
                String& replace (size_t pos, size_t len, const char* s, size_t n);
                //String& replace (const_iterator i1, const_iterator i2, const char* s, size_t n);


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
                String& replace (size_t pos, size_t len, size_t n, char c);
                //String& replace (const_iterator i1, const_iterator i2, size_t n, char c);
                //template <class InputIterator>
                //String& replace (const_iterator i1, const_iterator i2,
                //                   InputIterator first, InputIterator last);
                //String& replace (const_iterator i1, const_iterator i2, initializer_list<char> il);


                /**************************************************************
                * @brief:  swap the characters in the current string with the
                *          characters in str.
                * @param:  str the string to swap the current string with
                **************************************************************/
                void swap (std::string& str);


                /**************************************************************
                * @brief:  Remove the last character in the string.
                **************************************************************/
                void pop_back();


                /**************************************************************
                * @brief:  Get the current string in c string form.
                * @return: A pointer to the current string of data.
                **************************************************************/
                const char* data() const noexcept;
                //allocator_type get_allocator() const noexcept;


                /**************************************************************
                * @brief:  Copy a substring from the current string into s
                *          starting at position pos and ending at pos + len.
                * @param:  s the pointer to store the copied string.
                * @param:  len the number of characters to be copied.
                * @param:  pos the position in the current string to start
                *          copying
                * @return: The number of characters copied into s.
                **************************************************************/
                size_t copy (char* s, size_t len, size_t pos = 0) const;


                /**************************************************************
                * @brief:  Find a string str in the current string
                *          starting at position pos.
                * @param:  str the string to be found
                * @param:  pos the position to start looking for str.
                * @return: The position of the first character of the first match.
                *          in the current string or npos;
                **************************************************************/
                size_t find (const std::string& str, size_t pos = 0) const noexcept;


                /**************************************************************
                * @brief:  Find a string s in the current string
                *          starting at position pos.
                * @param:  s the string to be found
                * @param:  pos the position to start looking for s.
                * @return: The position of the first character of the first match.
                *          in the current string or npos;
                **************************************************************/
                size_t find (const char* s, size_t pos = 0) const;
                //size_t find (const char* s, size_t pos, size_type n) const;


                /**************************************************************
                * @brief:  Find a character c in the current string starting
                *          at position pos.
                * @param:  c the character to be found
                * @param:  pos the position to start looking for c.
                * @return: The position of the first character of the first match.
                *          in the current string or npos;
                **************************************************************/
                size_t find (char c, size_t pos = 0) const noexcept;

                /**************************************************************
                * @brief:  Find the string str at pos in reverse order.
                * @param:  str the string to be found.
                * @param:  pos the position to start looking for str.
                * @return: The position of the first character of the first match.
                *          in the current string or npos;
                **************************************************************/
                size_t rfind (const std::string& str, size_t pos = npos) const noexcept;


                /**************************************************************
                * @brief:  Find the string s at pos in reverse order.
                * @param:  s the string to be found.
                * @param:  pos the position to start looking for s.
                * @return: The position of the first character of the first match.
                *          in the current string or npos;
                **************************************************************/
                size_t rfind (const char* s, size_t pos = npos) const;


                /**************************************************************
                * @brief:  Find the string s at pos with length n in reverse order.
                * @param:  s the string to be found.
                * @param:  pos the position to start looking for s.
                * @param:  n the length of the string.
                * @return: The position of the first character of the first match.
                *          in the current string or npos;
                **************************************************************/
                size_t rfind (const char* s, size_t pos, size_t n) const;


                /**************************************************************
                * @brief:  Find the character c at pos in reverse order.
                * @param:  c the character to be found.
                * @param:  pos the position to start looking for c.
                * @return: The position of the first character of the first match.
                *          in the current string or npos;
                **************************************************************/
                size_t rfind (char c, size_t pos = npos) const noexcept;


                /**************************************************************
                * @brief:  Find the first character that matches any character
                *          in str.
                * @param:  str the characters to search for
                * @param:  pos the position to start looking for str.
                * @return: The position of the first character of the first match.
                *          in the current string or npos;
                **************************************************************/
                size_t find_first_of (const std::string& str, size_t pos = 0) const noexcept;


                /**************************************************************
                * @brief:  Find the first character that matches any character
                *          in s starting at position pos.
                * @param:  s the characters to search for
                * @param:  pos the position to start looking for s.
                * @return: The position of the first character of the first match.
                *          in the current string or npos;
                **************************************************************/
                size_t find_first_of (const char* s, size_t pos = 0) const;


                /**************************************************************
                * @brief:  Find the first character that matches any character
                *          in s starting at position pos and ending at position
                *          pos + n.
                * @param:  s the characters to search for
                * @param:  pos the position to start looking for s.
                * @param:  n the number of the characters to search
                * @return: The position of the first character of the first match.
                *          in the current string or npos;
                **************************************************************/
                size_t find_first_of (const char* s, size_t pos, size_t n) const;


                /**************************************************************
                * @brief:  Find the first instance of character c starting at
                *          position pos.
                * @param:  c the character to search for
                * @param:  pos the position to start looking for c.
                * @return: The position of the first character of the first match.
                *          in the current string or npos;
                **************************************************************/
                size_t find_first_of (char c, size_t pos = 0) const noexcept;


                /**************************************************************
                * @brief:  Find the last instance of any character that matches
                *          a character in str starting at position pos.
                * @param:  str the characters to search for
                * @param:  pos the position to start looking for str.
                * @return: The position of the first character of the first match.
                *          in the current string or npos;
                **************************************************************/
                size_t find_last_of (const std::string& str, size_t pos = npos) const noexcept;


                /**************************************************************
                * @brief:  Find the last instance of any character that matches
                *          a character in s starting at position pos.
                * @param:  s the characters to search for
                * @param:  pos the position to start looking for s.
                * @return: The position of the first character of the first match.
                *          in the current string or npos;
                **************************************************************/
                size_t find_last_of (const char* s, size_t pos = npos) const;


                /**************************************************************
                * @brief:  Find the last instance of any character that matches
                *          a character in s starting at position pos and ending
                *          at pos + n.
                * @param:  s the characters to search for
                * @param:  pos the position to start looking for s.
                * @param:  n the number of characters to search
                * @return: The position of the first character of the first match.
                *          in the current string or npos;
                **************************************************************/
                size_t find_last_of (const char* s, size_t pos, size_t n) const;


                /**************************************************************
                * @brief:  Find the last instance of character c starting
                *          at position pos.
                * @param:  c the character to search for
                * @param:  pos the position to start looking for c.
                * @return: The position of the first character of the first match.
                *          in the current string or npos;
                **************************************************************/
                size_t find_last_of (char c, size_t pos = npos) const noexcept;


                /**************************************************************
                * @brief:  Find the first instance of any character not in str.
                *          starting at position pos.
                * @param:  str the characters not to search for
                * @param:  pos the position to start looking for str.
                * @return: The position of the first character of the first match.
                *          in the current string or npos;
                **************************************************************/
                size_t find_first_not_of (const std::string& str, size_t pos = 0) const noexcept;


                /**************************************************************
                * @brief:  Find the first instance of any character not in s.
                *          starting at position pos.
                * @param:  s the characters not to search for
                * @param:  pos the position to start looking for s.
                * @return: The position of the first character of the first match.
                *          in the current string or npos;
                **************************************************************/
                size_t find_first_not_of (const char* s, size_t pos = 0) const;


                /**************************************************************
                * @brief:  Find the first instance of any character not in s.
                *          starting at position pos and ending at pos + n.
                * @param:  s the characters not to search for
                * @param:  pos the position to start looking for s.
                * @param:  n the number of characters to be searched
                * @return: The position of the first character of the first match.
                *          in the current string or npos;
                **************************************************************/
                size_t find_first_not_of (const char* s, size_t pos, size_t n) const;


                /**************************************************************
                * @brief:  Find the first instance of characte not in c.
                *          starting at position pos.
                * @param:  c the characters not to search for
                * @param:  pos the position to start looking for c.
                * @return: The position of the first character of the first match.
                *          in the current string or npos;
                **************************************************************/
                size_t find_first_not_of (char c, size_t pos = 0) const noexcept;


                /**************************************************************
                * @brief:  Find the last instance of character not in c.
                *          starting at position pos.
                * @param:  c the characters not to search for
                * @param:  pos the position to start looking for c.
                * @return: The position of the first character of the first match.
                *          in the current string or npos;
                **************************************************************/
                size_t find_last_not_of (const std::string& str, size_t pos = npos) const noexcept;


                /**************************************************************
                * @brief:  Find the last instance of any character not in s.
                *          starting at position pos.
                * @param:  s the characters not to search for
                * @param:  pos the position to start looking for s.
                * @return: The position of the first character of the first match.
                *          in the current string or npos;
                **************************************************************/
                size_t find_last_not_of (const char* s, size_t pos = npos) const;


                /**************************************************************
                * @brief:  Find the last instance of any character not in s.
                *          starting at position pos and ending at position pos + n.
                * @param:  s the characters not to search for
                * @param:  pos the position to start looking for s.
                * @param:  n the max number of characters to be searched.
                * @return: The position of the first character of the first match.
                *          in the current string or npos;
                **************************************************************/
                size_t find_last_not_of (const char* s, size_t pos, size_t n) const;


                /**************************************************************
                * @brief:  Find the last instance of any character other than c.
                *          starting at position pos .
                * @param:  c the character not to search for
                * @param:  pos the position to start looking for c.
                * @return: The position of the first character of the first match.
                *          in the current string or npos;
                **************************************************************/
                size_t find_last_not_of (char c, size_t pos = npos) const noexcept;


                /**************************************************************
                * @brief:  Find a substring starting at position pos and
                *          ending at position pos + len .
                * @param:  pos the position to start looking.
                * @param:  len the max length of the substring.
                * @return: The substring found.
                **************************************************************/
                String substr (size_t pos = 0, size_t len = npos) const;

                int compare (const std::string& str) const noexcept;
                int compare (size_t pos, size_t len, const std::string& str) const;
                int compare (size_t pos, size_t len, const std::string& str, size_t subpos, size_t sublen) const;
                int compare (const char* s) const;
                int compare (size_t pos, size_t len, const char* s) const;
                int compare (size_t pos, size_t len, const char* s, size_t n) const;

                /**************************************************************
                * @brief: Destructor.
                **************************************************************/
                ~String();

                static std::size_t npos;
            private:
                typedef size_t size_type;
                class impl;
                impl* pimpl = nullptr;
        };

    }
}


#endif
