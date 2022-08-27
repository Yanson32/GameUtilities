#include <iostream>
#include "GameUtilities/Algorithm/SAT/SatObject.h"
#include "GameUtilities/Algorithm/SAT/SAT.h"
#include <Math/Vector2.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cassert>

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
        

        /***********************************************************************************//**
        *   @brief  This method changes the color of the shape
        *   @param  color is the color the shape will be displayed with.
        ***************************************************************************************/
        void setColor(const sf::Color &color);
        

        /***********************************************************************************//**
        *   @brief  This method does any per frame lagic. 
        ***************************************************************************************/
        virtual void update(); 
        

        /***********************************************************************************//**
        *   @brief  This method changes the current position of the shape 
        *   @param  position is the new position of the shape 
        ***************************************************************************************/
        void setPosition(const Math::Vector2<float> &position);
        

        /***********************************************************************************//**
        *   @brief  This method return the current position of the shape.
        *   @return The current position of the shape. 
        ***************************************************************************************/
        Math::Vector2<float> getPosition() const;
        
        
        /********************************************************************//**
        *   @brief  This method sets a coordiante at the index specified in
        *           global coordinates. The coordinate will be translated to 
        *           local coordinates. 
        *   @param  coordinate is the new coordinate value in global coordinates 
        *   @param  index is the current index of the coordinate to be updated. 
        ************************************************************************/
        void  setGlobalCoordinate(const Math::Vector2<float> &coordinate, const std::size_t &index);
        
        
        /********************************************************************//**
        *   @brief  This method returns a coordinate at the index specified. In
        *           global coordinates.  
        *   @param  index The current index of the coordinated stored internally 
        *           to the SatObject.  
        *   @return A coordinate at the index specified in global coordinates.
        ************************************************************************/
        Math::Vector2<float> getGlobalCoordinate(const std::size_t &index) const;

        
        /********************************************************************//**
        *   @brief  This method sets a coordinate in local coordinates. The
        *           coordinate will not be translated to local coordinates.
        *   @param  coordinate The new value of coordinate at the index specified
        *           in local coordinates 
        *   @param  index is the index of the coordinate to be replaced.
        ************************************************************************/
        void  setLocalCoordinate(const Math::Vector2<float> &coordinate, const std::size_t &index);
        

        /********************************************************************//**
        *   @brief  This method returns the coordinate at the specified index
        *           In local coordinates.  
        *   @param  index is the current index of the coordinate. 
        *   @return The coordinate at the specified index in local coordinates.
        ************************************************************************/
        Math::Vector2<float> getLocalCoordinate(const std::size_t &index) const;
        

        /********************************************************************//**
        *   @brief  This method determines if tow SatObjects are colliding.
        *   @return True if the SatObjects are colliding. 
        ************************************************************************/
        bool intersects(const SatObject &object);
        std::size_t getVertexCount() const;
        std::size_t getEdgeCount() const;
        Math::Line<float> getEdge(const std::size_t &index) const;
    protected:
        sf::ConvexShape m_shape;
        Math::Vector2<float> m_position;
};


/***********************************************************************************//**
*   @brief  Constructor
*   @param  position the center position of the shape in global coordinates.
*   @param  points the number of vertecies required to create the shape.
***************************************************************************************/
Shape::Shape(const Math::Vector2<float> &position, const std::size_t &points):m_position(position)
{
    m_shape.setPointCount(points);
}



/***********************************************************************************//**
*   @brief  This method changes the current position of the shape 
*   @param  position is the new position of the shape 
***************************************************************************************/
void Shape::setPosition(const Math::Vector2<float> &position)
{
    m_position = position;
}


/***********************************************************************************//**
*   @brief  This method return the current position of the shape.
*   @return The current position of the shape. 
***************************************************************************************/
Math::Vector2<float> Shape::getPosition() const
{
    return m_position;
}


