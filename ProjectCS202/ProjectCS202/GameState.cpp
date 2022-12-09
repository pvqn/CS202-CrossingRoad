

#include "GameState.hpp"

GameState::GameState(GameDataRef data) : _data(data)
{
}

void GameState::Init()
{
	srand(time(NULL));
	this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
	this->_data->assets.LoadTexture("Lane", GAME_BACKGROUND_LANE_FILEPATH);
	this->_data->assets.LoadTexture("Sky", GAME_BACKGROUND_SKY_FILEPATH);
	this->_data->assets.LoadTexture("Coin", COIN_FILEPATH);

	this->_data->assets.LoadTexture("Menu Button", MENU_BUTTON_FILEPATH);
	this->_data->assets.LoadTexture("Replay Button", REPLAY_BUTTON_FILEPATH);
	this->_data->assets.LoadTexture("Exit Button", EXIT_BUTTON_FILEPATH);
	this->_data->assets.LoadTexture("Pause1 Button", PAUSE1_BUTTON_FILEPATH);
	this->_data->assets.LoadTexture("Pause2 Button", PAUSE2_BUTTON_FILEPATH);

	this->_data->assets.LoadTexture("Red Light", RED_LIGHT_FILEPATH);
	this->_data->assets.LoadTexture("Green Light", GREEN_LIGHT_FILEPATH);

	_background.setTexture(this->_data->assets.GetTexture("Game Background"));
	_laneCar.setTexture(this->_data->assets.GetTexture("Lane"));
	_laneTruck.setTexture(this->_data->assets.GetTexture("Lane"));
	_laneSheep.setTexture(this->_data->assets.GetTexture("Lane"));
	_laneDog.setTexture(this->_data->assets.GetTexture("Lane"));
	_skyBackground.setTexture(this->_data->assets.GetTexture("Sky"));
	_coin.setTexture(this->_data->assets.GetTexture("Coin"));

	_menuButton.setTexture(this->_data->assets.GetTexture("Menu Button"));
	_pauseButton.setTexture(this->_data->assets.GetTexture("Pause1 Button"));
	_exitButton.setTexture(this->_data->assets.GetTexture("Exit Button"));
	_replayButton.setTexture(this->_data->assets.GetTexture("Replay Button"));

	_trafficLight1.setTexture(this->_data->assets.GetTexture("Green Light"));
	_trafficLight2.setTexture(this->_data->assets.GetTexture("Green Light"));

	_laneCar.setPosition(0, 240);
	_laneTruck.setPosition(0, 636);
	_laneSheep.setPosition(0, 504);
	_laneDog.setPosition(0, 373);
	_skyBackground.setPosition(0, 0);
	_coin.setPosition(55 + (rand() % 845), 171);

	_exitButton.setPosition(26, 26);
	_menuButton.setPosition(26 + BUTTON_WIDTH, 26);
	_replayButton.setPosition(26 + BUTTON_WIDTH * 2, 26);
	_pauseButton.setPosition(26 + BUTTON_WIDTH * 3, 26);

	_trafficLight1.setPosition(0, 174);
	_trafficLight2.setPosition(0, 174 + 66 * 6);

	human = new Human;
	human->setPos((SCREEN_WIDTH / 2 - HUMAN_WIDTH / 2), (SCREEN_HEIGHT - HUMAN_HEIGHT));
	_newTimeTrafficLight = this->clock.getElapsedTime().asSeconds();
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
		if (this->_data->input.IsSpriteClicked(_pauseButton, sf::Mouse::Left, this->_data->window))
		{
			if (whichPause)
			{
				_pauseButton.setTexture(this->_data->assets.GetTexture("Pause2 Button"));
				whichPause = false;
			}
			else
			{
				whichPause = true;
				_pauseButton.setTexture(this->_data->assets.GetTexture("Pause1 Button"));
			}
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

		_newTimeTrafficLight = this->clock.getElapsedTime().asSeconds();
		if (cars[0].CheckLight() && (_newTimeTrafficLight - _currentTimeTrafficLight >= RED_TIME))
		{
			// switchToGreenLight
			for (int i = 0; i < cars.size(); ++i)
			{
				cars[i].SwitchLightSignal();
				cars[i].LightSignal();
			}
			for (int i = 0; i < trucks.size(); ++i)
			{
				trucks[i].SwitchLightSignal();
				trucks[i].LightSignal();
			}

			// updateTexture
			_trafficLight2.setTexture(this->_data->assets.GetTexture("Green Light"));
			_trafficLight1.setTexture(this->_data->assets.GetTexture("Green Light"));
			_currentTimeTrafficLight = _newTimeTrafficLight;
		}

		if (!cars[0].CheckLight() && (_newTimeTrafficLight - _currentTimeTrafficLight >= GREEN_TIME))
		{
			// switchToGreenLight
			for (int i = 0; i < cars.size(); ++i)
			{
				cars[i].SwitchLightSignal();
				cars[i].LightSignal();
			}
			for (int i = 0; i < trucks.size(); ++i)
			{
				trucks[i].SwitchLightSignal();
				trucks[i].LightSignal();
			}

			// updateTexture
			_trafficLight2.setTexture(this->_data->assets.GetTexture("Red Light"));
			_trafficLight1.setTexture(this->_data->assets.GetTexture("Red Light"));
			_currentTimeTrafficLight = _newTimeTrafficLight;
		}

		
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

	this->_data->window.draw(this->_menuButton);
	this->_data->window.draw(this->_replayButton);
	this->_data->window.draw(this->_exitButton);
	this->_data->window.draw(this->_pauseButton);

	this->_data->window.draw(this->_laneCar);
	this->_data->window.draw(this->_laneTruck);
	this->_data->window.draw(this->_laneDog);
	this->_data->window.draw(this->_laneSheep);

	this->_data->window.draw(_trafficLight1);
	this->_data->window.draw(_trafficLight2);

	MoveSheep(sheeps, this->_data->window);
	MoveCar(cars, this->_data->window);
	MoveTruck(trucks, this->_data->window);
	MoveDog(dogs, this->_data->window);
	human->render(this->_data->window);
	this->_data->window.display();
}
