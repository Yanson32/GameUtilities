#include "GameUtilities/Event/OnSliderChanged.h"
#include "GameUtilities/Event/EventId.h"

namespace GU
{
    namespace Evt
    {
		OnSliderChanged::OnSliderChanged(const int &newId, const int &newValue, const int newLine, const char* newFile):
		Event(static_cast<int>(GU::Evt::EventId::SLIDER_CHANGED), newLine, newFile),
        sliderId(newId),
        value(newValue)

		{
			//ctor
		}

		OnSliderChanged::~OnSliderChanged()
		{
			//dtor
		}
	}
}
