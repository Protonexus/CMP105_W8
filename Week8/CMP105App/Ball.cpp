#include "Ball.h"

Ball::Ball(sf::Vector2f pos, sf::Vector2f dir)
{
	ballTexture.loadFromFile("gfx/Beach_Ball.png");
	setSize(sf::Vector2f(16, 16));
	setPosition(pos.x, pos.y);
	direction = dir;
	
	setTexture(&ballTexture);

	speed = 10.f;
	acceleration = 0.f;

	setCollisionBox(pos.x, pos.y, getSize().x, getSize().y);
}

Ball::Ball()
{
	//Ball(sf::Vector2f(100.f,100.f), sf::Vector2f(0.f, 0.f));
	sf::Vector2f pos = sf::Vector2f(100.f,100.f);
	sf::Vector2f dir = sf::Vector2f(0.f, 0.f);
	ballTexture.loadFromFile("gfx/Beach_Ball.png");
	setSize(sf::Vector2f(16, 16));
	setPosition(pos.x, pos.y);
	direction = dir;

	setTexture(&ballTexture);

	speed = 10.f;
	acceleration = 0.f;

	setCollisionBox(pos.x, pos.y, getSize().x, getSize().y);
}

void Ball::update(float dt)
{
	velocity += (Vector::normalise(direction) *speed);
	move(velocity * dt);

	if ((getPosition().x + getSize().x >= window->getSize().x) | (getPosition().x <= 0.f))
	{
		direction.x = direction.x * -1;
	}

}

void Ball::collisionResponse()
{
	direction.x = direction.x * -1;
}
