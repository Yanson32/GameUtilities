#include "TestState.h"
#include <GameUtilities/Engin/Engin.h>
#include <SFML/Graphics/Color.hpp>
#include <iostream>
#include <cassert>
#include "ConvertCoords.h"

const std::size_t WINDOW_WIDTH = 800;
const std::size_t WINDOW_HEIGHT = 600;
const std::size_t WALL_THICKNESS = 10;


TestState::TestState(GU::Engin::Engin& engin):
m_Window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Box2D Example"),
m_Engin(engin),
m_World(b2Vec2(0, (-9.8))),
m_DebugDraw(m_World, 40)
{
    //Create ground
    b2BodyDef groundBodyDef;
    groundBodyDef.type = b2_staticBody;
    groundBodyDef.position.Set(toMeters(WINDOW_WIDTH / 2), toMeters(WINDOW_HEIGHT));
    groundBody = m_World.CreateBody(&groundBodyDef);
    assert(groundBody);

    b2PolygonShape groundShape;
    groundShape.SetAsBox(toMeters((WINDOW_WIDTH / 2)), (toMeters(WALL_THICKNESS)));

    b2FixtureDef groundFixtureDef;
    groundFixtureDef.shape = &groundShape;

    b2Fixture* fixture = groundBody->CreateFixture(&groundFixtureDef);
    assert(fixture);
    m_Objects.emplace_back<ObjectBase>(groundBody);
    m_Objects.back().setFillColor(sf::Color::Red);


    //Create dynamic body
    b2BodyDef dynamicBodyDef;
    dynamicBodyDef.type = b2BodyType::b2_dynamicBody;
    dynamicBodyDef.position.Set(toMeters(100), toMeters(100));
    dynamicBody = m_World.CreateBody(&dynamicBodyDef);
    assert(dynamicBody);
    assert(dynamicBody->GetType() == b2BodyType::b2_dynamicBody);

    b2PolygonShape dynamicShape;
    dynamicShape.SetAsBox(toMeters(50), (toMeters(50)));

    b2FixtureDef dynamicFixtureDef;
    dynamicFixtureDef.shape = &dynamicShape;
    dynamicFixtureDef.density = 1;
    dynamicFixtureDef.restitution = 0;
    b2Fixture* dynamicFixture = dynamicBody->CreateFixture(&dynamicFixtureDef);
    assert(dynamicFixture);

    m_Objects.emplace_back<ObjectBase>(dynamicBody);
    m_Objects.back().setFillColor(sf::Color::Red);

    //Create dynamic circle
    b2BodyDef circleBodyDef;
    circleBodyDef.type = b2BodyType::b2_dynamicBody;
    circleBodyDef.position.Set(toMeters(200), toMeters(100));
    b2Body* circleDynamicBody = m_World.CreateBody(&circleBodyDef);
    assert(circleDynamicBody);
    assert(circleDynamicBody->GetType() == b2BodyType::b2_dynamicBody);

    b2CircleShape dynamicCircleShape;
    dynamicCircleShape.m_radius = toMeters(30);

    b2FixtureDef dynamicCircleFixtureDef;
    dynamicCircleFixtureDef.shape = &dynamicCircleShape;
    dynamicCircleFixtureDef.density = 1;
    dynamicCircleFixtureDef.restitution = 0;
    b2Fixture* dynamicCircleFixture = circleDynamicBody->CreateFixture(&dynamicCircleFixtureDef);
    assert(dynamicCircleFixture);

    m_Objects.emplace_back<ObjectBase>(circleDynamicBody);
    m_Objects.back().setFillColor(sf::Color::Red);

    m_DebugDraw.SetFlags(b2Draw::e_shapeBit || b2Draw::e_centerOfMassBit || b2Draw::e_jointBit || b2Draw::e_aabbBit || b2Draw::e_pairBit);
    m_World.SetDebugDraw(&m_DebugDraw);
}


/*********************************************************************************//**           		*   \brief	Initialize the game state.
*************************************************************************************/
void TestState::Init()
{

}

/*********************************************************************************//**
*   \brief	Clean any resource the state uses
*************************************************************************************/
void TestState::Clean()
{

}

/*********************************************************************************//**
*   \brief	This method handles input such as user input and events
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void TestState::HandleEvents(GU::Engin::Engin& engin, const int &deltaTime)
{
    if(m_Window.isOpen())
    {
        sf::Event event;

        while (m_Window.pollEvent(event))
        {
            handleSFEvent(engin, event);
        }

    }
}


/*********************************************************************************//**
*   \brief	This method handles input such as user input and events
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void TestState::Update(GU::Engin::Engin& engin, const int &deltaTime)
{
    if(!IsPaused())
    {
        //Do game logic
        m_World.Step(1/20, 8, 3);
        for(auto& element : m_Objects)
            element.update();

        m_DebugDraw.update();
//        b2Vec2 pos = dynamicBody->GetPosition();
//        std::cout << "x = " << toPixles(pos.x) << std::endl;
//        std::cout << "y = " << toPixles(pos.y) << std::endl;
    }
}


/*********************************************************************************//**
*   \brief	This method draws the current game state.
*	\param	engin is a reference to the game's Engin object.
*************************************************************************************/
void TestState::Draw(GU::Engin::Engin& engin, const int &deltaTime)
{
    m_Window.clear();
    m_Window.draw(m_DebugDraw);

    for(auto& element: m_Objects)
        m_Window.draw(element);

    m_Window.display();
}

void TestState::handleSFEvent(GU::Engin::Engin& engin, sf::Event event)
{
    switch (event.type)
    {

        case sf::Event::Closed:
            engin.Quit();
        break;
        case sf::Event::MouseButtonPressed:
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2f mousePos = getMousePosition(m_Window);
                b2Vec2 mPos = toMeters(mousePos);
                b2AABB box;
                box.lowerBound.Set(mPos.x, mPos.y);
                box.upperBound.Set(mPos.x +  0.000001, mPos.y + 0.000001);
                MouseJointCallback callback;
                m_World.QueryAABB(&callback, box);
                if(callback.m_Fixture && callback.m_Fixture->GetBody()->GetType() == b2BodyType::b2_dynamicBody)
                {
                    if(m_MouseJoint == nullptr)
                    {
                        b2MouseJointDef jointDef;
                        jointDef.bodyA = groundBody;
                        jointDef.bodyB = callback.m_Fixture->GetBody();
                        jointDef.target = mPos;
                        b2MouseJoint* joint = dynamic_cast<b2MouseJoint*>(m_World.CreateJoint(&jointDef));

                        if(joint)
                            m_MouseJoint = new MouseJoint(joint, &m_World);
                    }
                }
            }
        break;
        case sf::Event::MouseMoved:
            if(m_MouseJoint)
            {
                sf::Vector2f mousePos = getMousePosition(m_Window);
                m_MouseJoint->setMousePos(mousePos);
            }
        break;
        case sf::Event::MouseButtonReleased:
            if(m_MouseJoint)
            {
                delete m_MouseJoint;
                m_MouseJoint = nullptr;
            }

        break;
    }
}

