#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"
#include "Obstacle.h"

#include "Human.h"
#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameOverState.hpp"
#include "InputManager.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Flash.h"
#include "MainMenuState.hpp"
#include "FinishedWinState.h"
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
		static void updateLevel()
		{
			_level++;
		}
		static void resetLevel()
		{
			_level=1;
		}
			static int _level;

	private:
		GameDataRef _data;

	
		sf::Sprite _background;
		sf::Sprite _laneCar;
		sf::Sprite _laneSheep;
		sf::Sprite _laneTruck;
		sf::Sprite _laneDog;
		sf::Sprite _skyBackground;
		sf::Sprite _coin;

		sf::Sprite _exitButton;
		sf::Sprite _menuButton;
		sf::Sprite _replayButton;
		sf::Sprite _pauseButton;

		sf::Sprite _trafficLight1;
		sf::Sprite _trafficLight2;
		sf::Clock clock;

		float _currentTimeTrafficLight;
		float _newTimeTrafficLight;

		int _gameState;
		int _score;

		bool whichPause=true;
		vector<Sheep> sheeps=InitSheep(_level);
		vector<Car>cars=InitCar(_level);
		vector<Truck>trucks=InitTruck(_level);
		vector<Dog>dogs=InitDog(_level);

		Human *human=nullptr;
		Flash *flash=nullptr;
		sf::RectangleShape _gameOverFlash;
		bool _flashOn;
		bool _isStop=false;

	};
