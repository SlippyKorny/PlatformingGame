#pragma once

#define SCREEN_HEIGHT 1080
//#define SCREEN_HEIGHT 768
#define SCREEN_WIDTH 1920
//#define SCREEN_WIDTH 1366
#define GAME_NAME "PlatformingGame"

#define SPLASH_STATE_SHOW_TIME 2.0

#define SPLASH_SCENE_BACKGROUND_FILEPATH "/Users/slipper/Documents/Projects/Game Dev/SFML/PlatformingGame/PlatformingGame/Assets/Splash_Screen/Arktis_productions_1080.png"

#define FLOOR_PATH "/Users/slipper/Documents/Projects/Game Dev/SFML/PlatformingGame/PlatformingGame/Assets/Textures/ow_brick.png"

#define FLOOR_TEXTURE this->_data->assets.GetTexture("brick_floor")

#define GRASS_LAND_FILEPATH "/Users/slipper/Documents/Projects/Game Dev/SFML/PlatformingGame/PlatformingGame/Assets/Textures/ground.png"

#define PLAYER_FRAME_0_FILEPATH "/Users/slipper/Documents/Projects/Game Dev/SFML/PlatformingGame/PlatformingGame/Assets/Textures/Player_0.png"

#define PLAYER_FRAME_1_FILEPATH "/Users/slipper/Documents/Projects/Game Dev/SFML/PlatformingGame/PlatformingGame/Assets/Textures/Player_1.png"

#define PLAYER_FRAME_2_FILEPATH "/Users/slipper/Documents/Projects/Game Dev/SFML/PlatformingGame/PlatformingGame/Assets/Textures/Player_2.png"

#define PLAYER_FRAME_3_FILEPATH "/Users/slipper/Documents/Projects/Game Dev/SFML/PlatformingGame/PlatformingGame/Assets/Textures/Player_3.png"

#define PLAYER_JUMP_FILEPATH "/Users/slipper/Documents/Projects/Game Dev/SFML/PlatformingGame/PlatformingGame/Assets/Textures/Player_Jump.png"

#define FONT_PATH "/Users/slipper/Documents/Projects/Game Dev/SFML/PlatformingGame/PlatformingGame/Assets/Fonts/emulogic.ttf"

#define HEART_PATH "/Users/slipper/Documents/Projects/Game Dev/SFML/PlatformingGame/PlatformingGame/Assets/Textures/heart.png"

#define GOOMBA_FRAME_0_FILEPATH "/Users/slipper/Documents/Projects/Game Dev/SFML/PlatformingGame/PlatformingGame/Assets/Textures/gumba_0.png"

#define GOOMBA_FRAME_1_FILEPATH "/Users/slipper/Documents/Projects/Game Dev/SFML/PlatformingGame/PlatformingGame/Assets/Textures/gumba_1.png"

#define GAME_THEME_PATH "/Users/slipper/Documents/Projects/Game Dev/SFML/PlatformingGame/PlatformingGame/Assets/Audio/game_theme.ogg"

#define BUMP_SOUND_PATH "/Users/slipper/Documents/Projects/Game Dev/SFML/PlatformingGame/PlatformingGame/Assets/Audio/smb_bump.ogg"

#define JUMP_SOUND_PATH "/Users/slipper/Documents/Projects/Game Dev/SFML/PlatformingGame/PlatformingGame/Assets/Audio/smb_jump-small.ogg"

#define STOMP_SOUND_PATH "/Users/slipper/Documents/Projects/Game Dev/SFML/PlatformingGame/PlatformingGame/Assets/Audio/smb_stomp.ogg"

#define GOOMBA_ANIMATION_DURATION 0.7f

#define GOOMBA_MVMT_SPEED 400.0f

#define FLOOR_WIDTH this->_data->window.getSize().x
#define FLOOR_HEIGHT (10.0f*this->_data->window.getSize().y)/100.0f

#define FIXED_PLATFORM_X_COORDINATE this->_data->window.getSize().x
#define RANDOM_PLATFORM_Y_COORDINATE rand()%this->_data->window.getSize().y

#define MAX_PLATFORM_HEIGHT (SCREEN_HEIGHT)*60.0f/100.0f
#define MIN_PLATFORM_HEIGHT (SCREEN_HEIGHT)*20.0f/100.0f

#define PLATFORM_MVMT_SPEED 250.0f
#define PLATFORM_SPWN_FREQ 3.0f

#define PLAYER_ANIMATION_DURATION 0.7f

#define PLAYER_STATE_WALK 0
#define PLAYER_STATE_FALL 1
#define PLAYER_STATE_RISE 2

#define PLAYER_INVINCIBILITY_TIME 2

#define GRAVITY_FORCE 350.0f

// You might wanna change that to force or even delete both of the next defines as I am not sure if it's gonna be useful
#define JUMP_SPEED -1200.0f

#define JUMP_DURATION 0.20f

enum GameStatus
{
    eReady,
    ePlaying,
    eGameOver
};
