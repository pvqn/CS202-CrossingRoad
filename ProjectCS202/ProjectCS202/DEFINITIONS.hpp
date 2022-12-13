#pragma once


#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

#define SPLASH_STATE_SHOW_TIME 5.0
#define BEFORE_GAME_OVER_APPEAR_TIME 3.0
#define BEFORE_GAME_APPEAR_TIME 2.0
#define FLASH_SPEED 1500.0f

#define QUICKSAND_REGULAR_FONT "Resources/fonts/Quicksand-Regular.otf"
#define MARKER_FELT_FONT "Resources/fonts/MarkerFelt.ttf"
#define FLAPPY_FONT "Resources/fonts/FlappyFont.ttf"


#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/res/background1.png"
#define FINISHED_WIN_BACKGROUND_FILEPATH "Resources/res/winFinishedState.png"
#define FINISHED_TITLE_BACKGROUND_FILEPATH "Resources/res/levelup.png"

#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/res/background2.png"
#define GAME_BACKGROUND_FILEPATH "Resources/res/background.png"
#define GAME_OVER_BACKGROUND_FILEPATH "Resources/res/"

#define GAME_BACKGROUND_LANE_FILEPATH "Resources/res/street.png"
#define GAME_BACKGROUND_SKY_FILEPATH "Resources/res/sky.png"
#define COIN_FILEPATH "Resources/res/coin.png"

#define EXIT_BUTTON_FILEPATH "Resources/res/exitbutton.png"
#define REPLAY_BUTTON_FILEPATH "Resources/res/replaybutton.png"
#define MENU_BUTTON_FILEPATH "Resources/res/menubutton.png"
#define PAUSE1_BUTTON_FILEPATH "Resources/res/pause1button.png"
#define PAUSE2_BUTTON_FILEPATH "Resources/res/pause2button.png"

#define LOAD_BUTTON_FILEPATH "Resources/res/loadbutton.png"
#define LOAD1_BUTTON_FILEPATH "Resources/res/loadbutton1.png"
#define PLAY_BUTTON_FILEPATH "Resources/res/playbutton.png"
#define PLAY1_BUTTON_FILEPATH "Resources/res/playbutton1.png"
#define RANK_BUTTON_FILEPATH "Resources/res/rankbutton.png"
#define RANK1_BUTTON_FILEPATH "Resources/res/rankbutton1.png"
#define RULE_BUTTON_FILEPATH "Resources/res/rulebutton.png"
#define RULE1_BUTTON_FILEPATH "Resources/res/rulebutton1.png"

#define MENU_TITLE_FILEPATH "Resources/res/menu1button.png"


#define GREEN_LIGHT_FILEPATH "Resources/res/greenLight.png"
#define RED_LIGHT_FILEPATH "Resources/res/redLight.png"


#define GAME_OVER_TITLE_FILEPATH "Resources/res/Game-Over-Title.png"
#define GAME_OVER_BODY_FILEPATH "Resources/res/Game-Over-Body.png" 

#define RANK_FILE_FILEPATH "Resources/texts/rank.txt"
#define LOSE_RANK_BACKGROUND_FILEPATH "Resources/res/lose_rank.png"
#define RANK_STATE_BACKGROUND_FILEPATH "Resources/res/rankState.png"

#define LOAD_FILE_FILEPATH "Resources/texts/load.txt"

#define FONT_FOLDER_FILEPATH "Resources/fonts/"

#define RESOURCE_PATH "Resources/res/"

#define VEHICLE_AMOUNT 5
#define ANIMAL_AMOUNT 7

#define VEHICLE_WIDTH 185
#define ANIMAL_WIDTH 86

#define HUMAN_WIDTH 43
#define HUMAN_HEIGHT 66

#define COIN_WIDTH 65
#define COIN_HEIGHT 60

#define BUTTON_WIDTH 57
#define BUTTON_HEIGHT 57

#define LIGHT_TIME 3
#define CAR_SPEED 2
#define TRUCK_SPEED 1.5
#define DOG_SPEED 0.5
#define SHEEP_SPEED 0.5

#define RED_TIME 3
#define GREEN_TIME 10
enum GameStates
{
	eReady,
	ePlaying,
	eGameOver
};
