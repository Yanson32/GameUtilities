#ifndef COLLISION_INFO_H
#define COLLISION_INFO_H
#include <limits>

namespace GU
{
    namespace Al
    {
        class SatObject;
        class CollisionInfo
        {
            public: 
                SatObject *first = nullptr;
                SatObject *second = nullptr;
                unsigned magnitude = ~0; 
                Direction direction;
        };
    }
}
#endif
