#include "EnginExampleState.h"
#include <iostream>
#include <SFML/Window/Event.hpp>

EnginExampleState::EnginExampleState(sf::RenderWindow &newWindow):
window(newWindow)
{

}


void EnginExampleState::init(std::shared_ptr<GU::Engin::Frame> frame)
{
    const float RADIUS = 50;
    circle.setFillColor(sf::Color::Green);
    circle.setPosition({400, 300});
    circle.setRadius(RADIUS);
    circle.setOrigin({RADIUS, RADIUS});
}


void EnginExampleState::clean(std::shared_ptr<GU::Engin::Frame> frame)
{

}


void EnginExampleState::handleEvents(GU::Engin::Engin& engin, const float &deltaTime, std::shared_ptr<GU::Engin::Frame> frame)
{
    if(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
    }
}



void EnginExampleState::update(GU::Engin::Engin& engin, const float &deltaTime, std::shared_ptr<GU::Engin::Frame> frame)
{

}


void EnginExampleState::draw(GU::Engin::Engin& engin, const float &deltaTime, std::shared_ptr<GU::Engin::Frame> frame)
{
    window.clear();
    window.draw(circle);
    window.display();
}
