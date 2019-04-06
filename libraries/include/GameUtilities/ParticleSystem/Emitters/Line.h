#ifndef GU_LINE_H
#define GU_LINE_H
#include "particlesystem_export.h"
#include "GameUtilities/ParticleSystem/Emitters/Emitter.h"

namespace GU
{
    namespace PS
    {
        namespace EM
        {
            class PARTICLESYSTEM_EXPORT Line: public Emitter
            {
                public:
                    Line(GU::PS::ParticleSystem *parent, const std::size_t ppf, Math::Vector relativePosition = Math::Vector());
                    virtual void Emit() = 0;
                    virtual ~Line();
                protected:
                private:
            };
        }
    }
}

#endif // GU_LINE_H
