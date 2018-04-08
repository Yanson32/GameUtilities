#ifndef GU_LINE_H
#define GU_LINE_H
#include "GameUtilities/Particle System/Emitters/Emitter.h"

namespace GU
{
    namespace PS
    {
        namespace EM
        {
            class Line: public Emitter
            {
                public:
                    Line(const std::size_t particles);
                    virtual void Emit() = 0;
                    virtual ~Line();
                protected:
                private:
            };
        }
    }
}

#endif // GU_LINE_H
