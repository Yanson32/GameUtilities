#include "GameUtilities/ParticleSystem/Attributes/AttributeBase.h"
#include "GameUtilities/ParticleSystem/Attributes/Manager.h"
#include "GameUtilities/Core/Macros.h"
namespace GU
{
	namespace PS
	{
		namespace AT
		{
			AttributeBase::AttributeBase(GU::PS::AT::Manager &newManager, const std::size_t &newSize, const int &newId):
            manager(newManager),
            id(newId)
			{
                UNUSED(newSize);
			}

			AttributeBase::~AttributeBase()
			{

			}
		}
	}
}
