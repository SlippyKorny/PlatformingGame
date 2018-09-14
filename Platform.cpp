#include "Platform.hpp"
#include "DEFINITIONS.h"

namespace ArktisProductions
{
    Platform::Platform(GameDataRef data) : _data(data)
    {
    }
    
    void Platform::spawnPlatform()
    {
        sf::Sprite sprite(this->_data->assets.GetTexture("brick_floor"));
        float y_coordinate;
        
        while(true)
        {
            y_coordinate = RANDOM_PLATFORM_Y_COORDINATE;
            if (y_coordinate < MAX_PLATFORM_HEIGHT)
                break;
        }
        
        sprite.setPosition(FIXED_PLATFORM_X_COORDINATE, y_coordinate);
        
        platformSprites.push_back(sprite);
    }
    
    void Platform::spawnInvisiblePlatform()
    {
        sf::Sprite sprite(this->_data->assets.GetTexture("brick_floor"));
        
        sprite.setPosition(this->_data->window.getSize().x, 0);
        sprite.setColor(sf::Color(0, 0, 0, 0));
        
        platformSprites.push_back(sprite);
    }
    
    void Platform::movePlatforms(float dt)
    {
        for (unsigned short int i = 0; i < platformSprites.size(); i++)
        {
            if (platformSprites.at(i).getPosition().x < 0 - platformSprites.at(i).getGlobalBounds().width)
                platformSprites.erase(platformSprites.begin()+i);
            else
            {
//                sf::Vector2f position = platformSprites.at(i).getPosition();
                float mvmt = PLATFORM_MVMT_SPEED * dt;
                
                platformSprites.at(i).move(-mvmt, 0);
            }
        }
    }
    
    void Platform::DrawPlatforms()
    {
        for (unsigned short int i = 0; i < platformSprites.size(); i++)
            this->_data->window.draw(platformSprites.at(i));
    }
    
    const std::vector<sf::Sprite> &Platform::GetSprites() const
    {
        return this->platformSprites;
    }
}
