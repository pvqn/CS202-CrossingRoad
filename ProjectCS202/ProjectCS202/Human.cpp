#include "Human.h"

void Human::initTexture()
{
	// load from file
	if (this->texture.loadFromFile("icons resource/human.png") == false)
	{
		std::cout << "HUMAN CLASS::Failed to load texture from file\n";
	}
}

void Human::initSound()
{
	if (this->buffer.loadFromFile("Sound/hit.wav") == false)
	{
		std::cout << "HUMAN CLASS::Failed to load sound from file\n";
	}
	this->sound.setBuffer(this->buffer);
}

void Human::initSprite()
{
	this->sprite.setTexture(this->texture);

	// scale
	this->sprite.scale(1.5f, 1.5f);
}

Human::Human()
{
	this->speed = 7.f;

	this->initTexture();
	this->initSprite();
	this->initSound();
}

Human::~Human() {}

void Human::move()
{
	float dirX = 0.f, dirY = 0.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		dirX = -1.f, dirY = 0.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		dirX = 1.f, dirY = 0.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		dirX = 0.f, dirY = -1.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		dirX = 0.f, dirY = 1.f;

	this->sprite.move(this->speed * dirX, this->speed * dirY);
}

void Human::setPos(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

const sf::Vector2f Human::getPos() const
{
	return this->sprite.getPosition();
}

const sf::Vector2f Human::getSize() const
{
	const sf::Vector2f spriteSize(
		sprite.getTexture()->getSize().x * sprite.getScale().x,
		sprite.getTexture()->getSize().y * sprite.getScale().y);
	return spriteSize;
}

void Human::setOrigin(const float x, const float y)
{
	this->sprite.setOrigin(this->getSize().x * 0.5f, this->getSize().y * 0.5f);
}

bool Human::isHit(sf::Sprite obj)
{
	if (this->sprite.getGlobalBounds().intersects(obj.getGlobalBounds()))
	{
		this->playingSound();
		return true;
	}
	return false;
}

void Human::playingSound() { this->sound.play(); }

void Human::update() {}

void Human::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}

