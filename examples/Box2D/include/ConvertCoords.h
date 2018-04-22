#ifndef BOX2D_EXAMPLES_CONVERTCOORDS_H
#define BOX2D_EXAMPLES_CONVERTCOORDS_H
#include <Box2D/Box2D.h>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

float32 toMeters(const float pixles);
float   toPixles(const float32 meters);
b2Vec2 toMeters(const sf::Vector2f& pixles);

sf::Vector2f getMousePosition(const sf::RenderWindow &window);
#endif // BOX2D_EXAMPLES_CONVERTCOORDS_H
