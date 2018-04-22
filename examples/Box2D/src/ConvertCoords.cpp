#include "ConvertCoords.h"
#include <SFML/Window/Mouse.hpp>
#include <SFML/System/Vector2.hpp>

float32 toMeters(const float pixles)
{
    return pixles / 40;
}


float toPixles(const float32 meters)
{
    return meters * 40;
}

b2Vec2 toMeters(const sf::Vector2f& pixles)
{
    return b2Vec2(toMeters(pixles.x), toMeters(pixles.y));
}

sf::Vector2f getMousePosition(const sf::RenderWindow &window)
{
    sf::Vector2i mouse = sf::Mouse::getPosition(window);
    //Map Pixel to Coords:
    sf::Vector2f mouse_world = window.mapPixelToCoords(mouse);
    return mouse_world;
}
