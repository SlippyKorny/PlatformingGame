#include "Game.hpp"

namespace ArktisProductions
{
    class Heart
    {
    public:
        Heart(GameDataRef data);
        
        void DrawHearts();
        
        void GetDMG();
        
    private:
        GameDataRef _data;
        
        std::vector<sf::Sprite> heartSprites;
    };
}
