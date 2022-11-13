#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Human
{
	sf::Sprite sprite;
	sf::Texture texture;
	float speed;

	void initSprite();
	void initTexture();
public:
	Human();
	~Human();

	// Move human
	void move();

	// Set human's position
	void setPos(const float x, const float y);

	// Get human's position
	const sf::Vector2f getPos() const;

	// get human's size
	const sf::Vector2f getSize() const;

	// set human's origin
	void setOrigin(const float x, const float y);

	// Hit an object
	bool isHit(sf::Sprite obj);

	// hit the bound of the screen (not allowed human to go out)
	void updateCollision(sf::RenderTarget& target); 
	// call this function in game update(): this->human->updateCollision(*this->window);

	void update();
	void render(sf::RenderTarget& target);
};

