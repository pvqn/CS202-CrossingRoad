#pragma once


#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

#define SPLASH_STATE_SHOW_TIME 0.0

#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/res/"
#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/res/"
#define GAME_BACKGROUND_FILEPATH "Resources/res/background.png"
#define GAME_OVER_BACKGROUND_FILEPATH "Resources/res/"

#define GAME_BACKGROUND_LANE_FILEPATH "Resources/res/street.png"
#define GAME_BACKGROUND_SKY_FILEPATH "Resources/res/sky.png"
#define COIN_FILEPATH "Resources/res/coin.png"


#define GAME_TITLE_FILEPATH "Resources/res/"
#define PLAY_BUTTON_FILEPATH "Resources/res/"

#define GAME_OVER_TITLE_FILEPATH "Resources/res/Game-Over-Title.png"
#define GAME_OVER_BODY_FILEPATH "Resources/res/Game-Over-Body.png" 

#define RESOURCE_PATH "Resources/res/"

#define VEHICLE_AMOUNT 5
#define ANIMAL_AMOUNT 7

#define VEHICLE_WIDTH 185
#define ANIMAL_WIDTH 86

#define HUMAN_WIDTH 43
#define HUMAN_HEIGHT 66

#define COIN_WIDTH 65
#define COIN_HEIGHT 60

#define LIGHT_TIME 3
#define CAR_SPEED 2
#define TRUCK_SPEED 1.5
#define DOG_SPEED 1
#define SHEEP_SPEED 0.5

enum GameStates
{
	eReady,
	ePlaying,
	eGameOver
};
