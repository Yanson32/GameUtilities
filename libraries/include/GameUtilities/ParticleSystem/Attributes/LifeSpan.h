#ifndef ATTRIBUTES_LIFE_SPAN_H
#define ATTRIBUTES_LIFE_SPAN_H
#include "particlesystem_export.h"
#include "GameUtilities/ParticleSystem/Attributes/AttributeBase.h"
#include "GameUtilities/ParticleSystem/Container.h"
namespace GU
{
	namespace PS
	{
		namespace AT
		{
			class PARTICLESYSTEM_EXPORT LifeSpan: public GU::PS::AT::AttributeBase
			{
				public:
					LifeSpan(GU::PS::AT::Manager &newManager, const std::size_t &newSize);
					void remove(const std::size_t &index) override;
					GU::PS::Container<float> data;
			};
		}
	}
}
#endif
