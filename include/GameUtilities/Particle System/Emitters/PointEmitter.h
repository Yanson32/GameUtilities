#ifndef GU_POINTEMITTER_H
#define GU_POINTEMITTER_H
#include "GameUtilities/Particle System/Emitters/Emitter.h"

namespace GU
{
    namespace PS
    {
        namespace EM
        {
            class PointEmitter: public Emitter
            {
                public:
                    PointEmitter(const std::size_t particles);
                    virtual void Emit();
                protected:
                private:
            };
        }
    }
}

#endif // GU_POINTEMITTER_H
