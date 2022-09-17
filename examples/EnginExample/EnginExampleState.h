#ifndef ENGIN_EXAMPLE_STATE_H
#define ENGIN_EXAMPLE_STATE_H
#include <GameUtilities/Engin/GameState.h>
#include <GameUtilities/Engin/Engin.h>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
	class EnginExampleState: public GU::Engin::GameState
	{
		public:
			EnginExampleState(sf::RenderWindow &newWindow);
            virtual void init() override;
            virtual void clean() override;
            virtual void handleEvents(GU::Engin::Engin *engin, const float &deltaTime) override;
            virtual void update(GU::Engin::Engin *engin, const float &deltaTime) override;
            virtual void draw(GU::Engin::Engin *engin, const float &deltaTime) override;
        private:
            sf::RenderWindow &window;
            sf::CircleShape circle;
	};
#endif
