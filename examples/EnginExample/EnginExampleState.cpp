#include "EnginExampleState.h"
#include <iostream>
#include <SFML/Window/Event.hpp>

EnginExampleState::EnginExampleState(sf::RenderWindow &newWindow):
window(newWindow)
{

}
void EnginExampleState::init()
{
    const float RADIUS = 50;
    circle.setFillColor(sf::Color::Green);
    circle.setPosition({400, 300});
    circle.setRadius(RADIUS);
    circle.setOrigin({RADIUS, RADIUS});
}


void EnginExampleState::clean()
{

}


void EnginExampleState::handleEvents(EnginPtr engin, const float &deltaTime)
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
                    engin->quit();
                    break;
            }
        }
    }
}



void EnginExampleState::update(EnginPtr engin, const float &deltaTime)
{

}


void EnginExampleState::draw(EnginPtr engin, const float &deltaTime)
{
    window.clear();
    window.draw(circle);
    window.display();
}
