#include "Collision.hpp"
#include "DEFINITIONS.h"

#include <iostream>

namespace ArktisProductions
{
    Collision::Collision()
    {
        
    }
    
    bool Collision::CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2)
    {
        sf::Rect<float> rect1 = sprite1.getGlobalBounds();
        sf::Rect<float> rect2 = sprite2.getGlobalBounds();
        
        if(rect1.intersects(rect2))
            return true;
        else
            return false;
    }
    
    bool Collision::IsSpriteOnPlatform(sf::Sprite player, sf::Sprite platform)
    {
//        sf::Rect<float> rect1 = player.getGlobalBounds();
//        sf::Rect<float> rect2 = player.getGlobalBounds();

//        if(rect1.intersects(rect2))
//            return true;
//        else
//            return false;
        float _player_height = player.getGlobalBounds().height,
        _player_width = player.getGlobalBounds().width,
        _player_pos_y = player.getPosition().y,
        _player_pos_x = player.getPosition().x;
        
        float _platform_height = platform.getGlobalBounds().height,
        _platform_width = platform.getGlobalBounds().width,
        _platform_pos_y = platform.getPosition().y,
        _platform_pos_x = platform.getPosition().x;
        
        
        if(((_player_height + _player_pos_y) < _platform_pos_y) &&
            !(_player_pos_y + _player_height < _platform_pos_y - 5.0f) &&
            ((_player_width + _player_pos_x) > _platform_pos_x) &&
            (_player_pos_x < _platform_pos_x + _platform_width))
            return true;
        else
            return false;
    }
}
