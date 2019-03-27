#ifndef GU_LIFESPAN_H
#define GU_LIFESPAN_H
#include "GameUtilities/Particle System/Attribute/Attribute.h"


namespace GU
{
    namespace PS
    {
        namespace AT
        {
            class LifeSpan: public Attribute<unsigned>
            {
                public:
                    LifeSpan();
                    virtual ~LifeSpan();
                protected:
                private:
            };
        }
    }
}
#endif // GU_LIFESPAN_H
