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
                virtual void Init();


                virtual void Clean();


                virtual void HandleEvents(GU::Engin::Engin& engin, const float &deltaTime);



                virtual void Update(GU::Engin::Engin& engin, const float &deltaTime);


                virtual void Draw(GU::Engin::Engin& engin, const float &deltaTime);
        private:
            sf::RenderWindow &window;
            sf::CircleShape circle;
	};
#endif
