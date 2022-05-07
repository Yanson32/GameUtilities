#include "GameUtilities/Event/OnComboChanged.h"
#include "GameUtilities/Event/EventId.h"
namespace GU
{
    namespace Evt
    {
        /**************************************************************************
        *   @brief  Constructor   
        *   @param  newComboId is the id of the combo box
        *   @param  newIndex is the index of the data element that has changed. 
        **************************************************************************/
        OnComboChanged::OnComboChanged(const int comboId, const int index):
        Event(static_cast<int>(GU::Evt::EventId::ON_COMBO_CHANGED)),
        m_comboId(comboId),
        m_index(index)
        {
            //ctor
        }

        

        /**************************************************************************
        *   @brief  Destructor
        **************************************************************************/
        OnComboChanged::~OnComboChanged()
        {
            //dtor
        }
    }
}
