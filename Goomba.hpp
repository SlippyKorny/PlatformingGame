#include <SFML/Graphics.hpp>
#include "Game.hpp"

namespace ArktisProductions
{
    class Goomba
    {
    public:
        Goomba(GameDataRef data);
        
        void Animate(float dt);
        
        void SpawnAGoomba();
        
        void MoveGoombas(float dt);
        
        void DeleteGoomba(unsigned short int index);
        
        void DrawGoombas();
        
        void PurgeGoombas();
        
        const std::vector<sf::Sprite> &GetSprites() const;
    private:
        GameDataRef _data;
        
        sf::Clock _clock;
        
        std::vector<sf::Sprite> goombaSprites;
        
        unsigned short int _animationIterator;
    };
}
