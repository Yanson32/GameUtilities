#include "GameUtilities/ParticleSystem/Attributes/Base.h"
#include "GameUtilities/ParticleSystem/Attributes/Manager.h"
#include "GameUtilities/Core/Macros.h"
namespace GU
{
	namespace PS
	{
		namespace AT
		{
			Base::Base(GU::PS::AT::Manager &newManager, const std::size_t &newSize, const int &newId):
            manager(newManager),
            id(newId)
			{
                UNUSED(newSize);
			}

			Base::~Base()
			{

			}
		}
	}
}
