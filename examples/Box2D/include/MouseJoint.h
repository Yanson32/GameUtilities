#ifndef BOX2D_MOUSE_JOINT_H
#define	BOX2D_MOUSE_JOINT_H
#include <Box2D/Box2D.h>
#include <SFML/Graphics/Drawable.hpp>

class MouseJoint: public sf::Drawable
{
	public:
		MouseJoint(b2MouseJoint* joint, b2World* world);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		void setMousePos(sf::Vector2f &mousePos);
		virtual ~MouseJoint();
    private:
        b2MouseJoint* m_MouseJoint = nullptr;
        b2World* m_World = nullptr;
};


class MouseJointCallback:
public b2QueryCallback
{
    public:
        virtual bool ReportFixture(b2Fixture* fixture);
        b2Fixture * m_Fixture = nullptr;
};
#endif
