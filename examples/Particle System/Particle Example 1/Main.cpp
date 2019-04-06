#include <GameUtilities/ParticleSystem/Systems/Starburst.h>
#include <GameUtilities/ParticleSystem/Attributes/Manager.h>
#include <GameUtilities/ParticleSystem/Attributes/Position.h>
#include <GameUtilities/ParticleSystem/Attributes/Velocity.h>
#include <GameUtilities/ParticleSystem/Attributes/LifeSpan.h>
#include <GameUtilities/ParticleSystem/Attributes/Base.h>
#include <GameUtilities/ParticleSystem/Attributes/Id.h>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <cassert>
#include <iostream>
class sfStarburst: public GU::PS::SY::Starburst, public sf::Drawable
{
    public:
            sfStarburst(const Math::Point &pos, const std::size_t size);
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
            virtual void update(const float &deltaTime) override;
            std::vector<sf::CircleShape> data;
};

sfStarburst::sfStarburst(const Math::Point &pos, const std::size_t size):
GU::PS::SY::Starburst::Starburst(pos, size)
{
    for(std::size_t i = 0; i < size; ++i)
    {
        sf::CircleShape circle;
        circle.setFillColor(sf::Color::Green);
        circle.setRadius(5);
        circle.setPosition({pos.m_x, pos.m_y});
        data.push_back(circle);
    }

//    std::shared_ptr<GU::PS::AT::Position> dPos = std::static_pointer_cast<GU::PS::AT::Position>(this->getComponent(GU::PS::AT::Id::POSITION));
//    assert(dPos != nullptr);
//    for(std::size_t i = 0; i < dPos->data.size(); ++i)
//    {
//        dPos->data[i].first = pos.m_x;
//        dPos->data[i].second = pos.m_y;
//    }
}

void sfStarburst::update(const float &deltaTime)
{
    Starburst::update(deltaTime);
    if(this->hasComponent(GU::PS::AT::Id::POSITION))
    {
        std::shared_ptr<GU::PS::AT::Position> pos = std::static_pointer_cast<GU::PS::AT::Position>(this->getComponent(GU::PS::AT::Id::POSITION));
        assert(pos != nullptr);
        this->data.resize(pos->data.size());
        for(std::size_t i = 0; i < pos->data.size(); ++i)
        {
            this->data[i].setPosition(pos->data[i].first, pos->data[i].second);
        }
    }


    //GU::PS::UP::Manager::update(*this, deltaTime);

}
void sfStarburst::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

    for(std::size_t i = 0; i < data.size(); ++i)
        target.draw(data[i]);
}
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    std::vector<sfStarburst> burst;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if(event.type == sf::Event::MouseButtonPressed)
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    Math::Point point(event.mouseButton.x, event.mouseButton.y);
                    sfStarburst temp(point, 100);
                    burst.push_back(temp);
                }
            }
        }

        window.clear();


        for(std::size_t i = 0; i < burst.size(); ++i)
        {
            burst[i].update(1);
        }


        //draw
        for(std::size_t i = 0; i < burst.size(); ++i)
        {
            window.draw(burst[i]);
        }
        Sleep(5);
        //sf::sleep({5});
        window.display();

    }

    return 0;
}
