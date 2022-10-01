#ifndef GAMEUTILITIES_EVENT_ID_H
#define GAMEUTILITIES_EVENT_ID_H

namespace GU
{
    namespace Evt
    {
        enum EventId
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
            ON_ITEM_SELECTED = 10,
            LOG = 11,
            ON_TEXT_CHANGED = 12,
            ON_KEY_PRESSED = 13,
            ON_KEY_RELEASED = 14,
            ON_MESSAGE,
            ON_BEGIN_DRAG,
            ON_END_DRAG,
            ON_CONTEXT_MENU,
            ON_DOUBLE_CLICK,
            ON_MOUSE_BUTTON_PRESSED,
            ON_MOUSE_BUTTON_RELEASED,
            ON_MOUSE_MOVED,
            ON_MOUSE_WHEEL,
            ON_START_MOUSE_DRAG,
            CON_END_MOUSE_DRAG,
            HIGHEST = 15
        };

    }
}

#endif 
