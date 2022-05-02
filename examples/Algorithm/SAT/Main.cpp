#include <iostream>
#include "GameUtilities/Algorithm/SAT/SatObject.h"
class Square : public GU::Al::SatObject 
{
    public:
        Square(const unsigned points);
        virtual ~Square();
};

Square::Square(const unsigned points):
GU::Al::SatObject(points)
{

}


Square::~Square()
{

}

int main()
{
    Square square(4);
    square[0] = Math::Vector2<float>(0, 0);
    square[1] = Math::Vector2<float>(10, 0);
    square[2] = Math::Vector2<float>(10, 10);
    square[3] = Math::Vector2<float>(0, 10);
    
    std::cout << "The number of points in the sat object " << square.getVertexCount() << std::endl;
    const unsigned INDEX = 1;
    std::cout << "The x coordinate at index " << INDEX <<  " is " << square[INDEX].x << std::endl;
    std::cout << "Hello World!" << std::endl;
    return 0;
}
