#ifndef ID_H_INCLUDED
#define ID_H_INCLUDED

namespace GU
{
    namespace Evt
    {
        namespace Id
        {
            const int LOWEST = -1;
            const int CHANGE_STATE = 0;
            const int PUSH_STATE = 1;
			const int POP_STATE = 2;
            const int MUSIC_VOLUME_CHANGED = 3;
            const int PLAY_MUSIC = 4;
            const int PLAY_SOUND = 5;
            const int SOUND_EFFECTS_VOLUME_CHANGED = 6;
            const int CLICK = 7;
            const int HIGHEST = 8;
        }

    }
}

#endif // ID_H_INCLUDED
