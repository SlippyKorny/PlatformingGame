#include "Player.hpp"
#include "DEFINITIONS.h"
//#include <iostream>


namespace ArktisProductions
{
    Player::Player(GameDataRef data) : _data(data)
    {
        _animationIterator = 0;
        _playerSprite.setTexture(this->_data->assets.GetTexture("Player Frame " + std::to_string(_animationIterator)));
        _playerSprite.setPosition(SCREEN_WIDTH/2.0f, SCREEN_HEIGHT - (_playerSprite.getGlobalBounds().height+this->_data->assets.GetTexture("Land").getSize().y));
        _playerState = PLAYER_STATE_WALK;   // TODO: Maybe delete
        
    }
    
    void Player::Draw()
    {
        this->_data->window.draw(_playerSprite);
    }
    
    void Player::Animate(float dt)
    {
        float how_many_frames = 4.0f; // It means there are 4 animation states (4 different textures)
        if(this->_playerState == PLAYER_STATE_RISE || this->_playerState == PLAYER_STATE_FALL)
        {
            this->_animationIterator = 1;
            this->_playerSprite.setTexture(this->_data->assets.GetTexture("Player Jump"));
            this->_clock.restart();
        }
        
        else if(_clock.getElapsedTime().asSeconds() > PLAYER_ANIMATION_DURATION / how_many_frames) // Make jump anim.
        {
            if (_animationIterator < how_many_frames-1)
                this->_animationIterator++;
            else
                this->_animationIterator = 1;
            this->_playerSprite.setTexture(this->_data->assets.GetTexture("Player Frame " + std::to_string(_animationIterator)));
            this->_clock.restart();
        }
    }
    
    void Player::Update(float dt)
    {
        // TODO: Jump animation
        // TODO: Change when hit a thing
        if(_playerState == PLAYER_STATE_FALL)
            this->_playerSprite.move(0, GRAVITY_FORCE * dt);
        else if(_playerState == PLAYER_STATE_RISE)
            this->_playerSprite.move(0, JUMP_SPEED * dt);
        
        if(_mvmtClock.getElapsedTime().asSeconds() > JUMP_DURATION)
        {
            this->_playerState = PLAYER_STATE_FALL;
            _mvmtClock.restart();                       // TODO: Maybe delete
        }
    }
    
    void Player::Jump()
    {
        if (this->_playerState != PLAYER_STATE_RISE && this->_playerState != PLAYER_STATE_FALL)
        {
            this->_mvmtClock.restart();
            this->_playerState = PLAYER_STATE_RISE;
        }
    }
    
    void Player::MoveOnePixelHigher()
    {
        this->_playerSprite.move(0, -1);
    }
    
    void Player::SetPlayerState(unsigned int _state)
    {
        this->_playerState = _state;
    }
    
    unsigned int &Player::GetPlayerState()
    {
        return this->_playerState;
    }
    
    const sf::Sprite &Player::GetSprite() const
    {
        return this->_playerSprite;
    }
}
