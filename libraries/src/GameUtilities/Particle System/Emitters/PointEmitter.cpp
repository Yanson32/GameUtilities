#include "GameUtilities/Particle System/Emitters/PointEmitter.h"
#include "GameUtilities/Particle System/Systems/ParticleSystem.h"
namespace GU
{
    namespace PS
    {
        namespace EM
        {
            PointEmitter::PointEmitter(GU::PS::ParticleSystem *parent, const std::size_t ppf, Math::Vector relativePosition):
            Emitter(parent, ppf, relativePosition)
            {
                //ctor
            }

            void PointEmitter::Emit()
            {
                assert(m_Parent);
                Math::Point position = m_Parent->getPosition() + m_RelativePosition;
                for(std::size_t i = 0; i < m_Ppf; ++i)
                {
                    //m_Parent->particles.position.emplace_back<Math::Point>(position.m_x, position.m_y);
                }
            }
        }
    }
}
