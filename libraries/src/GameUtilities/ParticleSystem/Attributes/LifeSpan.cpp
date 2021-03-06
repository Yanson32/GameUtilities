#include "GameUtilities/ParticleSystem/Attributes/LifeSpan.h"
#include "GameUtilities/ParticleSystem/Attributes/Manager.h"
#include "GameUtilities/ParticleSystem/Attributes/Id.h"

namespace GU
{
	namespace PS
	{
		namespace AT
		{
			LifeSpan::LifeSpan(GU::PS::AT::Manager &newManager, const std::size_t &newSize):
            Base::Base(newManager, newSize, GU::PS::AT::LIFESPAN),
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
