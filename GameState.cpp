#include <sstream>
#include <memory>
#include <stdlib.h>
#include "GameState.hpp"
#include "DEFINITIONS.h"
#include "GameOverState.hpp"

// TODO: Delete
#include <iostream>


namespace ArktisProductions
{
    GameState::GameState(GameDataRef data) : _data(data)
    {
        
    }
    
    void GameState::Init()
    {
        // Texture management 
        this->_data->assets.RemoveTexture("Splash_BG");
        this->_data->assets.LoadTexture("brick_floor", FLOOR_PATH);
        this->_data->assets.LoadTexture("Land", GRASS_LAND_FILEPATH);
        this->_data->assets.LoadTexture("Player Frame 0", PLAYER_FRAME_0_FILEPATH);
        this->_data->assets.LoadTexture("Player Frame 1", PLAYER_FRAME_1_FILEPATH);
        this->_data->assets.LoadTexture("Player Frame 2", PLAYER_FRAME_2_FILEPATH);
        this->_data->assets.LoadTexture("Player Frame 3", PLAYER_FRAME_3_FILEPATH);
        this->_data->assets.LoadTexture("Player Jump", PLAYER_JUMP_FILEPATH);
        this->_data->assets.LoadTexture("heart", HEART_PATH);
        this->_data->assets.LoadTexture("Goomba_0", GOOMBA_FRAME_0_FILEPATH);
        this->_data->assets.LoadTexture("Goomba_1", GOOMBA_FRAME_1_FILEPATH);
        this->_data->assets.LoadFont("score_font", FONT_PATH);
        
        //Player Jump
        
        // Music
        this->_gameTheme.openFromFile(GAME_THEME_PATH);
        this->_gameTheme.setLoop(true);
        
        this->_gameTheme.setVolume(0);
        
        // Sounds
        this->_bumpBuffer.loadFromFile(BUMP_SOUND_PATH);
        this->_bumpSound.setBuffer(_bumpBuffer);
        this->_jumpBuffer.loadFromFile(JUMP_SOUND_PATH);
        this->_jumpSound.setBuffer(_jumpBuffer);
        this->_stompBuffer.loadFromFile(STOMP_SOUND_PATH);
        this->_stompSound.setBuffer(_stompBuffer);
        
        // Score
        this->_score.setFont(this->_data->assets.GetFont("score_font"));
        this->_score.setPosition(1580, 10);
        this->_score.setFillColor(sf::Color(255, 255, 255));
        
        // Version
        this->_versionName.setFont(this->_data->assets.GetFont("score_font"));
        this->_versionName.setPosition(0, SCREEN_HEIGHT-35);
        this->_versionName.setFillColor(sf::Color(255, 255, 255, 200));
        this->_versionName.setString("Ver: Indev 0.01");
        
        // Pointer initialization
        this->platform = std::make_unique<Platform>(_data);
        this->land = std::make_unique<Land>(_data);
        this->player = std::make_unique<Player>(_data);
        this->heart = std::make_unique<Heart>(_data);
        this->goomba = std::make_unique<Goomba>(_data);

        // Platforms use the same texture as the floor does so no initialization
//        platform->spawnInvisiblePlatform();
        this->platform->spawnPlatform();
        
        this->_gameStatus = GameStatus::ePlaying;
        this->_additionalPoints = 0;
        
        this->_gameTheme.play();
        this->_data->gameClock.restart();
    }
    
