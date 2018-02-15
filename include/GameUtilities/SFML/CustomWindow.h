#ifndef CUSTOMWINDOW_H
#define CUSTOMWINDOW_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Exports.h"
//#include "Ui/Screen/Screen.h"

class GAMEUTILITIES_API CustomWindow: public sf::RenderWindow//, public Ui::Screen::Screen
{
    public:
        CustomWindow(sf::VideoMode mode,
                     const sf::String& title,
                     sf::Uint32 style =
                     sf::Style::Default,
                     const sf::ContextSettings& settings = sf::ContextSettings());

    protected:

    private:
};

#endif // CUSTOMWINDOW_H
