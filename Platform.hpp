#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace ArktisProductions
{
    class Platform
    {
    public:
        Platform(GameDataRef data);
        
        void spawnPlatform();
        void spawnInvisiblePlatform(); // <- Maybe delete this?
        void movePlatforms(float dt);
        
        void DrawPlatforms();
        
        const std::vector<sf::Sprite> &GetSprites() const;
        
    private:
        GameDataRef _data;
        std::vector<sf::Sprite> platformSprites;
    };
}
