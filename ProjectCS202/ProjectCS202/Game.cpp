#include "Game.hpp"
#include "SplashState.hpp"
#include "GameState.hpp"
#include <stdlib.h>
#include <time.h>
#include "FinishedWinState.h"

sf::Music music1;
sf::Music music2;
Game::Game(int width, int height, std::string title)
{
	_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
	_data->machine.AddState(StateRef(new SplashState(this->_data)),true);
	music1.openFromFile(string(MUSIC_PATH));
	music2.openFromFile(string(FAIL_MUSIC_PATH));
	music1.setVolume(50);
	music2.setVolume(50);
	music1.setLoop(true);
	music2.setLoop(true);
	this->Run();
}

void Game::Run()
{
	//music.play();
	float newTime, frameTime, interpolation;

	float currentTime = this->_clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;

	while (this->_data->window.isOpen())
	{
		this->_data->machine.ProcessStateChanges();
		newTime = this->_clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;

		if (frameTime > 0.25f)
		{
			frameTime = 0.25f;
		}

		currentTime = newTime;
		accumulator += frameTime;

		while (accumulator >= dt)
		{
			this->_data->machine.GetActiveState()->HandleInput();
			this->_data->machine.GetActiveState()->Update(dt);

			accumulator -= dt;
		}

		interpolation = accumulator / dt;
		this->_data->machine.GetActiveState()->Draw(interpolation);
		
	}
}
