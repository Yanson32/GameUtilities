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
		OnSliderChanged::OnSliderChanged(const int &id, const int &value, const int line, const char* file):
		Event(static_cast<int>(GU::Evt::EventId::SLIDER_CHANGED), line, file),
        m_sliderId(id),
        m_value(value)

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
