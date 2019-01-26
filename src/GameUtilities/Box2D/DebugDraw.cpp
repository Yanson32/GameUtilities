#include "DebugDraw.h"

#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>


#include <Box2D/Common/b2Math.h>

#include <cassert>
#include <algorithm>
#include <iostream>
#include <cstddef> //std::size_t
#include <vector>
namespace
{
    /**********************************************************************************************
    *   @brief    This method converts a circle to points along the circumference of the circle.
    *   @param    const b2Vec2& the center of the circle.
    *             float32 the radius of the circle.
    *             const unsigned the number of points around the circumference to be created.
    *   @param    std::vector<b2Vec2> a vector of points along the circumference.
    **********************************************************************************************/
    std::vector<b2Vec2> getPoints(const b2Vec2& center, float32 radius, const unsigned pointCount);



    /**********************************************************************************************
    *   @brief    Create a bounding box for a view.
    *   @param      const sf::View the view that we want to create a bounding box for.
    *   @return     sf::FloatRect represents the bounding box for the input view.
    **********************************************************************************************/
    sf::FloatRect getBounds(const sf::View &view);


    /****************************************************************************************
    *   @brief    This converts a box2d color object to an SFML color object.
    *   @param      const b2Color &color this parameter is a box2d color which will be
    *               converted to an SFML color.
    *               int alpha this parameter represents the alpha (opacity) of the color.
    *   @return     sf::Color object which is created from the input parameters.
    ****************************************************************************************/
    sf::Color toSfColor(const b2Color &color, int alpha = 255);


