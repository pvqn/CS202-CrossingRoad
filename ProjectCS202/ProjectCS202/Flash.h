#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "State.hpp"
#include "Game.hpp"
#include "DEFINITIONS.hpp"
class Flash {
	  public:
	  	Flash(GameDataRef data);

	  	void Show(float dt);
		void Draw();

	  private:
	  	GameDataRef _data;

	  	sf::RectangleShape _shape;

		bool _flashOn;
	  };
