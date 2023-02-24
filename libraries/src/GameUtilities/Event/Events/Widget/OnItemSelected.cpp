/**************************************************************************
*   @author Wayne J Larson Jr.
*   @date   05/07/22
*   @file   OnItemSelected.cpp
**************************************************************************/
#include "GameUtilities/Event/Events/Widget/OnItemSelected.h"
#include "GameUtilities/Event/EventId.h"
namespace GU
{
    namespace Evt
    {
        /**********************************************************************//**
        *   @brief  Constructor   
        *   @param  parent is a pointer to the widget where the event originated.
        *   @param  widgetId is the id of the combo box
        *   @param  index is the index of the currently selected element. 
        *   @param  text is the currently selected text.
        *   @param  line is the line number in source code where the event originated.
        *   @param  file is the source code file where the event originated.
        **************************************************************************/
        OnItemSelected::OnItemSelected(std::shared_ptr<void> parent, 
        const int &widgetId, 
        const int &index, 
        const GU::Core::String &text, 
        const int &line, 
        const char* file):
        WidgetEvent(parent, widgetId, static_cast<int>(GU::Evt::EventId::ON_ITEM_SELECTED), line, file),
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
