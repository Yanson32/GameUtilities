#include "GameUtilities/Particle System/Emitters/Emitter.h"


namespace GU
{
    namespace PS
    {
        namespace EM
        {
            Emitter::Emitter(const std::size_t particles):
            m_Particles(particles)
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
