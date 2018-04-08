#ifndef GU_EMITTER_H
#define GU_EMITTER_H
#include <cstddef>
#include "Math/Vector.h"

namespace GU
{
    namespace PS
    {
        namespace EM
        {
            class Emitter
            {
                public:
                    Emitter(const std::size_t particles);
                    virtual void Emit() = 0;
                    void SetRelativePosition(const Math::Vector &relativePosition);
                    Math::Vector GetRelativePosition()const;
                    virtual ~Emitter();
                protected:
                private:
                    const unsigned m_Particles = 0;
                    Math::Vector m_RelativePosition;
            };
        }
    }
}

#endif // GU_EMITTER_H
