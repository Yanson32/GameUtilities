#include <iostream>
#include <GameUtilities/Engin/Engin.h>
#include "EnginExampleState.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "GameUtilities/Engin/Frame.h"
#include <memory>

class ExampleFrame: public GU::Engin::Frame
{
    public:
        virtual void init() override;
        virtual void clean() override;
        virtual void handleEvents(GU::Engin::Engin& engin, const float &deltaTime) override;
        virtual void update(GU::Engin::Engin& engin, const float &deltaTime) override;
        virtual void draw(GU::Engin::Engin& engin, const float &deltaTime) override;
};

void ExampleFrame::init()
{

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


int main()
{
    std::shared_ptr<ExampleFrame> frame(new ExampleFrame());
    sf::RenderWindow window({800, 600}, "EnginExample");
	GU::Engin::Engin engin;
	engin.push<EnginExampleState>(frame, window);

    sf::Clock clock;
    sf::Time accumulator;
    sf::Time deltaTime = sf::seconds(1 / 60);

	while(engin.isRunning())
	{
        accumulator += clock.restart();
        engin.handleEvents(deltaTime.asMilliseconds(), frame);

        if(accumulator.asMilliseconds() >= deltaTime.asMilliseconds())
        {
            accumulator -= deltaTime;
            engin.update(deltaTime.asMilliseconds(), frame);
        }
        engin.draw(deltaTime.asMilliseconds(), frame);
	}
	return 0;
}
