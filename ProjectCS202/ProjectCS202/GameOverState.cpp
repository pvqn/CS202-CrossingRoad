
#include "GameOverState.hpp"

GameOverState::GameOverState(GameDataRef data, Rank rank) : _data(data), _rank(rank)
{
}

void GameOverState::Init()
{

	this->_data->assets.LoadTexture("Menu Button", MENU_BUTTON_FILEPATH);
	this->_data->assets.LoadTexture("Exit Button", EXIT_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("GameOver BackGround", LOSE_RANK_BACKGROUND_FILEPATH);
		_rank._sprite.setTexture(this->_data->assets.GetTexture("GameOver BackGround"));
	_menuButton.setTexture(this->_data->assets.GetTexture("Menu Button"));
	_exitButton.setTexture(this->_data->assets.GetTexture("Exit Button"));
	_exitButton.setPosition(26, 26);
	_menuButton.setPosition(26 + BUTTON_WIDTH, 26);
	
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
		if (_data->input.IsSpriteClicked(_menuButton, sf::Mouse::Left, _data->window))
		{
			_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}
	}
}

void GameOverState::Update(float dt)
{
}

void GameOverState::Draw(float dt)
{
	this->_data->window.clear(sf::Color::Red);
	this->_data->window.draw(_rank._sprite);
	this->_data->window.draw(_menuButton);
	this->_data->window.draw(_exitButton);
	
	this->_data->window.display();
}
