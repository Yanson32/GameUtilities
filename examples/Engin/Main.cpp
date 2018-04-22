#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <GameUtilities/Engin/Engin.h>
#include "TestState.h"

int main(int argc, char* argv[])
{


    sf::Clock timer;
    const sf::Time deltaTime = sf::seconds(1.0f / 60.0f);
    sf::Time accumulator = sf::seconds(0);

	GU::Engin::Engin engin;

	engin.Push<TestState>(engin);
	//EventManager::inst().Post<GU::Evt::PlayMusic>("../Resources/Music/Electro_Zombies.ogg");

    try
    {
        while (engin.IsRunning())
        {
            accumulator += timer.restart();
            engin.HandleEvents(deltaTime.asSeconds());
            while(accumulator.asSeconds() >= deltaTime.asSeconds())
            {
                engin.Update(deltaTime.asSeconds());
                accumulator -= deltaTime;
            }
            engin.Draw(deltaTime.asSeconds());
        }
    }
    catch(...)
    {

    }

}
