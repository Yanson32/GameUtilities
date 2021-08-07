#include "GameUtilities/Core/String.h"

namespace GU
{
    namespace Core
    {
        String::String(const char* newData):
            data(newData)
        {

        }
        
        
        std::size_t String::size() const
        {
            return strlen(data);
        }
 

        const char* String::c_str() const
        {
            return data;
        }


        String::~String()
        {

        }
    }
}
