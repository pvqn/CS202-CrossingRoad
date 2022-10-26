#pragma once

#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameOverState.hpp"
#include "GameState.hpp"
#include <iostream>
#include <fstream>
namespace Sonar
{
	GameOverState::GameOverState(GameDataRef data, int score) : _data(data), _score(score)
	{

	}

	void GameOverState::Init()
	{
		
		this->_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);
		


		_background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
		_gameOverTitle.setTexture(this->_data->assets.GetTexture("Game Over Title"));
		_retryButton.setTexture(this->_data->assets.GetTexture("Play Button"));

	}

	void GameOverState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			if (_data->input.IsSpriteClicked(_retryButton, sf::Mouse::Left, _data->window))
			{
				_data->machine.AddState(StateRef(new GameState(_data)),true);
			}
		}
	}

	void GameOverState::Update(float dt)
	{
		
	}

	void GameOverState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_gameOverTitle);
		this->_data->window.draw(this->_retryButton);
		this->_data->window.display();
	}
}