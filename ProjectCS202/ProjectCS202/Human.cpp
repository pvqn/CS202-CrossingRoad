#include "Human.h"
void Human::initTexture()
{
	// load from file
	std::string load=std::string(RESOURCE_PATH) + "human.png";
	if (this->texture.loadFromFile(load) == false)
	{
		std::cout << "HUMAN CLASS::Failed to load texture from file\n";
	}
}

void Human::initSprite()
{
	this->sprite.setTexture(this->texture);

	// scale
	this->sprite.scale(0.7f, 0.7f);
}

Human::Human()
{
	this->speed = 4.f;

	this->initTexture();
	this->initSprite();

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

void Human::setOrigin(const float x, const float y) // pass 0.5f, 0.5f to set its origin to center
{
	this->sprite.setOrigin(this->getSize().x * x, this->getSize().y * y);
}

bool Human::isHit(sf::Sprite obj)
{
	if (this->sprite.getGlobalBounds().intersects(obj.getGlobalBounds()))
		return true;
	return false;
}

void Human::updateCollision(sf::RenderTarget& target)
{
	// left world collision
	if (this->sprite.getGlobalBounds().left < 0.f) 
		this->sprite.setPosition(0.f, this->sprite.getGlobalBounds().top);

	// right world collision
	else if(this->sprite.getGlobalBounds().left + this->sprite.getGlobalBounds().width >= target.getSize().x)
		this->sprite.setPosition(target.getSize().x - this->sprite.getGlobalBounds().width, 
								 this->sprite.getGlobalBounds().top);
	
	// top world collision
	if (this->sprite.getGlobalBounds().top < 0.f)
		this->sprite.setPosition(this->sprite.getGlobalBounds().left, 0.f);

	// bottom world collision
	else if (this->sprite.getGlobalBounds().top + this->sprite.getGlobalBounds().height >= target.getSize().y)
		this->sprite.setPosition(this->sprite.getGlobalBounds().left, 
								 target.getSize().y - this->sprite.getGlobalBounds().height);
}

void Human::update() {}

void Human::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}


