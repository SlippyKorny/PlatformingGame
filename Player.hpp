#pragma once

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.h"
#include "Game.hpp"

namespace ArktisProductions
{
    class Player
    {
    public:
        Player(GameDataRef data);
        
        void Draw();
        
        void Animate(float dt);
        
        void Update(float dt);
        
        void Jump();
        
        void Bounce();
        
        void MoveOnePixelHigher();
        
        void MakePlayerInvincible();
        
        const bool IsPlayerInvincible() const;
        
        void SetPlayerState(unsigned int _state);
        
        const sf::Sprite &GetSprite() const;
        
        unsigned int &GetPlayerState();
    private:
        GameDataRef _data;
        
        sf::Sprite _playerSprite;
        
        sf::Clock _clock;
        
        sf::Clock _mvmtClock;
        
        bool _invincibility;
        
        bool _wasItInvincInPrevFrame;
        
        unsigned int _invincibilityStartTime;
        
        unsigned int _animationIterator;
        
        unsigned int _playerState;
    };
}
