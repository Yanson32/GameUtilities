#include "ObjectBase.h"
#include "ConvertCoords.h"
ObjectBase::ObjectBase(b2Body* body):
m_Body(body)
{
    //ctor
}


ObjectBase::ObjectBase(const ObjectBase& object)
{
    m_Body = object.m_Body;
}


void ObjectBase::update()
{
    for(b2Fixture *fix = m_Body->GetFixtureList(); fix; fix = fix->GetNext())
    {
        b2Shape::Type shapeType = fix->GetType();
        if(shapeType == b2Shape::e_circle)
        {
            b2CircleShape* circleShape = dynamic_cast<b2CircleShape*>(fix->GetShape());
            if(circleShape)
            {
                std::size_t vCount = circleShape->GetVertexCount();
                this->setPointCount(vCount);
                for(std::size_t i = 0; i < vCount; ++i)
                {
                    b2Vec2 localCoord = circleShape->GetVertex(i);
                    b2Vec2 worldCoord = m_Body->GetWorldPoint(localCoord);
                    this->setPoint(i, {toPixles(worldCoord.x), toPixles(worldCoord.y)});

                }
            }
        }
        else if(shapeType == b2Shape::e_polygon)
        {
            b2PolygonShape* polygonShape = dynamic_cast<b2PolygonShape*>(fix->GetShape());

            if(polygonShape)
            {
                std::size_t vCount = polygonShape->GetVertexCount();
                this->setPointCount(vCount);
                for(std::size_t i = 0; i < vCount; ++i)
                {
                    b2Vec2 localCoord = polygonShape->GetVertex(i);
                    b2Vec2 worldCoord = m_Body->GetWorldPoint(localCoord);
                    this->setPoint(i, {toPixles(worldCoord.x), toPixles(worldCoord.y)});
                }
            }
        }
    }
}

void ObjectBase::operator = (const ObjectBase& object)
{
    m_Body = object.m_Body;
}


ObjectBase::~ObjectBase()
{
    //dtor
}
