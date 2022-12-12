

#include "InputManager.hpp"

bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window)
{
	if (sf::Mouse::isButtonPressed(button))
	{
		sf::IntRect playButtonRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

		if (playButtonRect.contains(sf::Mouse::getPosition(window)))
		{
			return true;
		}
	}

	return false;
}
bool InputManager::IsHover(sf::Sprite object, sf::RenderWindow &window)
{
	if (object.getGlobalBounds().contains(GetMousePosition(window).x, GetMousePosition(window).y))
	{
		std::cout <<"HIT \n";
		return true;
	}
	return false;
}
bool InputManager::IsCollision(sf::Sprite object1, float scale1, sf::Sprite object2, float scale2)
{

	object1.setScale(scale1, scale1);
	object2.setScale(scale2, scale2);

	sf::Rect<float> rect1 = object1.getGlobalBounds();
	sf::Rect<float> rect2 = object2.getGlobalBounds();

	if (rect1.intersects(rect2))
	{
		return true;
	}

	return false;
}

sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow &window)
{
	return sf::Mouse::getPosition(window);
}
