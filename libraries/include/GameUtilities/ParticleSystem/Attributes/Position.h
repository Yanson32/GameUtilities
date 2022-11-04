#ifndef ATTRIBUTES_POSITION_H
#define ATTRIBUTES_POSITION_H
#include "particlesystem_export.h"
#include "GameUtilities/ParticleSystem/Attributes/AttributeBase.h"
#include "GameUtilities/ParticleSystem/Container.h"
namespace GU
{
	namespace PS
	{
		namespace AT
		{
			class PARTICLESYSTEM_EXPORT Position: public GU::PS::AT::AttributeBase
			{
				public:
					Position(GU::PS::AT::Manager &newManager, const std::size_t &newSize);
					void remove(const std::size_t &index) override;
					GU::PS::Container<std::pair<float, float>> data;
			};
		}
	}
}
#endif
