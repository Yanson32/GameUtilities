#include <iostream>
#include "GameUtilities/Data/QuadTree.h"
#include "GameUtilities/Data/Rectangle.h"
#include "GameUtilities/Data/PhysicsObject.h"
#include "GameUtilities/Data/AABB.h"
#include "GameUtilities/Core/Macros.h"
#include "Math/Vector2.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cassert>
#include "Math/Vector2.h"

class Ball: public GU::Data::PhysicsObject, public sf::Drawable
{
    public:
        Ball(const int radius);
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        void setPosition(const float &width, const float &height);
        Math::Vector2<float> getPosition() const;
        Math::Vector2<float> getVelocity() const;
        void setVelocity(const float &xVelocity, const float &yVelocity); 
        void update();
        void setColor(const sf::Color &color); 
        virtual GU::Data::AABB getBounds() const;
        float getRadius() const;
        virtual ~Ball();
    public:
        sf::CircleShape m_circle;
        Math::Vector2<float> m_velocity;
};


Ball::Ball(const int radius)
{
    m_circle.setRadius(radius);
    m_circle.setFillColor(sf::Color::Green);
    m_circle.setOrigin({m_circle.getOrigin().x + (radius), m_circle.getOrigin().y + (radius)});
}


float Ball::getRadius() const
{
    return m_circle.getRadius();
}


void Ball::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_circle, states); 
}


GU::Data::AABB Ball::getBounds() const
{
    GU::Data::AABB bounds({m_circle.getPosition().x, m_circle.getPosition().y}, m_circle.getRadius() * 2, m_circle.getRadius() * 2);
    return bounds;
}


void Ball::setPosition(const float &width, const float &height)
{
    m_circle.setPosition({width, height});
}


Math::Vector2<float> Ball::getPosition() const
{
    return {m_circle.getPosition().x, m_circle.getPosition().y};
}


Math::Vector2<float> Ball::getVelocity() const
{
    return m_velocity;
}


void Ball::setVelocity(const float &xVelocity, const float &yVelocity)
{
    m_velocity = Math::Vector2<float>(xVelocity, yVelocity);
}


void Ball::setColor(const sf::Color &color)
{
    m_circle.setFillColor(color);
}


void Ball::update()
{
    Math::Vector2<float> newPosition = Math::Vector2<float>({m_circle.getPosition().x + m_velocity.x, m_circle.getPosition().y + m_velocity.y}); 
    m_circle.setPosition({newPosition.x, newPosition.y});
}


Ball::~Ball()
{

}



