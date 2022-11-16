/**************************************************************************
*   @Author Wayne J Larson Jr.
*   @Date   10/01/22
*   @file   WidgetEvent.cpp
**************************************************************************/
#include "GameUtilities/Event/Events/Widget/WidgetEvent.h"

namespace GU
{
    namespace Evt
    {
        
        /******************************************************************//**
        *   @brief Constructor
        *   @param parent is the widget where the event originated.
        *   @param widgetId Is a unique identifier for the widget that created the event.
        *   @param eventId  Is a unique identifier for the event. 
        *   @param line is the line in source code where the event originated.
        *   @param file is the source code file where the event originated.
        **********************************************************************/
        WidgetEvent::WidgetEvent(std::shared_ptr<void> parent, const int &widgetId, const int &eventId, const int &line, const char* file):
        Event(eventId, line, file),
        m_parent(parent),
        m_widgetId(widgetId)
        {

        }


        /******************************************************************//**
        *   @brief  Destructor. 
        **********************************************************************/
        WidgetEvent::~WidgetEvent()
        {

        }
    }
}
