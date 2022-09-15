#ifndef EXAMPLE_FRAME_H
#define EXAMPLE_FRAME_H
#include "GameUtilities/Engin/Frame.h"
#include <SFML/Graphics.hpp>
class ExampleFrame: public GU::Engin::Frame
{
    public:
        ExampleFrame();
        virtual void init() override;
        virtual void clean() override;
        virtual void handleEvents(GU::Engin::Engin& engin, const float &deltaTime) override;
        virtual void update(GU::Engin::Engin& engin, const float &deltaTime) override;
        virtual void draw(GU::Engin::Engin& engin, const float &deltaTime) override;
        virtual ~ExampleFrame();
    public:      
        sf::CircleShape circle;
};
#endif
