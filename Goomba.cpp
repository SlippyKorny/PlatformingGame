#include "Goomba.hpp"
#include "DEFINITIONS.h"

namespace ArktisProductions
{
    Goomba::Goomba(GameDataRef data) :_data(data)
    {
        _animationIterator = 0;
    }
    
    void Goomba::Animate(float dt)
    {
        float how_many_frames = 2.0f; // It means there are 4 animation states (4 different textures)
        
        if(_clock.getElapsedTime().asSeconds() > GOOMBA_ANIMATION_DURATION / how_many_frames) // Make jump anim.
        {
            if (_animationIterator < how_many_frames-1)
                this->_animationIterator++;
            else
                this->_animationIterator = 0;
            
            for (unsigned short int i=0; i < goombaSprites.size(); i++)
                this->goombaSprites.at(i).setTexture(this->_data->assets.GetTexture("Goomba_" + std::to_string(_animationIterator)));
            this->_clock.restart();
        }
    }
    
    void Goomba::SpawnAGoomba()
    {
        sf::Sprite sprite(this->_data->assets.GetTexture("Goomba_0"));  // TODO: Import goomba textures and name them
                                                                // Just like that - goomba_0, goomba_1 etc.
        
        sprite.setPosition(FIXED_PLATFORM_X_COORDINATE, SCREEN_HEIGHT-(216+128));  // 216
        
        goombaSprites.push_back(sprite);
    }
    
    void Goomba::MoveGoombas(float dt)
    {
        for (unsigned short int i = 0; i < goombaSprites.size(); i++)
        {
            if (goombaSprites.at(i).getPosition().x < 0 - goombaSprites.at(i).getGlobalBounds().width)
                goombaSprites.erase(goombaSprites.begin()+i);
            else
            {
                //                sf::Vector2f position = platformSprites.at(i).getPosition();
                float mvmt = GOOMBA_MVMT_SPEED * dt;
                
                goombaSprites.at(i).move(-mvmt, 0);
            }
        }
    }
    
    void Goomba::DeleteGoomba(unsigned short int index)
    {
        goombaSprites.erase(goombaSprites.begin() + index);
    }
    
    void Goomba::DrawGoombas()
    {
        for (unsigned short int i = 0; i < goombaSprites.size(); i++)
            this->_data->window.draw(goombaSprites.at(i));
    }
    
    const std::vector<sf::Sprite> &Goomba::GetSprites() const
    {
        return this->goombaSprites;
    }
}
