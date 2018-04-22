#ifndef BOX2D_EXAMPLES_OBJECTBASE_H
#define BOX2D_EXAMPLES_OBJECTBASE_H

#include <SFML/Graphics/ConvexShape.hpp>
#include <Box2D/Box2D.h>

class ObjectBase:
public sf::ConvexShape
{
    public:
        ObjectBase(b2Body* body);
        ObjectBase(const ObjectBase& object);
        void operator = (const ObjectBase& object);
        void update();
        virtual ~ObjectBase();
    protected:
    private:
        b2Body* m_Body = nullptr;
};

#endif // BOX2D_EXAMPLES_OBJECTBASE_H
