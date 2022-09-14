#include <iostream>
#include <GameUtilities/Engin/Engin.h>
#include "EnginExampleState.h"
#include <SFML/Graphics/RenderWindow.hpp>

int main()
{
    sf::RenderWindow window({800, 600}, "EnginExample");
	GU::Engin::Engin engin;
	engin.push<EnginExampleState>(window);

    sf::Clock frame;
    sf::Time accumulator;
    sf::Time deltaTime = sf::seconds(1 / 60);

	while(engin.isRunning())
	{
        accumulator += frame.restart();
        engin.handleEvents(deltaTime.asMilliseconds());

        if(accumulator.asMilliseconds() >= deltaTime.asMilliseconds())
        {
            accumulator -= deltaTime;
            engin.update(deltaTime.asMilliseconds());
        }
        engin.draw(deltaTime.asMilliseconds());
	}
	return 0;
}
