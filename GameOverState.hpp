#pragma once

#include <SFML/Graphics.hpp>
#include "GameOverState.hpp"

#include "State.hpp"
#include "Game.hpp"

namespace ArktisProductions
{
    class GameOverState : public State
    {
    public:
        GameOverState(GameDataRef data);
        
        void Init();
        
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);
        
    private:
        GameDataRef _data;
        
        sf::Text _gameOverText, _restartText, _exitText;
    };
}
