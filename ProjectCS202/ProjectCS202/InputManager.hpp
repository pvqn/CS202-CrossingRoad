#pragma once

#include "SFML\Graphics.hpp"
#include <iostream>

	class InputManager
	{
	public:
		InputManager() {}
		~InputManager() {}

		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
		bool IsHover(sf::Sprite object,sf::RenderWindow &window);
		bool IsCollision(sf::Sprite object1, float scale1, sf::Sprite object2, float scale2);
		sf::Vector2i GetMousePosition(sf::RenderWindow &window);
	};
