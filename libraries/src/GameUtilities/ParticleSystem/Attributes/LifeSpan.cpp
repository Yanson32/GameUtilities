#include "GameUtilities/ParticleSystem/Attributes/LifeSpan.h"
#include "GameUtilities/ParticleSystem/Attributes/AttributeManager.h"
#include "GameUtilities/ParticleSystem/Attributes/Id.h"

namespace GU
{
	namespace PS
	{
		namespace AT
		{
			LifeSpan::LifeSpan(GU::PS::AT::AttributeManager &newManager, const std::size_t &newSize):
            AttributeBase::AttributeBase(newManager, GU::PS::AT::LIFESPAN),
			data(newSize)
			{

			}

			void LifeSpan::remove(const std::size_t &index)
			{
			   this->data.remove(index);
			}

		}
	}
}
