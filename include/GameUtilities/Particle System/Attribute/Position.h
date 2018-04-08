#ifndef GU_POSITION_H
#define GU_POSITION_H
#include "GameUtilities/Particle System/Attribute/Attribute.h"
#include "Math/Point.h"

namespace GU
{
    namespace PS
    {
        namespace AT
        {
            class Position: public GU::PS::AT::Attribute<Math::Point>
            {
                public:
                    Position();
                    virtual ~Position();
                protected:
                private:
            };
        }
    }
}

#endif // GU_POSITION_H
