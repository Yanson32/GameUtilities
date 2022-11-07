#include "GameUtilities/ParticleSystem/Attributes/Position.h"
#include "GameUtilities/ParticleSystem/Attributes/Id.h"
namespace GU
{
	namespace PS
	{
		namespace AT
		{
			Position::Position(GU::PS::AT::Manager &newManager, const std::size_t &newSize):
            AttributeBase::AttributeBase(newManager, GU::PS::AT::Id::POSITION),
            data(newSize)
			{

			}


			void Position::remove(const std::size_t &index)
			{
			    this->data.remove(index);
			}
		}
	}
}
