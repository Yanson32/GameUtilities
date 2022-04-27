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
    const unsigned INDEX = 1;
    square[INDEX].x = 7;
    std::cout << "The x coordinate at index " << INDEX <<  " is " << square[INDEX].x << std::endl;
    std::cout << "Hello World!" << std::endl;
    return 0;
}
