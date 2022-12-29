
#include "GameOverState.hpp"


GameOverState::GameOverState(GameDataRef data, Rank rank) : _data(data), _rank(rank)
{
}

void GameOverState::Init()
{

	this->_data->assets.LoadTexture("Menu Button", MENU_BUTTON_FILEPATH);
	this->_data->assets.LoadTexture("Exit Button", EXIT_BUTTON_FILEPATH);
	this->_data->assets.LoadTexture("Replay Button", REPLAY_BUTTON_FILEPATH);

		this->_data->assets.LoadTexture("GameOver BackGround", LOSE_RANK_BACKGROUND_FILEPATH);
		this->_data->assets.LoadFont("Flappy", FLAPPY_FONT);
		_rank._sprite.setTexture(this->_data->assets.GetTexture("GameOver BackGround"));
	_menuButton.setTexture(this->_data->assets.GetTexture("Menu Button"));
	_exitButton.setTexture(this->_data->assets.GetTexture("Exit Button"));
	_replayButton.setTexture(this->_data->assets.GetTexture("Replay Button"));
	for (int i = 0; i < _rank._texts.size(); ++i)
	{
		_rank._texts[i].setFont(this->_data->assets.GetFont("Flappy"));
		_rank._texts[i].setOutlineColor(sf::Color(44, 125, 59, 255));
		_rank._texts[i].setOutlineThickness(1.0f);
		_rank._texts[i].setCharacterSize(30);
	}
	_exitButton.setPosition(26, 26);
	_menuButton.setPosition(26 + BUTTON_WIDTH, 26); 
	_replayButton .setPosition(26 + 2*BUTTON_WIDTH, 26);
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
			GameState::resetLevel();
			music1.play();
			music2.stop();
			_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}
		if (_data->input.IsSpriteClicked(_replayButton, sf::Mouse::Left, _data->window))
		{
			music1.play();
			music2.stop();
			_data->machine.AddState(StateRef(new GameState(_data, false)), true);
		}
		if (_data->input.IsSpriteClicked(_exitButton, sf::Mouse::Left, _data->window))
		{
			GameState::resetLevel();
			this->_data->window.close();
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
	int size;
	if (_rank._texts.size() > 6)
		size = 6;
	else size = _rank._texts.size();
	for (int i = 0; i < size; ++i)
	{
		this->_data->window.draw(_rank._texts[i]);
	}
	this->_data->window.draw(_menuButton);
	this->_data->window.draw(_exitButton);
	this->_data->window.draw(_replayButton);

	this->_data->window.display();
}
