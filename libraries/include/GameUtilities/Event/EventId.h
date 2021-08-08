#ifndef GAMEUTILITIES_EVENT_ID_H
#define GAMEUTILITIES_EVENT_ID_H

namespace GU
{
    namespace Evt
    {
        enum class EventId
        {
            LOWEST = -1,
            CHANGE_STATE = 0,
            PUSH_STATE = 1,
			POP_STATE = 2,
            MUSIC_VOLUME_CHANGED = 3,
            PLAY_MUSIC = 4,
            PLAY_SOUND = 5,
            SOUND_EFFECTS_VOLUME_CHANGED = 6,
            CLICK = 7,
            SLIDER_CHANGED = 8,
            ON_CHECK= 9,
            ON_COMBO_CHANGED = 10,
            HIGHEST = 11
        };

    }
}

#endif 
