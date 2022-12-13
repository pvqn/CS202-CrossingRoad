#include "RankState.h"
RankState::RankState(GameDataRef data) : _data(data)
{
}

void RankState::Init()
{
	this->rank = new Rank;
	this->_data->assets.LoadTexture("Menu Button", MENU_BUTTON_FILEPATH);
	this->_data->assets.LoadTexture("Exit Button", EXIT_BUTTON_FILEPATH);
	_menuButton.setTexture(this->_data->assets.GetTexture("Menu Button"));
	_exitButton.setTexture(this->_data->assets.GetTexture("Exit Button"));
	_exitButton.setPosition(26, 26);
	_menuButton.setPosition(26 + BUTTON_WIDTH, 26);
}

void RankState::HandleInput()
{
	sf::Event event;

	while (this->_data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->_data->window.close();
		}
		if (this->_data->input.IsSpriteClicked(_menuButton, sf::Mouse::Left, this->_data->window))
		{
			_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}
	}
}

void RankState::Update(float dt)
{
	
}

void RankState::Draw(float dt)
{
	this->_data->window.clear(sf::Color::Red);
	this->_data->window.draw(_menuButton);
	this->_data->window.draw(_exitButton);
	this->rank->draw(this->_data->window);
	this->rank->draw_Texts(this->_data->window);
	this->_data->window.display();
}
