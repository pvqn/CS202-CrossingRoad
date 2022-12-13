#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include <iostream>
#include <fstream>
#include "Rank.hpp"
	class GameOverState : public State
	{
	public:
		GameOverState(GameDataRef data, Rank rank);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _menuButton;
		sf::Sprite _exitButton;
	
		Rank _rank;

		int _score;
	};
