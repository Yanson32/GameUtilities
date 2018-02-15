#include "Header.h"
namespace Ui
{
    namespace Screen
    {
        Header::Header()
        {
            //ctor
        }

        void Header::SetSize(const sf::Vector2f size)
        {
            _rect.setSize(size);
        }


        sf::Vector2f Header::GetSize()const
        {
            return _rect.getSize();
        }

        sf::FloatRect Header::GetGlobalBounds()const
        {
            return _rect.getGlobalBounds();
        }

        Header::~Header()
        {
            //dtor
        }
    }
}
