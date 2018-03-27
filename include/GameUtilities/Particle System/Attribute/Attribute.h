#ifndef GU_ATTRIBUTE_H
#define GU_ATTRIBUTE_H
#include "GameUtilities/Particle System/Container.h"

namespace GU
{
    namespace PS
    {
        namespace AT
        {
            template<class T>
            class Attribute
            {
                public:
                    Attribute() = delete;
                    Attribute(const int id): id(id)
                    Container<T> attribute;
                    const int id;
            };
        }
    }
}

#endif // GU_ATTRIBUTE_H
