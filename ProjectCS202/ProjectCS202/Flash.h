#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "State.hpp"
#include "Game.hpp"
#include "string"
#include "DEFINITIONS.hpp"
class Flash {
	  public:
	  	Flash(GameDataRef data);

	  	void Show(float dt);
		void Draw();
		sf::Sound _collide;
	  private:
	  	GameDataRef _data;

	  	sf::RectangleShape _shape;
		sf::SoundBuffer _collideBuffer;
		
		bool _flashOn;
	  };
