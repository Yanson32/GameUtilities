#include "GameUtilities/Window/Window.h"
#include <Math/Vector2.h>
int main()
{
    Math::Vector2<float> size(400, 400);
    GU::Win::Window win(size);
    return 0;
}
