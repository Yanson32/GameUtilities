#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include "Resource Holder.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "NonCopyable.h"
#include "Exports.h"
struct GAMEUTILITIES_API ResourceManager: NonCopyable
{
        static ResourceHolder<sf::Font,         sf::String> font;
        static ResourceHolder<sf::Texture,      sf::String> texture;
        //static ResourceHolder<sf::SoundBuffer,  sf::String> buffer;
};

#endif // RESOURCEMANAGER_H
