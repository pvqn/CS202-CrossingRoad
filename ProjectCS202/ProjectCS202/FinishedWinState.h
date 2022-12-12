#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include <iostream>
#include <fstream>
class FinishedWinState : public State
	  {
	  public:
	  	FinishedWinState(GameDataRef data);

	  	void Init();

	  	void HandleInput();
	  	void Update(float dt);
	  	void Draw(float dt);

	  private:
	  	GameDataRef _data;

	  	sf::Sprite _background;
		sf::Sprite _title;

		sf::Clock clock;
	  };