    void GameState::HandleInput()
    {
        sf::Event event;
        
        while (this->_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                this->_gameTheme.stop();
                this->_jumpSound.stop();
                this->_bumpSound.stop();
                this->_stompSound.stop();
                this->_data->window.close();
            }
            else if (sf::Event::KeyPressed == event.type && this->_gameStatus != GameStatus::eGameOver && this->player->GetPlayerState() == PLAYER_STATE_WALK)
            {
                this->player->Jump();
                this->_jumpSound.play();
            }
        }
    }
    
    void GameState::Update(float dt)
    {
        if (this->_gameStatus != GameStatus::eGameOver)
        {
            this->player->Animate(dt);
            this->goomba->Animate(dt);
            this->land->MoveLand(dt);
            this->platform->movePlatforms(dt);
            this->goomba->MoveGoombas(dt);
            this->_score.setString("Points:" + std::to_string((int)_scoreClock.getElapsedTime().asSeconds() + _additionalPoints));
        }
        
        if (this->_gameStatus == GameStatus::ePlaying)
        {
            bool isPlayerStandingOnSomething = false;
            
            if(this->_respawnerClock.getElapsedTime().asSeconds() > PLATFORM_SPWN_FREQ)
            {
                platform->spawnPlatform();
                // TODO: Maybe change this make it initialize at some other time
                if(rand()%2 == 0)
                    this->goomba->SpawnAGoomba();
                this->_respawnerClock.restart();
            }
            
            this->player->Update(dt);
            
            std::vector<sf::Sprite> goombaSprites = goomba->GetSprites();
            for(int i=0; i < goombaSprites.size(); i++)
            {
                if(this->collision.CheckSpriteCollision(player->GetSprite(), goombaSprites.at(i)))
                {
                    if (this->player->GetPlayerState() != PLAYER_STATE_FALL && !player->IsPlayerInvincible())
                    {
                        if(this->heart->GetHealth() != 0)
                        {
                            // TODO: Game state for game over
                            heart->ReceiveDMG();
                            goomba->DeleteGoomba(i);
                            _bumpSound.play();
                            player->MakePlayerInvincible();
                        }
                        else
                            _gameStatus = GameStatus::eGameOver;
                    }
                    else if(player->IsPlayerInvincible())
                    {
                        
                    }
                    else if (player->GetPlayerState() == PLAYER_STATE_FALL)
                    {
                        goomba->DeleteGoomba(i);
                        _additionalPoints += 200;
                        this->player->Bounce();
                        this->_stompSound.play();
                        return;
                    }
                }
            }
            
            std::vector<sf::Sprite> landSprites = land->GetSprites();
                
            for(int i=0; i < landSprites.size(); i++)
            {
                if(collision.CheckSpriteCollision(player->GetSprite(), landSprites.at(i)))
                {
                    isPlayerStandingOnSomething = true;
                    this->player->SetPlayerState(PLAYER_STATE_WALK);
                    return;
                }
            }
                
            std::vector<sf::Sprite> platformSprites = platform->GetSprites();

            for (int i=0; i < platformSprites.size(); i++)
            {
                if(this->collision.IsSpriteOnPlatform(player->GetSprite(), platformSprites.at(i)))
                {
                    isPlayerStandingOnSomething = true;
                    this->player->SetPlayerState(PLAYER_STATE_WALK);
                    return;
                }
            }
            
            if(!isPlayerStandingOnSomething && this->player->GetPlayerState() != PLAYER_STATE_RISE)
                player->SetPlayerState(PLAYER_STATE_FALL);
        }
        
        if (this->_gameStatus == GameStatus::eGameOver)
        {
            this->_gameTheme.stop();
            this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
        }
    }
    
    void GameState::Draw(float dt)
    {
        this->_data->window.clear(sf::Color(152, 180, 226));
        this->land->DrawLand();
        this->platform->DrawPlatforms();
        this->goomba->DrawGoombas();
        this->player->Draw();
        this->heart->DrawHearts();
        
        this->_data->window.draw(_score);
        this->_data->window.draw(_versionName);
        
        this->_data->window.display();
    }
    
    void GameState::ResetState()
    {
        // Restart clocks
        this->_respawnerClock.restart();
        this->_scoreClock.restart();
        
        // Set additional points and the point text to zero
        this->_additionalPoints = 0;
        this->_score.setString("Score:0");
        
        // Restart song
        // ======================================= CHECK IF IT WORKS =======================================
        this->_gameTheme.stop();
        this->_gameTheme.play();
        
        // Purge or reset objects
        this->goomba->PurgeGoombas();
        this->platform->PurgePlatforms();
        this->heart->RestartHearts();
        this->player->ResetPlayer();
        
    }
}
