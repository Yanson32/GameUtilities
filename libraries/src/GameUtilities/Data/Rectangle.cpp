#include "GameUtilities/Data/Rectangle.h"
#include "GameUtilities/Data/AABB.h"

namespace GU
{
    namespace Data
    {
        /****************************************************************************************
        *   @purpose    Constructor.
        *   @param      origin the starting point of the rectangle.
        *   @param      width the width of the rectangle.
        *   @param      height the height of the rectangle.
        *   @param      angle is the angle of the rectangle. 
        ****************************************************************************************/
        Rectangle::Rectangle(const Math::Vector2<float> &origin, const float &width, const float &height, const float &angle):
        m_origin(origin),
        m_width(width),
        m_height(height),
        m_angle(angle)
        {

        }

        
        /****************************************************************************************
        *   @purpose    This method checks if the two rectangles are overlapping. 
        *   @param      rectangle is checked to determine if the two rectangles are intersecting.
        *   @return     True if the two rectangles are intersecting and false otherwise. 
        ****************************************************************************************/
        bool Rectangle::intersects(const Rectangle &rectangle) const
        {
            //If this rectangle is to the left of the input rectangle 
            if((m_origin.x + m_width) < rectangle.m_origin.x)
                return false;

            //If this rectangle is to the right of the input rectangle 
            if((m_origin.x) > (rectangle.m_origin.x  + rectangle.m_width))
                return false;

            //If this rectangle is above the input rectangle 
            if((m_origin.y + m_height) < (rectangle.m_origin.y))
                return false;

            //If this rectangle is below the input rectangle 
            if((m_origin.y) < (rectangle.m_origin.y + rectangle.m_height))
                return false;

            return true;
        }

        
        /****************************************************************************************
        *   @purpose    This method checks if the rectangle overlaps a bounding box. 
        *   @param      aabb is checked to determine if it is overlapping the rectangle.  
        *   @return     True if the rectangle and AABB  are intersecting and false otherwise. 
        ****************************************************************************************/
        bool Rectangle::intersects(const AABB &aabb) const
        {
            //If this rectangle is to the left of the input bounding box 
            if((m_origin.x + m_width) < aabb.m_origin.x - (aabb.m_width / 2.0))
            {
                return false;
            }

            //If this rectangle is to the right of the input bounding box 
            if((m_origin.x) > (aabb.m_origin.x + (aabb.m_width / 2.0)))
            {
                return false;
            }
            //If this rectangle is above the input bounding box 
            if((m_origin.y + m_height) < (aabb.m_origin.y - (aabb.m_height / 2.0)))
            {
                return false;
            }
            //If this rectangle is below the input bounding box 
            if((m_origin.y) > (aabb.m_origin.y + (aabb.m_height / 2.0)))
            {
                return false;
            }

            return true;

        }

        
        /****************************************************************************************
        *   @purpose    Destructor 
        ****************************************************************************************/
        Rectangle::~Rectangle()
        {

        }
    }
}
