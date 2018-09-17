#include "Heart.hpp"

namespace ArktisProductions
{
    Heart::Heart(GameDataRef data) :_data(data)
    {
        for (short unsigned int i=0; i < 3; i++ )
        {
            this->heartSprites.push_back(sf::Sprite(this->_data->assets.GetTexture("heart")));
            this->heartSprites.at(i).setPosition(i*heartSprites.at(i).getGlobalBounds().width + 10, 10);
        }
    }
    
    void Heart::DrawHearts()
    {
        for (short unsigned int i=0; i < this->heartSprites.size(); i++)
            this->_data->window.draw(heartSprites.at(i));
    }
    
    void Heart::ReceiveDMG()
    {
        this->heartSprites.pop_back();
    }
    
    void Heart::RestartHearts()
    {
        // THIS IS ONLY TO BE CALLED WHEN THE PERSON DIES
        for(int i=0; i < 3; i++)
        {
            this->heartSprites.push_back(sf::Sprite(this->_data->assets.GetTexture("heart")));
            this->heartSprites.at(i).setPosition(i*heartSprites.at(i).getGlobalBounds().width + 10, 10);
        }
    }
    
    const unsigned short int Heart::GetHealth() const
    {
        return this->heartSprites.size();
    }
}
