#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"


struct GameData
{
	StateMachine machine;
	sf::RenderWindow window;
	AssetManager assets;
	InputManager input;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game
{
public:
	Game(int width, int height, std::string title);

private:
	// Updates run at 60 per second.
	const float dt = 1.0f / 60.0f;
	sf::Clock _clock;
	sf::Music music;
	GameDataRef _data = std::make_shared<GameData>();

	void Run();
};