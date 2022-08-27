#ifndef COLLISION_TYPES_H
#define COLLISION_TYPES_H
namespace GU
{
    namespace Al
    {
        class CollisionInfo;
        typedef std::vector<Math::Vector2<float>> PointsVec;
        typedef Math::Vector2<float> Position;
        typedef Math::Vector2<float> Direction;
        typedef std::pair<float, float> Projection;
    }
}
#endif
