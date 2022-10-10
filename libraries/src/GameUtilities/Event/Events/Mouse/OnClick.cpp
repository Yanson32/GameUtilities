#include "GameUtilities/Event/Events/Mouse/OnClick.h"
#include "GameUtilities/Event/EventId.h"
namespace GU
{
    namespace Evt
    {
        /**************************************************************************
        *   @brief  Constructor
        *   @param  id is the unique id of the button that was clicked 
        **************************************************************************/
        OnClick::OnClick(const int &buttonId, const int &line, const char* file):
        Event(static_cast<int>(GU::Evt::EventId::CLICK), line, file),
        m_buttonId(buttonId)
        {
            //ctor
        }

        
        /**************************************************************************
        *   @brief  Destructor 
        **************************************************************************/
        OnClick::~OnClick()
        {
            //dtor
        }
    }
}
