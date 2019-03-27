#include "GameUtilities/Particle System/Emitters/Emitter.h"


namespace GU
{
    namespace PS
    {
        namespace EM
        {
            Emitter::Emitter(GU::PS::ParticleSystem *parent, const std::size_t ppf, Math::Vector relativePosition):
            m_Parent(parent),
            m_Ppf(ppf),
            m_RelativePosition(relativePosition)
            {
            }

            void Emitter::SetRelativePosition(const Math::Vector &relativePosition)
            {
                m_RelativePosition = relativePosition;
            }

            Math::Vector Emitter::GetRelativePosition()const
            {
                return m_RelativePosition;
            }

            Emitter::~Emitter()
            {
                //dtor
            }
        }
    }
}
