
#include "MouseJoint.h"
#include <Box2D/Box2D.h>

MouseJoint::MouseJoint(b2MouseJoint* mouseJoint):
m_MouseJoint(mouseJoint)
{

}

void MouseJoint::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}

bool MouseJointCallback::ReportFixture(b2Fixture* fixture)
{
    m_Fixture = fixture;
}
