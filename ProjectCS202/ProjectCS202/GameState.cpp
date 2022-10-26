#pragma once

#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include "GameOverState.hpp"
#include <iostream>

	GameState::GameState(GameDataRef data) : _data(data)
	{

	}

	void GameState::Init()
	{

		this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
		
		_gameState = GameStates::eReady;
	}

	void GameState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
		}
	}

	void GameState::Update(float dt)
	{
		if (GameStates::eGameOver != _gameState)
		{
			
		}

		if (GameStates::ePlaying == _gameState)
		{
			
		}

		if (GameStates::eGameOver == _gameState)
		{
				_data->machine.AddState(StateRef(new GameOverState(_data,_score)),true);
		}
		
	}

	void GameState::Draw(float dt)
	{
		this->_data->window.clear( sf::Color::Red );

		this->_data->window.draw(this->_background);

		this->_data->window.display();
	}

