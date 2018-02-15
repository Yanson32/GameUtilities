#ifndef HEADER_H
#define HEADER_H
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "Exports.h"
namespace Ui
{
    namespace Screen
    {
        class GAMEUTILITIES_API Header
        {
            public:
                Header();
                void SetSize(const sf::Vector2f size);
                sf::Vector2f GetSize()const;
                sf::FloatRect GetGlobalBounds()const;
                virtual ~Header();

            protected:

            private:

                sf::RectangleShape _rect;
        };
    }
}
#endif // HEADER_H
