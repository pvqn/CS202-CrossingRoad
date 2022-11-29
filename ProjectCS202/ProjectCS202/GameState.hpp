#pragma once

#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"
#include "Obstacle.h"

#include "Human.h"
#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameOverState.hpp"
#include <iostream>
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _laneCar;
		sf::Sprite _laneSheep;
		sf::Sprite _laneTruck;
		sf::Sprite _laneDog;
		sf::Sprite _skyBackground;
		sf::Sprite _coin;

		sf::Clock clock;

		int _gameState;

		int _score;
		vector<Sheep> sheeps=InitSheep(1);
		vector<Car>cars=InitCar(1);
		vector<Truck>trucks=InitTruck(1);
		vector<Dog>dogs=InitDog(1);

		Human *human=nullptr;

	};
