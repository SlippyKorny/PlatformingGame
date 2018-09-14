#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include "State.hpp"
#include "Game.hpp"
#include "Platform.hpp"
#include "Land.hpp"
#include "Player.hpp"
#include "Collision.hpp"
#include "Heart.hpp"
#include "Goomba.hpp"

namespace ArktisProductions
{
    class GameState : public State
    {
    public:
        GameState(GameDataRef data);
        
        void Init();
        
        // No pause() or resume() methods here as this
        // is a very simple example of a game state.
        
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);
        
    private:
        GameDataRef _data;
        
        sf::Clock _respawnerClock;
        sf::Clock _scoreClock;
        
        sf::Text _score;
        sf::Text _versionName;
        
        sf::Music _gameTheme;
        
        // TODO: Make functions in asset manager that will handle this
        sf::SoundBuffer _bumpBuffer;
        sf::Sound _bumpSound;
        sf::SoundBuffer _jumpBuffer;
        sf::Sound _jumpSound;
        sf::SoundBuffer _stompBuffer;
        sf::Sound _stompSound;
        
        std::unique_ptr<Platform> platform;
        std::unique_ptr<Land> land;
        std::unique_ptr<Player> player;
        std::unique_ptr<Heart> heart;
        std::unique_ptr<Goomba> goomba;
        
        Collision collision;
        
        int _gameStatus;
        int _additionalPoints;
    };
}
