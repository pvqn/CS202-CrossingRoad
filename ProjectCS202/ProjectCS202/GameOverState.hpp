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
		sf::Sprite _replayButton;
		Rank _rank;

		int _score;
	};
	extern sf::Music music1;
	extern sf::Music music2;