    /****************************************************************************************
    *   @brief    This function creates a bounding box for a line segment.
    *   @param      const sf::Vector2f the first point of the line.
    *               const sf::Vector2f the second point of the line.
    *   @return     sf::FloatRect the bounding rectangle for the line
    ****************************************************************************************/
    sf::FloatRect getBounds(const sf::Vector2f first, const sf::Vector2f second);
}


    /****************************************************************************************************
    *   @brief    This method is a constructor.
    *   @param      sf::RenderWindow &newWindow this is the window where the Box2D bodies will be drawn
    ****************************************************************************************************/
	DebugDraw::DebugDraw(sf::RenderWindow &newWindow, const float newPixelsPerMeter): window(newWindow), pixelsPerMeter(newPixelsPerMeter)
    {
        lines.setPrimitiveType(sf::Lines);
        triangles.setPrimitiveType(sf::Triangles);
    }


    /*******************************************************************************************************************
    *   @brief    This method draws axis alligned bounding boxes.
    *   @param      b2Vec2* vertices which is an array of verticies.
    *               int32 vertexCount the number of vertices in the vertices parameter.
    *               const b2Color which is the color the axis aligned bounding box should be drawn with
    *   pre:        This class must first be registered with a box2d world object.
    *               The e_aabbBit must be set.
    *******************************************************************************************************************/
    void DebugDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
    {
        for(int i = 0; i < vertexCount - 1; ++i)
        {
            DrawSegment(vertices[i], vertices[i + 1], color);
        }

        DrawSegment(vertices[vertexCount - 1], vertices[0], color);
    }


    /*******************************************************************************************************************
    *   @brief    This method draws axis alligned bounding boxes.
    *   @param      b2Vec2* vertices which is an array of verticies.
    *               int32 vertexCount the number of vertices in the vertices parameter.
    *               const b2Color which is the color the axis aligned bounding box should be drawn with
    *   pre:        This class must first be registered with a box2d world object.
    *               The e_aabbBit must be set.
    *******************************************************************************************************************/
    void DebugDraw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
    {
        const sf::Color COLOR = toSfColor(color);

        for(int i = 0; i < vertexCount - 2; ++i)
        {
            sf::Vertex vertA;
            vertA.position = this->toPixels(vertices[i]);
            vertA.color = COLOR;
            triangles.append(vertA);

            sf::Vertex vertB;
            vertB.position = this->toPixels(vertices[i + 1]);
            vertB.color = COLOR;
            triangles.append(vertB);

            sf::Vertex vertC;
            vertC.position = this->toPixels(vertices[i + 2]);
            vertC.color = COLOR;
            triangles.append(vertC);
        }


        sf::Vertex vertA;
        vertA.position = this->toPixels(vertices[vertexCount - 2]);
        vertA.color = COLOR;

        sf::Vertex vertB;
        vertB.position = this->toPixels(vertices[vertexCount - 1]);
        vertB.color = COLOR;

        sf::Vertex vertC;
        vertC.position = this->toPixels(vertices[0]);
		vertC.color = COLOR;

        triangles.append(vertA);
        triangles.append(vertB);
        triangles.append(vertC);
    }


    /*******************************************************************************************************************
    *   @brief    This method draws the outline of a circle.
    *   @param      const b2Vec2& center this parameter is the center of the circle.
    *               float32 radius this parameter is the radius of the circle.
    *               const b2Color& color this parameter is the color that the circle will be drawn with
    *   Pre:        This class must first be registered with a box2d world object.
    *******************************************************************************************************************/
    void DebugDraw::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color)
    {
        const unsigned      POINT_COUNT = 10 + radius;
        std::vector<b2Vec2> points = getPoints(center, radius, POINT_COUNT);
        assert(points.size() != 0);

        for(std::size_t i = 0; i < points.size() - 1; ++i)
        {
            DrawSegment(points[i], points[i + 1], color);
        }

        DrawSegment(points[points.size() - 1], points[0], color);
    }


    /*******************************************************************************************************************
    *   @brief    This method draws circle objects. The circle will be drawn as a circle filled with color.
    *               float32 radius this is the radius of the circle.
    *               const b2Vec2 axis is a direction vector relative to the center of the circle. The axis parameter must
    *               be scaled by the radius of the circle to compensate for the diameter of the circle.
    *               const b2Color color this is the color the circle will be drawn in.
    *   Pre:        This class must first be registered with a box2d world object.
    *               The e_shapeBit must be set.
    ********************************************************************************************************************/
    void DebugDraw::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color)
    {
        const unsigned POINT_COUNT = (10 + static_cast<int>(radius));
        const sf::Color COLOR = toSfColor(color);


        //Draw the circle
        sf::Vector2f CENTER_POINT = this->toPixels(center);
        std::vector<b2Vec2> points = getPoints(center, radius, POINT_COUNT);

        assert(points.size() != 0);
        for(std::size_t i = 0; i < points.size() - 1; ++i)
        {
            sf::Vertex vertA;
            vertA.position = CENTER_POINT;
            vertA.color = COLOR;

            sf::Vertex vertB;
			vertB.position = this->toPixels(points[i]);
            vertB.color = COLOR;

            sf::Vertex vertC;
            vertC.position = this->toPixels(points[i + 1]);
            vertC.color = COLOR;

            triangles.append(vertA);
            triangles.append(vertB);
            triangles.append(vertC);
        }


        sf::Vertex vertA;
        vertA.position = CENTER_POINT;
        vertA.color = COLOR;

        sf::Vertex vertB;
        vertB.position = this->toPixels(points[points.size() - 1]);
        vertB.color = COLOR;

        sf::Vertex vertC;
        vertC.position = this->toPixels(points[0]);
        vertC.color = COLOR;

        triangles.append(vertA);
        triangles.append(vertB);
        triangles.append(vertC);
    }



    /*******************************************************************************************************************
    *   @brief    This method draws a line segment to the screen.
    *   @param      const b2Vec2 p1 this is the first point of the line segment.
    *               const b2Vec2 p2 this is the second point of the line segment.
    *               const b2Color color this is a struct that defines the blue, green, red color values.
    *   Pre:        This class must first be registered with a box2d world object.
    *               The e_shapeBit must be set.
    *******************************************************************************************************************/
    void DebugDraw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
    {
        //Convert Box2D parameters to SFML
        const sf::Color     COLOR           = toSfColor(color);
        const sf::Vector2f  FIRST_POINT     = this->toPixels(p1);
        const sf::Vector2f  SECOND_POINT    = this->toPixels(p2);

        //Make sure one of the points is on the screen
        //if(viewBounds.contains(FIRST_POINT) || viewBounds.contains(SECOND_POINT))
        //if(viewBounds.intersects(getBounds(FIRST_POINT, SECOND_POINT)))
        {
            //Allocate memory if needed
            if(lines.getVertexCount() - linesUsed < 2)
                lines.resize(lines.getVertexCount() + 2);


            //Create two points
            sf::Vertex vertA;
            vertA.position      = FIRST_POINT;
            vertA.color         = COLOR;

            sf::Vertex vertB;
            vertB.position      = SECOND_POINT;
            vertB.color         = COLOR;

            //Add points to lines VertexArray
            lines[linesUsed]    = vertA;
            ++linesUsed;
            lines[linesUsed]    = vertB;
            ++linesUsed;
        }
    }


    /*******************************************************************************************************************
    *   @brief    This method draws a transform to the screen when the e_centerOfMassBit is set.
    *   @param      const b2Transform xf which is the transform to be drawn to the screen.
    *   Pre:        This class must first be registered with a box2d world object.
    *               The e_centerOfMassBit must be set or the function won't be called
    *******************************************************************************************************************/
    void DebugDraw::DrawTransform(const b2Transform& xf)
    {
        const float32 LENGTH            = 0.2f;
        const b2Vec2 CENTER_POINT       = (xf.p);
        const b2Vec2 HORIZONTAL_POINT   = (xf.p + (LENGTH * xf.q.GetXAxis()));
        const b2Vec2 VERTICAL_POINT     = (xf.p + (LENGTH * xf.q.GetYAxis()));


        //Draw transform
        DrawSegment(CENTER_POINT, HORIZONTAL_POINT, b2Color(0, 1, 0));
        DrawSegment(CENTER_POINT, VERTICAL_POINT, b2Color(1, 0, 0));
    }


    /*******************************************************************************************************************
    *   @brief    This method does per frame logic and must be called once per frame.
    *******************************************************************************************************************/
    void DebugDraw::update()
    {
        triangles.resize(0);
        lines.resize(linesUsed);
        linesUsed = 0;
        //viewBounds = getBounds(window.getView());
    }

    /*******************************************************************************************************************
    *   @brief    This method converts b2Vec2 in box2d meters to sf::Vector2f in pixles.
    *   @param      const b2Vec2 the point in box2d meters.
    *   @return     sf::Vector2f the point in pixles.
    *******************************************************************************************************************/
    sf::Vector2f DebugDraw::toPixels(const b2Vec2 &vec)
    {
        sf::Vector2f temp;
        temp.x = this->toPixels(vec.x);
        temp.y = this->toPixels(vec.y);
        return temp;
    }


    /*******************************************************************************************************************
    *   @brief    This method converts float32 in box2d meters to float32 in pixles.
    *   @param      const float32 in meters
    *   @return     float32 in pixles.
    *******************************************************************************************************************/
    float32 DebugDraw::toPixels(const float32 meters)
    {
        return meters * pixelsPerMeter;
    }


    /****************************************************************************************************
    *   @brief    This method draws all box2d objects to the screen.
    *   @param      sf::RenderTarget the window or other render target where the objects will be drawn.
    *               sf::RenderStates struct that contains different rendering properties.
    *   side:       modifies the target by drawing to it
    ****************************************************************************************************/
    void DebugDraw::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(triangles);
        target.draw(lines);
    }


    /*******************************************************************************************************************
    *   @brief  Destructor
    *******************************************************************************************************************/
    DebugDraw::~DebugDraw()
    {
        //dtor
    }