/********************************************************************//**
*   @brief  This method sets a coordiante at the index specified in
*           global coordinates. The coordinate will be translated to 
*           local coordinates. 
*   @param  coordinate is the new coordinate value in global coordinates 
*   @param  index is the current index of the coordinate to be updated. 
************************************************************************/
void  Shape::setGlobalCoordinate(const Math::Vector2<float> &coordinate, const std::size_t &index)
{
    assert(index >= 0 && index < getVertexCount());
    Math::Vector2<float> temp = m_position - coordinate;
    temp.x = -temp.x;
    temp.y = -temp.y; 
    m_shape.setPoint(index, {temp.x, temp.y}); 
}


/********************************************************************//**
*   @brief  This method returns a coordinate at the index specified. In
*           global coordinates.  
*   @param  index The current index of the coordinated stored internally 
*           to the SatObject.  
*   @return A coordinate at the index specified in global coordinates.
************************************************************************/
Math::Vector2<float> Shape::getGlobalCoordinate(const std::size_t &index) const
{
    assert(index >= 0 && index < getVertexCount());

    return getLocalCoordinate(index) + m_position; 
}


/********************************************************************//**
*   @brief  This method sets a coordinate in local coordinates. The
*           coordinate will not be translated to local coordinates.
*   @param  coordinate The new value of coordinate at the index specified
*           in local coordinates 
*   @param  index is the index of the coordinate to be replaced.
************************************************************************/
void  Shape::setLocalCoordinate(const Math::Vector2<float> &coordinate, const std::size_t &index)
{
   assert(index >= 0 && index < getVertexCount()); 

    m_shape.setPoint(index, {coordinate.x, coordinate.y});
}


/********************************************************************//**
*   @brief  This method returns the coordinate at the specified index
*           In local coordinates.  
*   @param  index is the current index of the coordinate. 
*   @return The coordinate at the specified index in local coordinates.
************************************************************************/
Math::Vector2<float>  Shape::getLocalCoordinate(const std::size_t &index) const
{
    assert(index >= 0 && index < getVertexCount());

    return {m_shape.getPoint(index).x, m_shape.getPoint(index).y};
}


/********************************************************************//**
*   @brief  This method returns the number of  vertices that make up the
*           SAT object. 
*   @return The number of vertices that make up the SAT object. 
************************************************************************/
std::size_t Shape::getVertexCount() const
{
    return m_shape.getPointCount();
}

 
/********************************************************************//**
*   @brief  This method returns the number of edges that make up the
*           SAT object.
*   @return The number of edges that make up the SAT object.
************************************************************************/
std::size_t Shape::getEdgeCount() const
{
    return m_shape.getPointCount(); 
}


/********************************************************************//**
*   @brief  This method determines if tow SatObjects are colliding.
*   @return True if the SatObjects are colliding. 
************************************************************************/
bool Shape::intersects(const SatObject &object)
{
    return satIntersects(*this, object);
}


/********************************************************************//**
*   @brief  This method returns the edge at the given index.
*   @param  index The index of the edge to be returned. 
*   @return A Line object representing the edge at index. 
************************************************************************/
Math::Line<float> Shape::getEdge(const std::size_t &index) const
{
    if(index < getVertexCount() - 1)
    {
        Math::Vector2 start(getGlobalCoordinate(index));
        Math::Vector2 end(getGlobalCoordinate(index + 1));
        return Math::Line<float>(start, end);
    }
    else if(index == getVertexCount() - 1)
    {
        Math::Vector2 start(getGlobalCoordinate(index));
        Math::Vector2 end(getGlobalCoordinate(0));
        return Math::Line<float>(start, end);
    }
        
    throw std::runtime_error("SatObject::getEdge index out of range");
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


/***********************************************************************************//**
*   @brief  This method changes the color of the shape
*   @param  color is the color the shape will be displayed with.
***************************************************************************************/
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
    triangle.setPosition({300,  300});

    sf::RenderWindow window(sf::VideoMode(800, 600), "SAT EXample");
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

        /*
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
        */
        window.draw(square);
        window.draw(triangle);
        window.display();
    }

    return 0;
}
