#ifndef GU_VELOCITY_H
#define GU_VELOCITY_H
#include "GameUtilities/Particle System/Attribute/Attribute.h"
#include "Math/Vector.h"

namespace GU
{
    namespace PS
    {
        namespace AT
        {
            class Velocity: public Attribute<Math::Vector>
            {
                public:
                    Velocity();
                    ~Velocity();
                    float degree = 0;
                    float magnitude = 0;
            };
        }
    }
}

#endif // GU_VELOCITY_H
