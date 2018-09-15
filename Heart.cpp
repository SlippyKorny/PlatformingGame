#include "Heart.hpp"

namespace ArktisProductions
{
    Heart::Heart(GameDataRef data) :_data(data)
    {
        for (short unsigned int i=0; i < 3; i++ )
        {
            heartSprites.push_back(sf::Sprite(this->_data->assets.GetTexture("heart")));
            heartSprites.at(i).setPosition(i*heartSprites.at(i).getGlobalBounds().width + 10, 10);
        }
    }
    
    void Heart::DrawHearts()
    {
        for (short unsigned int i=0; i < this->heartSprites.size(); i++)
            this->_data->window.draw(heartSprites.at(i));
    }
    
    void Heart::ReceiveDMG()
    {
        heartSprites.pop_back();
    }
    
    const unsigned short int Heart::GetHealth() const
    {
        return heartSprites.size();
    }
}
