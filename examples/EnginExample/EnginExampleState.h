#ifndef ENGIN_EXAMPLE_STATE_H
#define ENGIN_EXAMPLE_STATE_H
#include <GameUtilities/Engin/GameState.h>
#include <GameUtilities/Engin/Engin.h>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
	class EnginExampleState: public GU::Engin::GameState
	{
		public:
            typedef GU::Engin::Engin * const EnginPtr;
			EnginExampleState(sf::RenderWindow &newWindow);
            virtual void init() override;
            virtual void clean() override;
            virtual void handleEvents(EnginPtr engin, const float &deltaTime) override;
            virtual void update(EnginPtr engin, const float &deltaTime) override;
            virtual void draw(EnginPtr engin, const float &deltaTime) override;
        private:
            sf::RenderWindow &window;
            sf::CircleShape circle;
	};
#endif
