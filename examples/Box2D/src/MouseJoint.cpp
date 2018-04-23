
#include "MouseJoint.h"
#include <Box2D/Box2D.h>
#include "ConvertCoords.h"
MouseJoint::MouseJoint(b2MouseJoint* mJoint, b2World* world):
m_MouseJoint(mJoint),
m_World(world)
{

}

void MouseJoint::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}

void MouseJoint::setMousePos(sf::Vector2f &mousePos)
{

    if(m_MouseJoint)
    {
        b2Vec2 pos = toMeters(mousePos);
        m_MouseJoint->SetTarget(pos);
    }
}


MouseJoint::~MouseJoint()
{
    m_World->DestroyJoint(m_MouseJoint);
    m_MouseJoint = nullptr;
}


bool MouseJointCallback::ReportFixture(b2Fixture* fixture)
{
    m_Fixture = fixture;
}

