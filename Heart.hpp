#include "Game.hpp"

namespace ArktisProductions
{
    class Heart
    {
    public:
        Heart(GameDataRef data);
        
        void DrawHearts();
        
        void ReceiveDMG();
        
        const  unsigned short int GetHealth() const;
        
    private:
        GameDataRef _data;
        
        std::vector<sf::Sprite> heartSprites;
    };
}
