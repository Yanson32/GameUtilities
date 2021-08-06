#include "GameUtilities/Event/OnSliderChanged.h"
#include "GameUtilities/Event/Id.h"

namespace GU
{
    namespace Evt
    {
		OnSliderChanged::OnSliderChanged(const int &newId, const int &newValue, const int newLine, const char* newFile):
		Event(GU::Evt::Id::MUSIC_VOLUME_CHANGED, newLine, newFile),
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
