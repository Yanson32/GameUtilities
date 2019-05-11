#include <GameUtilities/ParticleSystem/Systems/Starburst.h>
#include <GameUtilities/ParticleSystem/Attributes/Manager.h>
#include <GameUtilities/ParticleSystem/Attributes/Position.h>
#include <GameUtilities/ParticleSystem/Attributes/Velocity.h>
#include <GameUtilities/ParticleSystem/Attributes/LifeSpan.h>
#include <GameUtilities/ParticleSystem/Attributes/Base.h>
#include <GameUtilities/ParticleSystem/Attributes/Id.h>
#include <GameUtilities/ParticleSystem/Attributes/Base.h>
#include <GameUtilities/ParticleSystem/Container.h>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <cassert>
#include <iostream>

const int CIRCLE_ATT = 3;	///CircleAtt's id

/********************************************************************************//**
*	@brief	sf::CircleShape attribute. for drawing particles with sfml.
*	@class	CircleAtt
************************************************************************************/
class CircleAtt: public GU::PS::AT::Base
{
    public:

		/**********************************************************************************//**
		*	@brief Constructor.
		*	@param	newManager a reference to the attribute manager.
		*	@param  newSize a reference to the total number of particles in the system.
		*	@param	newId the id of the attribute.
		**************************************************************************************/
        CircleAtt(GU::PS::AT::Manager& newManager, const std::size_t &newSize, const int &newId = -1);


		/**********************************************************************************//**
		*	@brief remove element from container.
		*	@param	The index of the element to be removed.
		**************************************************************************************/
        virtual void remove(const std::size_t &index);

        GU::PS::Container<sf::CircleShape> data;	///A container for the attributes data.
};


/**********************************************************************************//**
*	@brief Constructor.
*	@param	newManager a reference to the attribute manager.
*	@param  newSize a reference to the total number of particles in the system.
*	@param	newId the id of the attribute.
**************************************************************************************/
CircleAtt::CircleAtt(GU::PS::AT::Manager& newManager, const std::size_t &newSize, const int &newId):
    GU::PS::AT::Base::Base(newManager, newSize, newId),
    data(newSize)
{

    for(std::size_t i = 0; i < newSize; ++i)
    {
        sf::CircleShape &circle = data[i];
        circle.setFillColor(sf::Color::Green);
        circle.setRadius(5);
    }

}


/**********************************************************************************//**
*	@brief remove element from container.
*	@param	The index of the element to be removed.
**************************************************************************************/
void CircleAtt::remove(const std::size_t &index)
{
    data.remove(index);
}


/**********************************************************************************//**
*	@brief	Creates particles in a circular pattern. Designed to be drawn with
*			sfml graphics library.
*	@class	sfStarburst.
**************************************************************************************/
class sfStarburst: public GU::PS::SY::Starburst, public sf::Drawable
{
    public:
            sfStarburst(const Math::Point &pos, const std::size_t size);
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
            virtual void update(const float &deltaTime) override;
};


/**********************************************************************************//**
*	@brief	Creates particles in a circular pattern. Designed to be drawn with
*			sfml graphics library.
*	@param	sfStarburst.
**************************************************************************************/
sfStarburst::sfStarburst(const Math::Point &pos, const std::size_t size):
GU::PS::SY::Starburst::Starburst(pos, size)
{
    std::shared_ptr<CircleAtt> cAtt = std::shared_ptr<CircleAtt>(new CircleAtt(*this, size, CIRCLE_ATT));
    assert(cAtt != nullptr);
    this->addAttribute(cAtt);
}


/**********************************************************************************//**
*	@brief	Update per frame logic.
*	@param	deltaTime the amout of time the last frame took.
**************************************************************************************/
void sfStarburst::update(const float &deltaTime)
{
    Starburst::update(deltaTime);
    if(this->hasComponent(GU::PS::AT::Id::POSITION) && this->hasComponent(CIRCLE_ATT))
    {
        std::shared_ptr<GU::PS::AT::Position> pos = std::static_pointer_cast<GU::PS::AT::Position>(this->getComponent(GU::PS::AT::Id::POSITION));
        std::shared_ptr<CircleAtt> cAtt = std::static_pointer_cast<CircleAtt>(this->getComponent(CIRCLE_ATT));
        assert(pos != nullptr);
        assert(cAtt != nullptr);
        assert(pos->data.size() == cAtt->data.size());
        for(std::size_t i = 0; i < pos->data.size(); ++i)
        {
            cAtt->data[i].setPosition(pos->data[i].first, pos->data[i].second);
        }
    }
}


/**********************************************************************************//**
*	@brief	Draw particle system  to the window.
*	@param	target that particles will be drawn to.
*	@param	states sfml drawing attributes.
**************************************************************************************/
void sfStarburst::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if(this->hasComponent(CIRCLE_ATT))
    {
        std::shared_ptr<CircleAtt> att = std::static_pointer_cast<CircleAtt>(this->getComponent(CIRCLE_ATT));
        for(std::size_t i = 0; i < att->data.size(); ++i)
        {
            target.draw(att->data[i]);
        }
    }
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

		//update
        for(std::size_t i = 0; i < burst.size(); ++i)
        {
            burst[i].update(1);
        }


        //draw
        for(std::size_t i = 0; i < burst.size(); ++i)
        {
            window.draw(burst[i]);
        }
        window.display();

    }

    return 0;
}
