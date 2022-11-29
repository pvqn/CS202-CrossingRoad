

#include "GameState.hpp"

GameState::GameState(GameDataRef data) : _data(data)
{
}

void GameState::Init()
{

	this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
	this->_data->assets.LoadTexture("Lane", GAME_BACKGROUND_LANE_FILEPATH);
	this->_data->assets.LoadTexture("Sky", GAME_BACKGROUND_SKY_FILEPATH);
	this->_data->assets.LoadTexture("Coin", COIN_FILEPATH);

	_background.setTexture(this->_data->assets.GetTexture("Game Background"));
	_laneCar.setTexture(this->_data->assets.GetTexture("Lane"));
	_laneTruck.setTexture(this->_data->assets.GetTexture("Lane"));
	_laneSheep.setTexture(this->_data->assets.GetTexture("Lane"));
	_laneDog.setTexture(this->_data->assets.GetTexture("Lane"));
	_skyBackground.setTexture(this->_data->assets.GetTexture("Sky"));
	_coin.setTexture(this->_data->assets.GetTexture("Coin"));

	_laneCar.setPosition(0, 240);
	_laneTruck.setPosition(0, 636);
	_laneSheep.setPosition(0, 504);
	_laneDog.setPosition(0, 373);
	_skyBackground.setPosition(0, 0);
	_coin.setPosition((SCREEN_WIDTH / 2 - COIN_WIDTH / 2),171);

	human = new Human;
	human->setPos((SCREEN_WIDTH / 2 - HUMAN_WIDTH / 2), (SCREEN_HEIGHT - HUMAN_HEIGHT));

	//_gameState = GameStates::eReady;
	_gameState = GameStates::ePlaying;
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
		human->move();
		human->updateCollision(this->_data->window);
	}

	if (GameStates::eGameOver == _gameState)
	{
		_data->machine.AddState(StateRef(new GameOverState(_data, _score)), true);
	}
}

void GameState::Draw(float dt)
{
	this->_data->window.clear(sf::Color::Red);
	this->_data->window.draw(this->_background);
	this->_data->window.draw(this->_skyBackground);
	this->_data->window.draw(this->_coin);

	this->_data->window.draw(this->_laneCar);
	this->_data->window.draw(this->_laneTruck);
	this->_data->window.draw(this->_laneDog);
	this->_data->window.draw(this->_laneSheep);
	MoveSheep(sheeps, this->_data->window);
	MoveCar(cars, this->_data->window);
	MoveTruck(trucks, this->_data->window);
	MoveDog(dogs, this->_data->window);
	human->render(this->_data->window);
	this->_data->window.display();
}
