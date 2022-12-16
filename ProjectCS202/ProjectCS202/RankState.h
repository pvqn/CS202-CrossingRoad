#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "State.hpp"
#include "Game.hpp"
#include "Rank.hpp"
#include "MainMenuState.hpp"
class RankState : public State
	  {
	  public:
	  	RankState(GameDataRef data);

	  	void Init();
		
	  	void HandleInput();
	  	void Update(float dt);
	  	void Draw(float dt);

	  private:
	  	GameDataRef _data;


	  	sf::Sprite _menuButton;
	  	sf::Sprite _exitButton;

		Rank _rank;
        
	  };
