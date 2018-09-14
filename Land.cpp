#include "Land.hpp"
#include "DEFINITIONS.h"

namespace ArktisProductions
{
    Land::Land(GameDataRef data) : _data(data)
    {
        sf::Sprite sprite(_data->assets.GetTexture("Land"));
        sf::Sprite spriteTwo(_data->assets.GetTexture("Land"));
        
        //216 - height
        sprite.setPosition(0, SCREEN_HEIGHT - sprite.getGlobalBounds().height);
        spriteTwo.setPosition(sprite.getGlobalBounds().width, SCREEN_HEIGHT - sprite.getGlobalBounds().height);
        
        _landSprites.push_back(sprite);
        _landSprites.push_back(spriteTwo);
    }
    
    void Land::MoveLand(float dt)
    {
        for (unsigned short int i=0; i < _landSprites.size(); i++)
        {
            float mvmt = PLATFORM_MVMT_SPEED * dt;
            _landSprites.at(i).move(-mvmt, 0.0f);
            if (_landSprites.at(i).getPosition().x < 0 - _landSprites.at(i).getGlobalBounds().width)
            {
                sf::Vector2f pos(_data->window.getSize().x, _landSprites.at(i).getPosition().y);
                _landSprites.at(i).setPosition(pos); // TODO: Delete the vector2f reference
            }
        }
    }
    
    void Land::DrawLand()
    {
        for (unsigned short int i=0; i < _landSprites.size(); i++)
            _data->window.draw(_landSprites.at(i));
    }
    
    const std::vector<sf::Sprite> &Land::GetSprites() const
    {
        return this->_landSprites;
    }
}
