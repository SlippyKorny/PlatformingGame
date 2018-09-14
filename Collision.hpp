#pragma once

#include <SFML/Graphics.hpp>

namespace ArktisProductions
{
    class Collision
    {
    public:
        Collision();
        
        bool CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2);
        
        bool IsSpriteOnPlatform(sf::Sprite player, sf::Sprite platform);
    };
}
