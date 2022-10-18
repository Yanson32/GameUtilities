#include "GameUtilities/Event/Events/Widget/OnCheck.h"
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
        OnCheck::OnCheck(std::shared_ptr<void> parent, const int &widgetId, const bool &checked, const int &line, const char* file):
        WidgetEvent(parent, widgetId, static_cast<int>(GU::Evt::EventId::ON_CHECK), line, file),
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
