#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
#include "Framework/Collision.h"

class Ball : public GameObject
{
public:
	Ball(sf::Vector2f pos, sf::Vector2f dir);
	Ball();
	void update(float dt);
	void collisionResponse();
	void setWindow(sf::RenderWindow* hndw) { window = hndw; };


private:
	sf::Texture ballTexture;

	sf::Vector2f direction;
	sf::Vector2f velocity;
	float speed;
	float acceleration;

	sf::RenderWindow* window;
};