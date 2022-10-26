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

enum GameStates
{
	eReady,
	ePlaying,
	eGameOver
};
