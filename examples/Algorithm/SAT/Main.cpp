#include <iostream>
#include "GameUtilities/Algorithm/SAT/SatObject.h"
#include <Math/Vector2.h>

class Square : public GU::Al::SatObject 
{
    public:
        Square(const unsigned points);
        virtual ~Square();
};

Square::Square(const unsigned points):
GU::Al::SatObject(Math::Vector2<float>(0, 0), points)
{

}


Square::~Square()
{

}

int main()
{
    Square square(4);
    square.setLocalCoordinate(Math::Vector2<float>(0, 0), 0);
    square.setLocalCoordinate(Math::Vector2<float>(10, 0), 1);
    square.setLocalCoordinate(Math::Vector2<float>(10, 10), 2);
    square.setLocalCoordinate(Math::Vector2<float>(0, 10), 3);
    
    std::cout << "The number of points in the sat object " << square.getVertexCount() << std::endl;
    const unsigned INDEX = 1;
    std::cout << "The x coordinate at index " << INDEX <<  " is " << square.getLocalCoordinate(INDEX).x << std::endl;
    std::cout << "Hello World!" << std::endl;
    return 0;
}
