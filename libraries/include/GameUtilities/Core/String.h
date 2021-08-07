#ifndef GAMEUTILITIES_STRING_H
#define GAMEUTILITIES_STRING_H
#include <cstring>
#include "core_export.h"

namespace GU
{
    namespace Core
    {
        class CORE_EXPORT String
        {
            public:
                String(const char* newData = nullptr);
                std::size_t size() const; 
                const char* c_str() const;     
                template <class T>
                friend T& operator << (T &in, const String &st);
               
                template <class T>
                friend T& operator >> (T &out, const String &st);

                ~String();
            private:
                const char* data = nullptr;
        };
        template <class T>
        T& operator << (T &in, const String &st)
        {
            in << st.data;
            return in; 
        }
               
        template <class T>
        T& operator >> (T &out, const String &st)
        {
            out >> st.data;
            return out;
        }
    }
}


#endif
