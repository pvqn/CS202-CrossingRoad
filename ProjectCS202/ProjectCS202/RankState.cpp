#include "RankState.h"
RankState::RankState(GameDataRef data) : _data(data)
{
}

void RankState::Init()
{
	this->_data->assets.LoadTexture("Rank State Background", RANK_STATE_BACKGROUND_FILEPATH);

	
	this->_data->assets.LoadTexture("Menu Button", MENU_BUTTON_FILEPATH);
	this->_data->assets.LoadTexture("Exit Button", EXIT_BUTTON_FILEPATH);
	this->_data->assets.LoadFont("Flappy", FLAPPY_FONT);

	_rank._sprite.setTexture(this->_data->assets.GetTexture("Rank State Background"));
	_menuButton.setTexture(this->_data->assets.GetTexture("Menu Button"));
	_exitButton.setTexture(this->_data->assets.GetTexture("Exit Button"));
	_exitButton.setPosition(26, 26);
	_menuButton.setPosition(26 + BUTTON_WIDTH, 26);
	for (int i = 0; i < _rank._texts.size(); ++i)
	{
		_rank._texts[i].setFont(this->_data->assets.GetFont("Flappy"));
		_rank._texts[i].setOutlineColor(sf::Color(44, 125, 59, 255));
		_rank._texts[i].setOutlineThickness(1.0f);
		_rank._texts[i].setCharacterSize(35);
	}
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
	this->_data->window.draw(_rank._sprite);
	this->_data->window.draw(_menuButton);
	this->_data->window.draw(_exitButton);
	int size;
	if (_rank._texts.size() > 9)
		size = 9;
	else size = _rank._texts.size();
	for (int i = 0; i < size; ++i)
	{
		this->_data->window.draw(_rank._texts[i]);
	}
	this->_data->window.display();
}
