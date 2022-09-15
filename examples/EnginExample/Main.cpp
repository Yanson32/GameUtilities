#include <iostream>
#include <GameUtilities/Engin/Engin.h>
#include "EnginExampleState.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "ExampleFrame.h"
#include <memory>


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
