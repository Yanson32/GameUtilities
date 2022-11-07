#include "GameUtilities/ParticleSystem/Attributes/Velocity.h"
#include "GameUtilities/ParticleSystem/Attributes/Manager.h"
#include "GameUtilities/ParticleSystem/Attributes/Position.h"
#include "GameUtilities/ParticleSystem/Attributes/Id.h"

namespace GU
{
	namespace PS
	{
		namespace AT
		{
			Velocity::Velocity(GU::PS::AT::Manager &newManager, const std::size_t &newSize):
            AttributeBase::AttributeBase(newManager, GU::PS::AT::Id::VELOCITY),
            data(newSize)
			{

			}


			void Velocity::remove(const std::size_t &index)
			{
			    this->data.remove(index);
			}
		}
	}
}
