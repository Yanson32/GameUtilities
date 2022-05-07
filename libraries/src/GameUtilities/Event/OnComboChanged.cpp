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
        OnComboChanged::OnComboChanged(const int newComboId, const int newIndex):
        Event(static_cast<int>(GU::Evt::EventId::ON_COMBO_CHANGED)),
        comboId(newComboId),
        index(newIndex)
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
