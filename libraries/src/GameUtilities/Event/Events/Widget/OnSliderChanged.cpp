#include "GameUtilities/Event/Events/Widget/OnSliderChanged.h"
#include "GameUtilities/Event/EventId.h"

namespace GU
{
    namespace Evt
    {
        /**************************************************************************
        *   @breif  Constructor
        *   @param  id of the slider.
        *   @param  value is the current value of the slider
        *   @param  line is where the event was generated in code.
        *   @param  file is the file where the event was generated.
        **************************************************************************/
		OnSliderChanged::OnSliderChanged(std::shared_ptr<void> parent, const int &widgetId, const int &value, const int &line, const char* file):
		WidgetEvent(parent, widgetId, static_cast<int>(GU::Evt::EventId::SLIDER_CHANGED), line, file),
        m_sliderPos(value)

		{
			//ctor
		}

        
        /**************************************************************************
        *   @breif  Deconstructor 
        **************************************************************************/
		OnSliderChanged::~OnSliderChanged()
		{
			//dtor
		}
	}
}
