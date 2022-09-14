#include <iostream>
#include <GameUtilities/Engin/Engin.h>
#include "EnginExampleState.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "GameUtilities/Engin/Frame.h"
#include <memory>

class ExampleFrame: public GU::Engin::Frame
{
    public:
        virtual void Init() override;
        virtual void Clean() override;
        virtual void HandleEvents(GU::Engin::Engin& engin, const float &deltaTime) override;
        virtual void Update(GU::Engin::Engin& engin, const float &deltaTime) override;
        virtual void Draw(GU::Engin::Engin& engin, const float &deltaTime) override;
};

void ExampleFrame::Init()
{

}


void ExampleFrame::Clean()
{

}


void ExampleFrame::HandleEvents(GU::Engin::Engin& engin, const float &deltaTime)
{

}


void ExampleFrame::Update(GU::Engin::Engin& engin, const float &deltaTime)
{

}


void ExampleFrame::Draw(GU::Engin::Engin& engin, const float &deltaTime)
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
