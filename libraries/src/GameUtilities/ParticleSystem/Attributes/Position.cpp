#include "GameUtilities/ParticleSystem/Attributes/Position.h"
#include "GameUtilities/ParticleSystem/Attributes/Id.h"
namespace GU
{
	namespace PS
	{
		namespace AT
		{
            /************************************************************************//**
            *   @brief  Constructor 
            *   @param  manager is a reference to the attribute manager. 
            *   @param  size is the number of attributes to be created. 
            ****************************************************************************/
			Position::Position(GU::PS::AT::AttributeManager &manager, const std::size_t &size):
            AttributeBase::AttributeBase(manager, GU::PS::AT::Id::POSITION),
            m_data(size)
			{

			}


            /************************************************************************//**
            *   @brief  This method removes an attribute from the container at the given 
            *           index. 
            *   @param  index is the position in the container of the attribute to be 
            *           removed. 
            ****************************************************************************/
			void Position::remove(const std::size_t &index)
			{
			    this->m_data.remove(index);
			}
		}
	}
}
