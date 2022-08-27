#include "GameUtilities/Event/OnCheck.h"
#include "GameUtilities/Event/EventId.h"
namespace GU
{
    namespace Evt
    {
        /**************************************************************************
        *   @breif  Constructor
        *   @param  checkBoxId is a unique identifier for the checkbox.
        *   @param  checked is true if the checkbox was checked and false otherwise.
        **************************************************************************/
        OnCheck::OnCheck(const int checkBoxId, const bool checked):
        Event(static_cast<int>(GU::Evt::EventId::ON_CHECK)),
        m_checkboxId(checkBoxId),
        m_checked(checked)
        {
            //ctor
        }

        
        /**************************************************************************
        *   @breif  Destructor 
        **************************************************************************/
        OnCheck::~OnCheck()
        {
            //dtor
        }
    }
}
