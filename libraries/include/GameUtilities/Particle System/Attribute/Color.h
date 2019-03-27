#ifndef GU_COLOR_H
#define GU_COLOR_H
#include "GameUtilities/Particle System/Attribute/Attribute.h"
#include "GameUtilities/RGBA.h"

namespace GU
{
    namespace PS
    {
        namespace AT
        {
            class Color: public Attribute<RGBA>
            {
                public:
                    Color();
                    virtual ~Color();
                protected:
                private:
            };
        }
    }
}

#endif // GU_COLOR_H