int main()
{
    const float windowWidth = 800;
    const float windowHeight = 600;
    Math::Vector2<float> origin(windowWidth / 2, windowHeight / 2);
    const int MAX_OBJECTS = 3; 
    sf::Color backGroundColor = sf::Color::White;
    GU::Data::AABB queryRect(Math::Vector2<float>(200, 200), 100, 100);
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "QuadTree EXample");
    std::vector<std::shared_ptr<Ball>> balls;
    balls.push_back(std::shared_ptr<Ball>(new Ball(10)));
    balls[0]->setPosition(0, 0); 
    balls[0]->setVelocity(1, 1); 
    balls.push_back(std::shared_ptr<Ball>(new Ball(10)));
    balls[1]->setPosition(400, 400); 
    balls[1]->setVelocity(-1, -1); 
    balls.push_back(std::shared_ptr<Ball>(new Ball(10)));
    balls[2]->setPosition(150, 600); 
    balls[2]->setVelocity(-1, 1); 
    balls.push_back(std::shared_ptr<Ball>(new Ball(10)));
    balls[3]->setPosition(700, 300); 
    balls[3]->setVelocity(1, -1); 
    balls.push_back(std::shared_ptr<Ball>(new Ball(10)));
    balls[4]->setPosition(400, 300); 
    balls[4]->setVelocity(-1, -1); 
    balls.push_back(std::shared_ptr<Ball>(new Ball(10)));
    balls[5]->setPosition(400, 0); 
    balls[5]->setVelocity(1, -1); 
    balls.push_back(std::shared_ptr<Ball>(new Ball(10)));
    balls[6]->setPosition(100, 100); 
    balls[6]->setVelocity(1, -1); 
    balls.push_back(std::shared_ptr<Ball>(new Ball(10)));
    balls[7]->setPosition(400, 400); 
    balls[7]->setVelocity(1, 1); 
    balls.push_back(std::shared_ptr<Ball>(new Ball(10)));
    balls[8]->setPosition(250, 600); 
    balls[8]->setVelocity(-1, -1); 
    balls.push_back(std::shared_ptr<Ball>(new Ball(10)));
    balls[9]->setPosition(250, 600); 
    balls[9]->setVelocity(1, 1); 
    balls.push_back(std::shared_ptr<Ball>(new Ball(10)));
    balls[10]->setPosition(600, 500); 
    balls[10]->setVelocity(1, 1); 


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        GU::Data::QuadTree quad(origin, windowWidth, windowHeight, 1, MAX_OBJECTS, 4);
        //Insert balls into quadtree 
        for(auto &element : balls)
            element->setColor(sf::Color::Green); 
        
        //Insert balls into quadtree 
        for(auto &element : balls)
            quad.insert(element); 
      
         
        //Update all balls 
        for(auto &element : balls)
           element->update(); 
     
         
        std::vector<std::shared_ptr<GU::Data::PhysicsObject>> results = quad.query(queryRect);
        for(auto &element : results)
        {
            std::shared_ptr<Ball> ball = std::dynamic_pointer_cast<Ball>(element); 
            if(ball)
                ball->setColor(sf::Color::Red);
        }
        
        for(auto &element : balls)
        {
            std::vector<std::shared_ptr<GU::Data::PhysicsObject>> result = quad.query(element->getBounds());

            for(auto &object: result)
            {
                std::shared_ptr<Ball> ball = std::dynamic_pointer_cast<Ball>(object); 
                if(ball && ball != element)
                    ball->setColor(sf::Color::Red);
            }
        } 
        

        //Change direction of balls if they are off screen 
        for(auto &element : balls)
        {
            int x = element->getPosition().x;
            int y = element->getPosition().y;
            if(x > windowWidth || x < 0)
                element->setVelocity(element->getVelocity().x * -1, element->getVelocity().y);
            if(y > windowHeight || y < 0)
                element->setVelocity(element->getVelocity().x, element->getVelocity().y * -1);
            
        }
 
        window.clear(backGroundColor);
        std::vector<GU::Data::AABB> bounds = quad.getAllBounds();       
        
        for(auto &element : bounds)
        {
            sf::RectangleShape rect;
            rect.setOutlineColor(sf::Color::Black);
            rect.setOutlineThickness(1);
            rect.setSize({static_cast<float>(element.m_width), static_cast<float>(element.m_height)});
            rect.setOrigin({static_cast<float>(element.m_width) / 2.0f, static_cast<float>(element.m_height) / 2.0f}); 
            rect.setPosition({element.m_origin.x, element.m_origin.y});
            window.draw(rect);
        }

        //Draw all balls to the screen 
        for(auto &element : balls)
            window.draw(*element); 
      

        //Draw ball bounding boxes to the screen
        for(auto &element : balls)
        {
            sf::RectangleShape rect;
            rect.setOutlineColor(sf::Color::Black);
            rect.setOutlineThickness(1);
            rect.setFillColor(sf::Color::Transparent);
            GU::Data::Rectangle bounds = element->getBounds().asRectangle(); 
            rect.setPosition({bounds.m_origin.x, bounds.m_origin.y});
            rect.setSize({bounds.m_width, bounds.m_height});
            window.draw(rect);
            
        } 
        GU::Data::Rectangle testRect = queryRect.asRectangle();
        sf::RectangleShape sfTestRect;
        sfTestRect.setFillColor(sf::Color(0, 0, 255, 100));
        sfTestRect.setPosition({testRect.m_origin.x, testRect.m_origin.y});
        sfTestRect.setSize({testRect.m_width, testRect.m_height});
        window.draw(sfTestRect);
        window.display();
        sf::sleep(sf::microseconds(5000)); 
    }
}
