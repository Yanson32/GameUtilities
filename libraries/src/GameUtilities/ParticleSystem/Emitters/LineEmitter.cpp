#include "GameUtilities/ParticleSystem/Emitters/Line.h"


namespace GU
{
    namespace PS
    {
        namespace EM
        {
            
            /************************************************************************//**
            *   @brief  Constructor. 
            *   @param  parent is a pointer to the parent particle system. 
            *   @param  ppf (particles per frame) is the number of particles in the system.
            *   @param  relativePosition is the relative position of the emitter. 
            ****************************************************************************/
            LineEmitter::LineEmitter(GU::PS::ParticleSystem *parent, const std::size_t ppf, Math::Vector relativePosition):
            Emitter(parent, ppf, relativePosition)
            {
                //ctor
            }

            
            /************************************************************************//**
            *   @brief  Destructor.
            ****************************************************************************/
            LineEmitter::~LineEmitter()
            {
                //dtor
            }
        }
    }
}
