#include <iostream>
#include "GameUtilities/Algorithm/SAT/SatObject.h"
#include <Math/Vector2.h>
#include <SFML/Graphics.hpp>
#include <iostream>
class Shape : public GU::Al::SatObject, public sf::Drawable
{
    public:
        /***********************************************************************************//**
        *   @brief  Constructor
        *   @param  position the center position of the shape in global coordinates.
        *   @param  points the number of vertices required to create the shape.
        ***************************************************************************************/
        Shape(const Math::Vector2<float> &position, const std::size_t &points);
        

        /***********************************************************************************//**
        *   @brief  Draw the shape to the render target. 
        *   @param  target is the render target where the shape will be drawn. 
        *   @param  states augments the way the target will be drawn 
        ***************************************************************************************/
        virtual void draw (sf::RenderTarget &target, sf::RenderStates states) const override;
        
        
        /***********************************************************************************//**
        *   @brief  This method changes the shapes location relative to it's current location. 
        *   @param  x will be added to the shapes current x axis position 
        *   @param  y will be added to the shapes current y axis position 
        ***************************************************************************************/
        void move(const int &x, const int &y);
        

        void setColor(const sf::Color &color);
        /***********************************************************************************//**
        *   @brief  This method does any per frame lagic. 
        ***************************************************************************************/
        virtual void update(); 
    protected:
        sf::ConvexShape m_shape;
};


/***********************************************************************************//**
*   @brief  Constructor
*   @param  position the center position of the shape in global coordinates.
*   @param  points the number of vertecies required to create the shape.
***************************************************************************************/
Shape::Shape(const Math::Vector2<float> &position, const std::size_t &points):
GU::Al::SatObject(position, points)
{
    m_shape.setPointCount(points);
}


/***********************************************************************************//**
*   @brief  Draw the shape to the render target. 
*   @param  target is the render target where the shape will be drawn. 
*   @param  states augments the way the target will be drawn 
***************************************************************************************/
void Shape::draw (sf::RenderTarget &target, sf::RenderStates states) const
{
   target.draw(m_shape); 
}


/***********************************************************************************//**
*   @brief  This method changes the shapes location relative to it's current location. 
*   @param  x will be added to the shapes current x axis position 
*   @param  y will be added to the shapes current y axis position 
***************************************************************************************/
void Shape::move(const int &x, const int &y)
{
    Math::Vector2<float> position = getPosition();
    position.x += x;
    position.y += y;
    setPosition(position);
}


void Shape::setColor(const sf::Color &color)
{
    m_shape.setFillColor(color);
}

/***********************************************************************************//**
*   @brief  This method does any per frame lagic. 
***************************************************************************************/
void Shape::update()
{
    m_shape.setPosition({getPosition().x, getPosition().y});
    for(std::size_t i = 0; i < getVertexCount(); ++i)
    {
        m_shape.setPoint(i, {getLocalCoordinate(i).x, getLocalCoordinate(i).y});
    }
}



class Square : public Shape 
{
    public:
        /***********************************************************************************//**
        *   @brief  Constructor
        *   @param  position the center position of the shape in global coordinates.
        *   @param  points the number of vertices required to create the shape.
        ***************************************************************************************/
        Square(const Math::Vector2<float> &position);
        

        /***********************************************************************************//**
        *   @brief  Destructor 
        ***************************************************************************************/
        virtual ~Square();

};


/***********************************************************************************//**
*   @brief  Constructor
*   @param  position the center position of the shape in global coordinates.
*   @param  points the number of vertices required to create the shape.
***************************************************************************************/
Square::Square(const Math::Vector2<float> &position):
Shape::Shape(position, 4)
{
    m_shape.setFillColor(sf::Color::Green);
}


/***********************************************************************************//**
*   @brief  Destructor 
***************************************************************************************/
Square::~Square()
{

}

class Triangle: public Shape 
{
    public:
        /***********************************************************************************//**
        *   @brief  Constructor
        *   @param  position the center position of the shape in global coordinates.
        *   @param  points the number of vertices required to create the shape.
        ***************************************************************************************/
        Triangle(const Math::Vector2<float> &position);
        

        /***********************************************************************************//**
        *   @brief  Destructor 
        ***************************************************************************************/
        virtual ~Triangle();

};


/***********************************************************************************//**
*   @brief  Constructor
*   @param  position the center position of the shape in global coordinates.
*   @param  points the number of vertices required to create the shape.
***************************************************************************************/
Triangle::Triangle(const Math::Vector2<float> &position):
Shape::Shape(position, 3)
{
    m_shape.setFillColor(sf::Color::Yellow);
}


/***********************************************************************************//**
*   @brief  Destructor 
***************************************************************************************/
Triangle::~Triangle()
{

}

int main()
{
    Square square(Math::Vector2<float>(100, 100));
    square.setLocalCoordinate(Math::Vector2<float>(0, 0), 0);
    square.setLocalCoordinate(Math::Vector2<float>(50, 0), 1);
    square.setLocalCoordinate(Math::Vector2<float>(50, 50), 2);
    square.setLocalCoordinate(Math::Vector2<float>(0, 50), 3);
    
    Triangle triangle(Math::Vector2<float>(100, 200));
    triangle.setLocalCoordinate(Math::Vector2<float>(0, -50), 0);
    triangle.setLocalCoordinate(Math::Vector2<float>(50, 0), 1);
    triangle.setLocalCoordinate(Math::Vector2<float>(-50,0), 2);

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    const int SPEED = 10;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if(event.type == sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    triangle.move(0, -SPEED);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    triangle.move(0, SPEED);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    triangle.move(-SPEED, 0);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    triangle.move(SPEED, 0);
                }

            } 
        }
        triangle.update();
        square.update();
        sf::ConvexShape line;
        
        if(triangle.intersects(square))
        {
            triangle.setColor(sf::Color::Red);
            square.setColor(sf::Color::Red);
        }
        else
        {
            triangle.setColor(sf::Color::Yellow); 
            square.setColor(sf::Color::Green);
        }

        window.clear();
        for(std::size_t i = 0; i < triangle.getEdgeCount(); ++i)
        {
            Math::Line<float> edge = triangle.getEdge(i);
            Math::Vector2<float> normal = edge.LeftNormal(); 
            line.setPointCount(3); 
            line.setPoint(0, {edge.m_End.x, edge.m_End.y});
            line.setPoint(1, {edge.m_End.x + 1, edge.m_End.y});
            line.setPoint(2, {edge.m_End.x + normal.x, edge.m_End.y + normal.y});
            line.setFillColor(sf::Color::Red);
            window.draw(line);
         
        }

        for(std::size_t i = 0; i < square.getEdgeCount(); ++i)
        {
            Math::Line<float> edge = square.getEdge(i);
            Math::Vector2<float> normal = edge.LeftNormal(); 
            line.setPointCount(3); 
            line.setPoint(0, {edge.m_End.x, edge.m_End.y});
            line.setPoint(1, {edge.m_End.x + 1, edge.m_End.y});
            line.setPoint(2, {edge.m_End.x + normal.x, edge.m_End.y + normal.y});
            line.setFillColor(sf::Color::Red);
            window.draw(line);
         
        }
        window.draw(square);
        window.draw(triangle);
        window.display();
    }

    return 0;
}
