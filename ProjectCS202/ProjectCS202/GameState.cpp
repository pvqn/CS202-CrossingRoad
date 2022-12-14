

#include "GameState.hpp"

GameState::GameState(GameDataRef data, bool isLoad) : _data(data), _isLoad(isLoad)
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

	_exitButton.setPosition(26, 26);
	_menuButton.setPosition(26 + BUTTON_WIDTH, 26);
	_replayButton.setPosition(26 + BUTTON_WIDTH * 2, 26);
	_pauseButton.setPosition(26 + BUTTON_WIDTH * 3, 26);

	_trafficLight1.setPosition(0, 174);
	_trafficLight2.setPosition(0, 174 + 66 * 6);

	human = new Human;
	flash = new Flash(_data);

	if (!_isLoad)
	{
		human->setPos((SCREEN_WIDTH / 2 - HUMAN_WIDTH / 2), (SCREEN_HEIGHT - HUMAN_HEIGHT) * 1.2);

		this->sheeps = InitSheep(this->_level);
		this->trucks = InitTruck(this->_level);
		this->cars = InitCar(this->_level);
		this->dogs = InitDog(this->_level);
		_coin.setPosition(55 + (rand() % 845), 171);
		setTimeStart();
	}
	else
	{
		LoadGameFromeFile();
	}

	_newTimeTrafficLight = this->clock.getElapsedTime().asSeconds();
	//_gameState = GameStates::eReady;
	_gameState = GameStates::ePlaying;
	std::cout << "level " << _level << " \n";
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
				_isStop = true;
			}
			else
			{
				whichPause = true;
				_pauseButton.setTexture(this->_data->assets.GetTexture("Pause1 Button"));
				_isStop = false;
			}
		}
		if (this->_data->input.IsSpriteClicked(_replayButton, sf::Mouse::Left, this->_data->window))
		{
			_data->machine.AddState(StateRef(new GameState(_data, false)), true);
		}
		if (this->_data->input.IsSpriteClicked(_menuButton, sf::Mouse::Left, this->_data->window))
		{
			// ADD SAVE GAME
			SaveGameToFile();
			resetLevel();
			_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}
	}
}

