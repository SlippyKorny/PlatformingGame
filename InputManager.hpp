#pragma once

#include <SFML/Graphics.hpp>

namespace ArktisProductions
{
    class InputManager
    {
    public:
        InputManager() {}
        ~InputManager() {}
        
        bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
        
        bool IsTextClicked(sf::Text object, sf::Mouse::Button button, sf::RenderWindow &window);
        
        sf::Vector2i GetMousePosition(sf::RenderWindow &window);
    };
}
