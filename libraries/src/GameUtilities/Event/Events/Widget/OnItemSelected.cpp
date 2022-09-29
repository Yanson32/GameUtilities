#include "GameUtilities/Event/Events/Widget/OnItemSelected.h"
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
        OnItemSelected::OnItemSelected(const int &comboId, const int &index, const GU::Core::String &text):
        Event(static_cast<int>(GU::Evt::EventId::ON_ITEM_SELECTED)),
        m_comboId(comboId),
        m_index(index),
        m_text(text)
        {
            //ctor
        }

        

        /**************************************************************************
        *   @brief  Destructor
        **************************************************************************/
        OnItemSelected::~OnItemSelected()
        {
            //dtor
        }
    }
}
