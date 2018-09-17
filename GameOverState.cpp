#include <sstream>
#include "GameOverState.hpp"
#include "DEFINITIONS.h"

#include <iostream>

namespace ArktisProductions
{
    GameOverState::GameOverState(GameDataRef data) : _data(data)
    {
        // Game Over text
        _gameOverText.setFont(this->_data->assets.GetFont("score_font"));
        _gameOverText.setString("Game Over!");
        _gameOverText.setCharacterSize(72);
        _gameOverText.setPosition((SCREEN_WIDTH * 30.0f)/100.0f, (SCREEN_HEIGHT * 10.0f)/100.0f);
//        _gameOverText.setPosition((SCREEN_HEIGHT * 10.0f)/100.0f, (SCREEN_WIDTH * 30.0f)/100.0f);
        
        // Restart text
        _restartText.setFont(this->_data->assets.GetFont("score_font"));
        _restartText.setString("Restart game");
        _restartText.setCharacterSize(42);
        _restartText.setPosition((SCREEN_WIDTH * 10.0f)/100.0f, (SCREEN_HEIGHT * 50.0f)/100.0f);
        
        // Exit text
        _exitText.setFont(this->_data->assets.GetFont("score_font"));
        _exitText.setString("Exit the game");
        _exitText.setCharacterSize(42);
        _exitText.setPosition((SCREEN_WIDTH * 62.5f)/100.0f, (SCREEN_HEIGHT * 50.0f)/100.0f);
    }
    
    void GameOverState::Init()
    {
        
    }
    
    void GameOverState::HandleInput()
    {
        sf::Event event;
        
        while (this->_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
                this->_data->window.close();
        }
    }
    
    void GameOverState::Update(float dt)
    {
    }
    
    void GameOverState::Draw(float dt)
    {
        this->_data->window.clear(sf::Color::Black);
        
        this->_data->window.draw(_restartText);
        this->_data->window.draw(_exitText);
        this->_data->window.draw(_gameOverText);
        
        this->_data->window.display();
    }
}
