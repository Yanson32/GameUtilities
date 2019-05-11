#include "GameUtilities/ParticleSystem/Emitters/Line.h"


namespace GU
{
    namespace PS
    {
        namespace EM
        {
            Line::Line(GU::PS::ParticleSystem *parent, const std::size_t ppf, Math::Vector relativePosition):
            Emitter(parent, ppf, relativePosition)
            {
                //ctor
            }

            Line::~Line()
            {
                //dtor
            }
        }
    }
}
