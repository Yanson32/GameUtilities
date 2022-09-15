#include "ExampleFrame.h"

ExampleFrame::ExampleFrame()
{

}

void ExampleFrame::init()
{
    const float RADIUS = 50;
    circle.setFillColor(sf::Color::Green);
    circle.setPosition({400, 300});
    circle.setRadius(RADIUS);
    circle.setOrigin({RADIUS, RADIUS});
}


void ExampleFrame::clean()
{

}


void ExampleFrame::handleEvents(GU::Engin::Engin& engin, const float &deltaTime)
{

}


void ExampleFrame::update(GU::Engin::Engin& engin, const float &deltaTime)
{

}


void ExampleFrame::draw(GU::Engin::Engin& engin, const float &deltaTime)
{

}

ExampleFrame::~ExampleFrame()
{

}
