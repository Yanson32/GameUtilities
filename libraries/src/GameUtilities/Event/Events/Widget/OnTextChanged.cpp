/*********************************************************************//***
*   @author Wayne J Larson Jr.
*   @date   08/31/22
*   @file   OnTextChanged.cpp
**************************************************************************/
#include "GameUtilities/Event/Events/Widget/OnTextChanged.h"
#include "GameUtilities/Event/EventId.h"


namespace GU
{
    namespace Evt
    {

        /**********************************************************************//**
        *   @brief Constructor. 
        *   @param parent is the widget where the event originated from.
        *   @param widgetId is the id of the widget where the event originated.
        *   @param text is the new text.
        *   @param line is the line in source code where the event originated.  
        *   @param file is the source code file where the event originated from.
        **************************************************************************/
        OnTextChanged::OnTextChanged(std::shared_ptr<void> parent, 
        const int &widgetId, 
        const GU::Core::String &text, 
        const int &line, 
        const char* file):
        WidgetEvent(parent, widgetId, static_cast<int>(GU::Evt::EventId::ON_TEXT_CHANGED), line, file),
        m_text(text)
        {

        }


        /**********************************************************************//**
        *   @brief Destructor.
        **************************************************************************/
        OnTextChanged::~OnTextChanged()
        {

        }

    }
}

