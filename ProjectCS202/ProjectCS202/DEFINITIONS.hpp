#pragma once


#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024

#define SPLASH_STATE_SHOW_TIME 0.0

#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/res/"
#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/res/"
#define GAME_BACKGROUND_FILEPATH "Resources/res/"
#define GAME_OVER_BACKGROUND_FILEPATH "Resources/res/"

#define GAME_TITLE_FILEPATH "Resources/res/"
#define PLAY_BUTTON_FILEPATH "Resources/res/"

#define GAME_OVER_TITLE_FILEPATH "Resources/res/Game-Over-Title.png"
#define GAME_OVER_BODY_FILEPATH "Resources/res/Game-Over-Body.png"

#define RESOURCE_PATH "Resources/res/"

#define VEHICLE_AMOUNT 4
#define ANIMAL_AMOUNT 7

#define VEHICLE_WIDTH 185
#define ANIMAL_WIDTH 86

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
