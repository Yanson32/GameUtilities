#include "EnginExampleState.h"
#include <iostream>
#include <SFML/Window/Event.hpp>
#include "ExampleFrame.h"

EnginExampleState::EnginExampleState(sf::RenderWindow &newWindow):
window(newWindow)
{

}


void EnginExampleState::init(std::shared_ptr<GU::Engin::Frame> frame)
{
    frame->init();
}


void EnginExampleState::clean(std::shared_ptr<GU::Engin::Frame> frame)
{
    frame->clean();
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
                    engin.quit(); 
                    break;
            }
        }
    }

    frame->handleEvents(engin, deltaTime);
}



void EnginExampleState::update(GU::Engin::Engin& engin, const float &deltaTime, std::shared_ptr<GU::Engin::Frame> frame)
{
    frame->update(engin, deltaTime);
}


void EnginExampleState::draw(GU::Engin::Engin& engin, const float &deltaTime, std::shared_ptr<GU::Engin::Frame> frame)
{
    std::shared_ptr<ExampleFrame> eFrame = std::dynamic_pointer_cast<ExampleFrame>(frame);    
    window.clear();
    
    window.draw(eFrame->circle);
    window.display();
}