namespace
{
    /**********************************************************************************************
    *   @brief    This method converts a circle to points along the circumference of the circle.
    *   @param      const b2Vec2& the center of the circle.
    *               float32 the radius of the circle.
    *               const unsigned the number of points around the circumference to be created.
    *   @return     std::vector<b2Vec2> a vector of points along the circumference.
    **********************************************************************************************/
    std::vector<b2Vec2> getPoints(const b2Vec2& center, float32 radius, const unsigned pointCount)
    {
        static const float PIE = 3.141592654f;
        static const float TAU = 2 * PIE;
        std::vector<b2Vec2> tempVec;


        for(unsigned i = 1; i <= pointCount; ++i)
        {
            b2Vec2 point;
            float angle = i * TAU / pointCount;
            point.x = center.x + (cos(angle) * radius);
            point.y = center.y + (sin(angle) * radius);
            tempVec.push_back(point);
        }

        return tempVec;
    }


    /****************************************************************************************
    *   @brief    This converts a box2d color object to an SFML color object.
    *   @param      const b2Color &color this parameter is a box2d color which will be
    *               converted to an SFML color.
    *               int alpha this parameter represents the alpha (opacity) of the color.
    *   @return     sf::Color object which is created from the input parameters.
    ****************************************************************************************/
    sf::Color toSfColor(const b2Color &color, int alpha)
    {
        return sf::Color (color.r * 255, color.g * 255, color.b * 255);
    }


    /****************************************************************************************
    *   @brief  This function creates a bounding box for a line segment.
    *   @param  const sf::Vector2f the first point of the line.
    *   @param  const sf::Vector2f the second point of the line.
    *   @return sf::FloatRect the bounding rectangle for the line
    ****************************************************************************************/
    sf::FloatRect getBounds(const sf::Vector2f first, const sf::Vector2f second)
    {
        //sf::FloatRect rt;
        //rt.left = view.getCenter().x - view.getSize().x / 2.0f;
        //rt.top = view.getCenter().y - view.getSize().y / 2.0f;
        //rt.width = view.getSize().x;
        //rt.height = view.getSize().y;
		return sf::FloatRect();
    }
}
