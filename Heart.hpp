#include "Game.hpp"

namespace ArktisProductions
{
    class Heart
    {
    public:
        Heart(GameDataRef data);
        
        void DrawHearts();
        
        void ReceiveDMG();
        
        void RestartHearts();
        
        const  unsigned short int GetHealth() const;
        
    private:
        GameDataRef _data;
        
        std::vector<sf::Sprite> heartSprites;
    };
}