void GameState::Update(float dt)
{

	if (GameStates::ePlaying == _gameState)
	{
		if (!_isStop)
		{
			human->move();
			human->updateCollision(this->_data->window);
			MoveSheep(sheeps, this->_data->window);
			MoveCar(cars, this->_data->window);
			MoveTruck(trucks, this->_data->window);
			MoveDog(dogs, this->_data->window);
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
			for (int i = 0; i < VEHICLE_AMOUNT; ++i)
			{
				if (this->_data->input.IsCollision(human->getSprite(), 0.4f, trucks[i].getSprite(), 0.7f))
				{
					_gameState = GameStates::eGameOver;
					_timePassed = getTimeEnd();
					clock.restart();
					break;
				}
				if (this->_data->input.IsCollision(human->getSprite(), 0.4f, cars[i].getSprite(), 0.7f))
				{
					_gameState = GameStates::eGameOver;
					_timePassed = getTimeEnd();
					clock.restart();
					break;
				}
			}
			for (int i = 0; i < ANIMAL_AMOUNT; ++i)
			{
				if (this->_data->input.IsCollision(human->getSprite(), 0.4f, sheeps[i].getSprite(), 0.7f))
				{
					_gameState = GameStates::eGameOver;
					_timePassed = getTimeEnd();
					clock.restart();
					break;
				}
				if (this->_data->input.IsCollision(human->getSprite(), 0.4f, dogs[i].getSprite(), 0.7f))
				{
					_gameState = GameStates::eGameOver;
					_timePassed = getTimeEnd();
					clock.restart();
					break;
				}
			}
			if (this->_data->input.IsCollision(human->getSprite(), 0.4f, _skyBackground, 0.9f))
			{
				if (this->_data->input.IsCollision(human->getSprite(), 1.0f, _coin, 1.2f))
				{
					updateLevel();
					_data->machine.AddState(StateRef(new FinishedWinState(_data)), true);
				}
				_gameState = GameStates::eGameOver;
				_timePassed = getTimeEnd();

				clock.restart();
			}
		}
	}
	else if (GameStates::eGameOver == _gameState)
	{
		flash->Show(dt);
		if (clock.getElapsedTime().asSeconds() > BEFORE_GAME_OVER_APPEAR_TIME)
			_data->machine.AddState(StateRef(new GameOverState(_data)), true);
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

	for (int i = 0; i < VEHICLE_AMOUNT; ++i)
	{
		trucks[i].Draw(this->_data->window);
		cars[i].Draw(this->_data->window);
	}

	for (int i = 0; i < ANIMAL_AMOUNT; ++i)
	{
		sheeps[i].Draw(this->_data->window);
		dogs[i].Draw(this->_data->window);
	}
	human->render(this->_data->window);
	flash->Draw();
	this->_data->window.display();
}

void GameState::setTimeStart()
{
	this->_timeStart = this->clock.getElapsedTime().asSeconds();
}
float GameState::getTimeEnd()
{
	return this->clock.getElapsedTime().asSeconds() - this->_timeStart;
}
int GameState::getLevel() { return this->_level; }

void GameState::SaveGameToFile()
{
	std::ofstream fout;
	fout.open(LOAD_FILE_FILEPATH, std::ios::out);
	if (fout.is_open())
	{
		// LEVEL
		fout << _level << std::endl;

		// TIME
		fout << _timePassed << std::endl;
		// OBSTACLE
		// Sheep[0] Dog[0] Sheep[1] Dog[1] .....
		for (int i = 0; i < ANIMAL_AMOUNT; ++i)
		{
			fout << sheeps[i].getSprite().getPosition().x << " " << sheeps[i].getSprite().getPosition().y << " ";
			fout << dogs[i].getSprite().getPosition().x << " " << sheeps[i].getSprite().getPosition().y;
		}
		fout << std::endl;
		// Car[0] Truck[0] Car[1] Truck[1] .....
		for (int i = 0; i < VEHICLE_AMOUNT; ++i)
		{
			fout << cars[i].getSprite().getPosition().x << " " << cars[i].getSprite().getPosition().y << " ";
			fout << trucks[i].getSprite().getPosition().x << " " << trucks[i].getSprite().getPosition().y;
		}
		fout << std::endl;
		// COIN
		fout << _coin.getPosition().x << " " << _coin.getPosition().y << std::endl;
		// HUMAN
		fout << this->human->getPos().x << " " << human->getPos().y << std::endl;
	}
	else
	{
		std::cout << "Open saveGame file failed!" << std::endl;
	}
	fout.close();
}
void GameState::LoadGameFromeFile()
{
	std::ifstream fin;
	fin.open(LOAD_FILE_FILEPATH, std::ios::in);
	if (fin.is_open())
	{
		fin >> this->_level;
		fin >> this->_timeStart;
		for (int i = 0; i < ANIMAL_AMOUNT; ++i)
		{
			float x, y;
			fin >> x >> y;
			this->sheeps[i].SetPosXY(x, y);
			fin >> x >> y;
			this->dogs[i].SetPosXY(x, y);
		}
		for (int i = 0; i < VEHICLE_AMOUNT; ++i)
		{
			float x, y;
			fin >> x >> y;
			this->cars[i].SetPosXY(x, y);
			fin >> x >> y;
			this->trucks[i].SetPosXY(x, y);
		}
		float x, y;
		fin >> x >> y;
		this->_coin.setPosition(x, y);
		fin >> x >> y;
		this->human->setPos(x, y);
	}

	fin.close();
}
int GameState::getLevel() {return this->level;}

void GameState::SaveGameToFile() {
    ofstream fout;
   	fout.open(LOAD_FILE_FILEPATH, ios::out);
    if(fout.is_open()) {
        // LEVEL SCORE
        fout << _level << " " << _score << endl;;
        // TIME
//        fout << ...
        // OBSTACLE
        // Sheep[0] Dog[0] Sheep[1] Dog[1] .....
        
        for(int i = 0; i < ANIMAL_AMOUNT; ++i) {
            fout << sheeps[i].getPosXY().x << " " << sheeps[i].getPosXY().y << " ";
            fout << dogs[i].getPosXY().x << " " << dogs[i].getPosXY().y << " ";
        } fout << endl;
        // Car[0] Truck[0] Car[1] Truck[1] .....
        for(int i = 0; i < VEHICLE_AMOUNT; ++i) {
            fout << cars[i].getPosXY().x << " " << cars[i].getPosXY().y << " ";
            fout << trucks[i].getPosXY().x << " " << trucks[i].getPosXY().y << " ";
        } fout << endl;
        // COIN
        fout << _coin.getPosition().x << " " << _coin.getPosition().y << " ";
        // HUMAN
        fout << human->getPos().x << " " << human->getPos().y << endl;
    }
    else 
        cout << "Open saveGame file failed!" << endl;
    fout.close();
}
void GameState::LoadGameFromeFile() {
    ifstream fin;
    fin.open(LOAD_FILE_FILEPATH, ios::in);
    if(fin.is_open()) {
        fin >> _level >> _score; fin.ignore();
        double x1, y1, x2, y2;
        for(int i = 0; i < ANIMAL_AMOUNT; ++i) {
            fin >> x1 >> y1;
            fin >> x2 >> y2;
            sheeps[i].SetPosXY(x1, y1);
            dogs[i].SetPosXY(x2, y2);
        } fin.ignore();
        for(int i = 0; i < VEHICLE_AMOUNT; ++i) {
            fin >> x1 >> y1 >> x2 >> y2;
            cars[i].SetPosXY(x1, y1);
            trucks[i].SetPosXY(x2, y2);
        } fin.ignore();
        fin >> x1 >> y1 >> x2 >> y2;
        _coin.setPosition(x1, y1);
    }
    else cout << "Open saveGame file failed!" << endl;
    fin.close();
}