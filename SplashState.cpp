#include <sstream>
#include "SplashState.hpp"
#include "GameState.hpp"
#include "DEFINITIONS.h"

#include <iostream>

namespace ArktisProductions
{
    SplashState::SplashState(GameDataRef data) : _data(data)
    {
        
    }
    
    void SplashState::Init()
    {
        this->_data->assets.LoadTexture("Splash_BG", SPLASH_SCENE_BACKGROUND_FILEPATH);
        
        _background.setTexture(this->_data->assets.GetTexture("Splash_BG"));
    }
    
    void SplashState::HandleInput()
    {
        sf::Event event;
        
        while (this->_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
                this->_data->window.close();
        }
    }
    
    void SplashState::Update(float dt)
    {
        if (this->_clock.getElapsedTime().asSeconds() > 3)
            this->_data->machine.AddState(StateRef(new GameState(_data)), true);
    }
    
    void SplashState::Draw(float dt)
    {
        this->_data->window.clear(sf::Color::Red);
        
        this->_data->window.draw( this->_background );
        
        this->_data->window.display();
    }
}
